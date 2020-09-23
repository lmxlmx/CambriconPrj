#include <assert.h>
#include <pthread.h>
#include "cnrt.h"
#include "video_encode_context.h"

int eventCallback(cncodecCbEventType eventType, void *pUserData, void *cbInfo) {
  if (eventType == CNCODEC_CB_EVENT_EOS) {
    videoEncodeContext *pContext = (videoEncodeContext *)pUserData;
    LOG_INFO("Capture EOS\n");
    // LOG_ERROR("sem_post eosSemaphore\n");
    sem_post(&(pContext->eosSemaphore));
    // LOG_ERROR("sem_post eosSemaphore end\n");
    return 0;
  } else if (eventType == CNCODEC_CB_EVENT_SW_RESET || eventType == CNCODEC_CB_EVENT_HW_RESET) {
    LOG_ERROR("System crash, eventType(%d)\n", eventType);
  } else if (eventType == CNCODEC_CB_EVENT_NEW_FRAME) {
    videoEncodeContext *pContext = (videoEncodeContext *)pUserData;
    if (pContext->chanConfig.isEnableDump) {
      // writeBitstreamToFile(pContext, (cnvideoEncOutput *)cbInfo);
      writeBitstreamToFileBymapping(pContext, (cnvideoEncOutput *)cbInfo);
    }
  } else if (eventType == CNCODEC_CB_EVENT_OUT_OF_MEMORY) {
    videoEncodeContext *pContext = (videoEncodeContext *)pUserData;
    sem_post(&(pContext->eosSemaphore));
    LOG_ERROR("decoder chan[#%d] out of memory, force stop\n", pContext->chanConfig.encodeChannelId);
    return 0;
  } else if (eventType == CNCODEC_CB_EVENT_ABORT_ERROR) {
    videoEncodeContext *pContext = (videoEncodeContext *)pUserData;
    sem_post(&(pContext->eosSemaphore));
    LOG_ERROR("decoder chan[#%d] occurs abort error, force stop\n", pContext->chanConfig.encodeChannelId);
    return 0;
  } else {
    LOG_INFO("unknown event(%d)\n", eventType);
  }

  return 0;
}

void *encodeProc(void *argv) {
  videoEncodeContext *pContext = (videoEncodeContext *)argv;
  int ret = 0;
  bool hasNext;

  /* Initialize encode context, including encode parameters preparation and input & output buffer allocation*/
  initEncodeContext(pContext);

  gettimeofday(&pContext->statistics.start, NULL);
  pContext->statistics.total_frame_count = 0;

  ret = cnvideoEncCreate(&pContext->handle, eventCallback, &pContext->createInfo);
  if (ret < 0) {
    LOG_ERROR("Call CN_Encode_Create failed, ret(%d)\n", ret);
    exit(0);
  }

  /**
   * Feed frame to encoder until eos(end of stream) is detected
   */
  hasNext = true;

  while (!pContext->eos) {
    /* Wait and get an available buffer */
    ret = cnvideoEncWaitAvailInputBuf(pContext->handle, &pContext->encInput.frame, -1);
    if (ret < 0) {
      LOG_ERROR("Call cnvideoEncWaitAvailInputBuf failed, ret(%d)\n", ret);
      exit(0);
    }

    /**
     * 1. Read a frame from input file and fill the available buffer
     * 2. Sync for device berfore feeding data using CNMedia interface
     */
    // readVideoFrame(pContext, &pContext->encInput.frame, &hasNext);
    readVideoFrameByMapping(pContext, &pContext->encInput.frame, &hasNext);

    // pContext->encInput.frame = &frame;
    pContext->encInput.pts = 0;

    if (!hasNext) {
      pContext->eos = true;
      pContext->encInput.flags |= CNVIDEOENC_FLAG_EOS;
    } else {
      pContext->encInput.flags &= (~CNVIDEOENC_FLAG_EOS);
    }

    /* Feed a frame to encode */
    ret = cnvideoEncFeedFrame(pContext->handle, &pContext->encInput, 5000);
    if (ret < 0) {
      LOG_ERROR("Call CN_Encode_Feed_Frame failed, ret(%d)\n", ret);
      exit(0);
    }
    pContext->statistics.total_frame_count++;
  }

  // LOG_ERROR("wait eosSemaphore\n");
  sem_wait(&(pContext->eosSemaphore));

  /* destory the encode*/
  ret = cnvideoEncDestroy(pContext->handle);
  if (ret < 0) {
    LOG_ERROR("Call CN_Encode_Destroy failed, ret(%d)\n", ret);
    exit(0);
  }

  gettimeofday(&pContext->statistics.end, NULL);
  pContext->statistics.total_time_cost = calculate_duraion_us(&pContext->statistics.start, &pContext->statistics.end);

  LOG_INFO("Encode end: total_frame_count(%u) total_time_cost(%u us)\n", pContext->statistics.total_frame_count,
           pContext->statistics.total_time_cost);

  /*deinit encode context, including release input and output buffer*/
  deinitEncodeContext(pContext);

  return NULL;
}

int main(int argc, char *argv[]) {
  int ret = 0;
  pthread_t encThread;

  videoEncodeContext *pContext = NULL;
  pContext = (videoEncodeContext *)malloc(sizeof(videoEncodeContext));
  memset((void *)pContext, 0, sizeof(videoEncodeContext));

  /* parse encode parameters from command line and store it in encode context */
  ret = encodeChanConfigParse(argc, argv, &pContext->chanConfig);
  if (ret < 0) {
    LOG_ERROR("parse encode parameter failed, ret(%d)\n", ret);
    exit(0);
  }

  pthread_create(&encThread, NULL, encodeProc, pContext);

  pthread_join(encThread, NULL);

  free(pContext);

  return 0;
}
