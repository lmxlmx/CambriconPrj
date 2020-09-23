#include <assert.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>
#include "video_decode_context.h"

static int sequenceCallback(void *pData, cnvideoDecSequenceInfo *pFormat) {
  int ret = 0;

  //    cnvideoDecCreateInfo decinfo;

  videoDecodeContext *pContext = (videoDecodeContext *)pData;
  pContext->seqinfo = *pFormat;

  updateDecodeContext(pContext);

  /*start decode*/
  ret = cnvideoDecStart(pContext->handle, &pContext->decInfo);
  if (ret < 0) {
    LOG_ERROR("Call cnvideoDecStart failed, ret(%d)\n", ret);
    return -1;
  }

  return 0;
}

static int newFrameCallback(void *pData, cnvideoDecOutput *pDecOuput) {
  static int num = 0;
  int ret = 0;

  videoDecodeContext *pContext = (videoDecodeContext *)pData;

  ret = cnvideoDecAddReference(pContext->handle, &pDecOuput->frame);
  if (ret < 0) {
    LOG_ERROR("Call cnvideoDecAddReference failed, ret(%d)\n", ret);
    return -1;
  }

  if (pContext->chanConfig.isEnableDump) {
    writeFrameToFile(pContext, &pDecOuput->frame);
  }

  // exception case, when is set to 1, not all buffers are released
  // this is used to test feeddata timeout and wait eos issue.
  if ((pContext->chanConfig.exceptionTestCode == 1) && (num++ % 4 == 0)) {
    LOG_ERROR("not releae ref buffer:%d\n", num);
    return 0;
  }

  ret = cnvideoDecReleaseReference(pContext->handle, &pDecOuput->frame);
  if (ret < 0) {
    LOG_ERROR("Call cnvideoDecReleaseReference failed, ret(%d)\n", ret);
    return -1;
  }

  return 0;
}

static int eosCallback(void *pData, void *pData1) {
  videoDecodeContext *pContext = (videoDecodeContext *)pData;
  sem_post(&(pContext->eosSemaphore));

  return 0;
}

static int outOfMemoryCallback(void *pData, void *pData1) {
  videoDecodeContext *pContext = (videoDecodeContext *)pData;
  sem_post(&(pContext->eosSemaphore));
  LOG_ERROR("decoder chan[#%d] out of memory, force stop\n", pContext->chanConfig.decodeChannelId);

  return 0;
}

static int abortErrorCallback(void *pData, void *pData1) {
  videoDecodeContext *pContext = (videoDecodeContext *)pData;
  sem_post(&(pContext->eosSemaphore));
  LOG_ERROR("decoder chan[#%d] occurs abort error, force stop\n", pContext->chanConfig.decodeChannelId);

  return 0;
}

int eventCallback(cncodecCbEventType EventType, void *pData, void *pdata1) {
  LOG_DEBUG("callback event type: %d \n", EventType);
  videoDecodeContext *pContext = (videoDecodeContext *)pData;

  switch (EventType) {
    case CNCODEC_CB_EVENT_NEW_FRAME:
      newFrameCallback(pData, pdata1);
      pContext->statistics.total_frame_count++;
      break;
    case CNCODEC_CB_EVENT_SEQUENCE:
      sequenceCallback(pData, pdata1);
      break;
    case CNCODEC_CB_EVENT_EOS:
      eosCallback(pData, pdata1);
      break;
    case CNCODEC_CB_EVENT_SW_RESET:
    case CNCODEC_CB_EVENT_HW_RESET:
      // todo....
      LOG_ERROR("Decode Firmware crash Event: %d \n", EventType);
      break;
    case CNCODEC_CB_EVENT_OUT_OF_MEMORY:
      outOfMemoryCallback(pData, pdata1);
      break;
    case CNCODEC_CB_EVENT_ABORT_ERROR:
      abortErrorCallback(pData, pdata1);
      break;
    default:
      LOG_ERROR("invalid Event: %d \n", EventType);
      break;
  }

  return 0;
}

static void *decodeProc(void *argv) {
  videoDecodeContext *pContext = (videoDecodeContext *)argv;
  cnvideoDecInput decinput;
  int length = 0;
  int ret = 0;
  struct timespec ts;

  gettimeofday(&pContext->statistics.start, NULL);
  pContext->statistics.total_frame_count = 0;

  // Initialize decode context, including preparing decode information
  // and allocating input and output buffer
  initDecodeContext(pContext);

  ret = cnvideoDecCreate(&pContext->handle, eventCallback, &pContext->decInfo);
  if (ret < 0) {
    LOG_ERROR("Call cnvideoDecCreate failed, ret(%d)\n", ret);
    goto deinit_context;
  }

  /**
   * Feed frame to decoder until eos(end of stream) is detected
   */
  pContext->bufInfo.bufAddr = (u8_t *)malloc(INPUT_BUFFER_SIZE_FOR_DECODE);
  pContext->bufInfo.bufRp = pContext->bufInfo.bufAddr;
  pContext->bufInfo.bufWp = pContext->bufInfo.bufAddr;
  pContext->needReadFileData = true;  // need read file to memory at the first time
  if (pContext->bufInfo.bufAddr == NULL) {
    LOG_ERROR("%s, fail to malloc buffer for decinput.streamBuf\n", __FUNCTION__);
    goto dec_destroy;
  }

  while (!pContext->eos) {
    memset(&decinput, 0, sizeof(cnvideoDecInput));
    decinput.streamBuf = pContext->bufInfo.bufAddr;

    ret = readInputStreamData(pContext, &decinput, INPUT_BUFFER_SIZE_FOR_DECODE);
    if (ret < 0) {
      LOG_ERROR("readInputStreamData failed, ret(%d)\n", ret);
      continue;
    }
    // TODO check result
    if (pContext->chanConfig.readMode == DEC_NALU) {
      struct timeval curTime;
      gettimeofday(&curTime, NULL);
      decinput.pts = curTime.tv_sec * 1000000 + curTime.tv_usec;
      decinput.flags |= CNVIDEODEC_FLAG_TIMESTAMP;
    }

    ret = cnvideoDecFeedData(pContext->handle, &decinput, 10000);
    if (ret == -CNCODEC_TIMEOUT) {
      LOG_ERROR("cnvideoDecFeedData timeout happened\n");
      cnvideoDecAbort(pContext->handle);
      goto deinit_context;
    } else if (ret < 0) {
      LOG_ERROR("Call CN_Decode_FeedData failed, ret(%d)\n", ret);
      if (pContext->bufInfo.bufAddr != NULL) {
        free(pContext->bufInfo.bufAddr);
      }
      goto dec_stop;
    }
  }

  free(pContext->bufInfo.bufAddr);

  clock_gettime(CLOCK_REALTIME, &ts);
  ts.tv_sec += 10;
  if (sem_timedwait(&(pContext->eosSemaphore), &ts) == -1) {
    if (errno == ETIMEDOUT) {
      LOG_ERROR("sem_timedwait timeout happened\n");
      cnvideoDecAbort(pContext->handle);
      goto deinit_context;
    }
  }

  // sem_wait(&(pContext->eosSemaphore));

  gettimeofday(&pContext->statistics.end, NULL);
  pContext->statistics.total_time_cost = calculate_duraion_us(&pContext->statistics.start, &pContext->statistics.end);

  LOG_INFO("decode end: read file time(%u) total_time_cost(%u us)\n", pContext->statistics.total_frame_count,
           pContext->statistics.total_time_cost);

dec_stop:
  ret = cnvideoDecStop(pContext->handle);
  if (ret == -CNCODEC_TIMEOUT) {
    LOG_ERROR("cnvideoDecStop timeout happened\n");
    cnvideoDecAbort(pContext->handle);
    goto deinit_context;
  } else if (ret < 0) {
    LOG_ERROR("Call CN_Decode_Stop failed, ret(%d)\n", ret);
  }

dec_destroy:
  ret = cnvideoDecDestroy(pContext->handle);
  if (ret < 0) {
    LOG_ERROR("Call CN_Decode_Destroy failed, ret(%d)\n", ret);
  }

deinit_context:
  /*deinit encode context, including release input and output buffer*/
  deinitDecodeContext(pContext);

  return NULL;
}

int main(int argc, char *argv[]) {
  int ret = 0;
  pthread_t decThread;
  videoDecodeContext *pContext;

  pContext = (videoDecodeContext *)malloc(sizeof(videoDecodeContext));
  if (pContext == NULL) {
    LOG_ERROR("malloc pContext failed\n");
    return -1;
  }

  memset(pContext, 0, sizeof(videoDecodeContext));

  /* parse encode parameters from command line and store it in encode context */
  ret = decodeChanConfigParse(argc, argv, &pContext->chanConfig);
  if (ret < 0) {
    LOG_ERROR("parse encode parameter failed, ret(%d)\n", ret);
    free(pContext);
    return ret;
  }

  pthread_create(&decThread, NULL, decodeProc, pContext);

  pthread_join(decThread, NULL);

  free(pContext);

  return 0;
}
