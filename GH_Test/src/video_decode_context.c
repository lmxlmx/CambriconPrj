#include "video_decode_context.h"
#include "cn_codec_memory.h"
#include "cnrt.h"

#define NaluHeaderSizeIsThree 3
#define NaluHeaderSizeIsFour 4

#define IS_NALU_START_CODE1(x) ((*(int *)(x)&0x00ffffff) == 0x00010000)
#define IS_NALU_START_CODE(x) (*(int *)(x) == 0x01000000)

typedef enum {
  H264_NALU_TYPE_SLICE = 1,
  H264_NALU_TYPE_DPA = 2,
  H264_NALU_TYPE_DPB,
  H264_NALU_TYPE_DPC,
  H264_NALU_TYPE_IDR,
  H264_NALU_TYPE_SEI,
  H264_NALU_TYPE_SPS,
  H264_NALU_TYPE_PPS,
  H264_NALU_TYPE_AUD,
  H264_NALU_TYPE_EOSEQ,
  H264_NALU_TYPE_EOSTREAM,
  H264_NALU_TYPE_FILL,
  H264_NALU_TYPE_MAX,
} cncodecH264NaluType;

typedef enum {
  H265_NALU_TYPE_VPS = 32,
  H265_NALU_TYPE_SPS = 33,
  H265_NALU_TYPE_PPS = 34,
  H265_NALU_TYPE_AUD = 35,
  H265_NALU_TYPE_EOSEQ = 36,
  H265_NALU_TYPE_MAX,
} cncodecH265NaluType;

void usage(void) {
  LOG_ERROR("usage: decode_demo [decode options]\n\n");
  LOG_ERROR("options: \n");

  LOG_INFO("  -d | --decode-id  <decoder id>  selece video decode hw instance (0 ~5), default 0\n");
  LOG_INFO("  -c | --codec  <codec type>      input stream codec type: H264 | H265 \n");
  LOG_INFO("  -f | --surface-format <surface format>    decode output surface format:\n");
  LOG_INFO("                                            NV12(default) | NV21 | I420 | YUYV | UYVY | P010\n");
  LOG_INFO("  --height                        output frame height, default 0 means equaling source stream height\n");
  LOG_INFO("  --width                         output frame width, default 0 means equaling source stream width\n");
  LOG_INFO("  -i | --input <file name > source stream file name for decode\n");
  LOG_INFO("  --output-file <file name >      enable output dump\n");
  LOG_INFO("  --feed  <mode>                  set feed mode for input stream:\n");

  LOG_INFO("  --force-eos-null-frame          test force send eos in a null frame after last decode stream data\n");
  LOG_INFO(
      "  --app-frame-buffer              app allocate frame buffer and config buffer to decode for frame output "
      "purpose \n");
  LOG_INFO(
      "  --test-round                    total test round, default 1, if stress tes case, test-round is ignored\n");
  LOG_INFO("  --stress-test                   endless stress test, default false\n");
  LOG_INFO("  --exception                     exception test case\n");
  LOG_INFO("                                  1 : not all output buffer are released to codec\n\n");

  LOG_INFO("  -h | --help                     print above help message\n\n");

  LOG_ERROR("examples:\n");
  LOG_ERROR("example #1 decode input0.h264 to NV12 with output file\n");
  LOG_INFO("decode_demo -c H264 -d 0 --input-stream input0.h264 --output-file out.yuv --app-frame-buffer\n");
  LOG_ERROR("example #2 decode input0.h264 to NV12 without output file\n");
  LOG_INFO("decode_demo -c H264 -d 0 --input-stream input0.h264 --app-frame-buffer\n");
}

static bool IsAuxNaluType(cncodecType codec, char data) {
  if (codec == CNCODEC_H264) {
    cncodecH265NaluType nalu_type = (data & 0x1f);

    if ((nalu_type == H264_NALU_TYPE_SEI) || (nalu_type == H264_NALU_TYPE_SPS) || (nalu_type == H264_NALU_TYPE_PPS) ||
        (nalu_type == H264_NALU_TYPE_AUD)) {
      return true;
    }
  } else if (codec == CNCODEC_HEVC) {
    cncodecH265NaluType nalu_type = (data & 0x7E) >> 1;

    if ((nalu_type == H265_NALU_TYPE_PPS) || (nalu_type == H265_NALU_TYPE_VPS) || (nalu_type == H265_NALU_TYPE_SPS) ||
        (nalu_type == H265_NALU_TYPE_AUD)) {
      return true;
    }
  } else {
    return false;
  }

  return false;
}

bool decodeChanConfigParse(int argc, char *argv[], videoDecodeChannelConfig *pConfig) {
  int opt;
  int opt_idx;
  int i;

  const char *const short_opt = "d:c:f:i:";
  const struct option long_opt[] = {
      {"decoder-id", required_argument, NULL, 'd'},     {"codec", required_argument, NULL, 'c'},
      {"surface-format", required_argument, NULL, 'f'}, {"input-stream", required_argument, NULL, 'i'},
      {"output-file", required_argument, NULL, 'o'},    {"stress-test", no_argument, NULL, 'x'},
      {"force-eos-null-frame", no_argument, NULL, 'n'}, {"app-frame-buffer", no_argument, NULL, 'p'},
      {"height", required_argument, NULL, 'g'},         {"feed", required_argument, NULL, 'e'},
      {"width", required_argument, NULL, 'w'},          {"stress", no_argument, NULL, 't'},
      {"exception", required_argument, NULL, 'u'},      {0, 0, 0, 0},
  };

  optind = 1;  // re-init linux global opt indx as multiple cli parse is required

  if (argc < 2) {
    usage();
    exit(0);
  }

  for (i = 1; i < argc; ++i) {
    if ((strcmp(argv[i], "--help") == 0) || (strcmp(argv[i], "-h") == 0)) {
      usage();
      exit(0);
    }
  }

  /*init some default vaule*/
  pConfig->decodeChannelId = 0;
  pConfig->codec = CNCODEC_H264;
  pConfig->isAppAllocBuf = false;
  pConfig->readMode = DEC_CHUNK;
  pConfig->isEnableDump = false;

  while ((opt = getopt_long(argc, argv, short_opt, long_opt, &opt_idx)) != -1) {
    switch (opt) {
      case 'd':
        pConfig->decodeChannelId = (cnvideoDecInstance)atoi(optarg);
        break;

      case 'c':
        pConfig->codec = parseCodecType(optarg);
        break;

      case 'f':
        pConfig->pixFmt = ParsePixelFormat(optarg);
        break;

      case 'i':
        memcpy(pConfig->inputFileName, optarg, 256);
        break;

      case 'o':
        memcpy(pConfig->outputFileName, optarg, 256);
        pConfig->isEnableDump = true;
        break;

      case 'e':
        pConfig->readMode = string2ReadMode(optarg);
        break;

      case 's':
        pConfig->interlaced = true;
        break;

      case 'n':
        pConfig->isForceSendEosInNullFrame = true;
        break;

      case 'p':
        pConfig->isAppAllocBuf = true;
        break;

      case 'g':
        pConfig->outputHeight = atoi(optarg);
        break;

      case 'w':
        pConfig->outputWidth = atoi(optarg);
        break;

      case 'u':
        pConfig->exceptionTestCode = (videoDecodeExceptionCode)atoi(optarg);
        break;

      default:
        break;
    }
  }

  printDecConfig(pConfig);

  return false;
}

void printDecConfig(videoDecodeChannelConfig *pConfig) {
  LOG_INFO("[in] codec(%s) instance_id(%d) strm_read_mode(%d) \n\n", codecStrs[pConfig->codec],
           pConfig->decodeInstanceId, pConfig->readMode);

  LOG_INFO("[out] planar_format(%s) out solution(w %d h %d)\n\n", surfaceFmtStrs[pConfig->pixFmt], pConfig->outputWidth,
           pConfig->outputHeight);

  LOG_INFO("[in] file name:(%s)\n", pConfig->inputFileName);

  if (pConfig->isEnableDump)
    LOG_INFO("[out]file name:(%s)\n\n", pConfig->outputFileName);
  else
    LOG_INFO("[out] no output\n");
}

cnrtChannelType_t getBestChannelForDecoder(int instanceId) {
  if (instanceId == 0) return CNRT_CHANNEL_TYPE_0;

  if (instanceId == 1 || instanceId == 2) return CNRT_CHANNEL_TYPE_1;

  if (instanceId == 3 || instanceId == 4) return CNRT_CHANNEL_TYPE_2;

  if (instanceId == 5) return CNRT_CHANNEL_TYPE_3;

  return CNRT_CHANNEL_TYPE_1;
}

static int cnrtContextInit(int deviceId, cnrtChannelType_t channelId) {
  unsigned int dev_num;
  cnrtDev_t dev;
  cnrtRet_t rtRet;

  rtRet = cnrtInit(0);
  CNRT_ERROR_CHECK(rtRet);

  cnrtGetDeviceCount(&dev_num);
  if (dev_num == 0) {
    LOG_ERROR("cnrtGetDeviceCount return 0 \n");
    return -1;
  }

  rtRet = cnrtGetDeviceHandle(&dev, deviceId);
  CNRT_ERROR_CHECK(rtRet);

  rtRet = cnrtSetCurrentDevice(dev);
  CNRT_ERROR_CHECK(rtRet);

  rtRet = cnrtSetCurrentChannel(channelId);
  CNRT_ERROR_CHECK(rtRet);

  return 0;
}

static int allocateDecodeInputBuffer(videoDecodeContext *pContext) {
  unsigned int i = 0;
  cnrtRet_t rtRet;

  for (i = 0; i < pContext->decInfo.inputBufNum; ++i) {
    pContext->decInfo.inputBuf[i].addr = 0;
    rtRet = cnrtMallocFrameBuffer((void **)&pContext->decInfo.inputBuf[i].addr, INPUT_BUFFER_SIZE_FOR_DECODE);
    if (rtRet != CNRT_RET_SUCCESS) {
      LOG_ERROR("cnrtMallocFrameBuffer failed\n");
      goto ALLOC_ERR;
    }

    pContext->decInfo.inputBuf[i].size = INPUT_BUFFER_SIZE_FOR_DECODE;
  }

  return 0;

ALLOC_ERR:
  for (i = 0; i < pContext->decInfo.inputBufNum; ++i) {
    if (pContext->decInfo.inputBuf[i].addr != 0) {
      cnrtFree((void *)pContext->decInfo.inputBuf[i].addr);
    }
  }

  return -1;
}

static int allocateDecodeOutputBuffer(videoDecodeContext *pContext) {
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int size;
  uint32_t planesNum;
  cnrtRet_t rtRet;

  planesNum = get_planes_num(pContext->chanConfig.pixFmt);

  for (i = 0; i < pContext->decInfo.outputBufNum; ++i) {
    pContext->decInfo.outputBuf[i].width = pContext->decInfo.width;
    pContext->decInfo.outputBuf[i].height = pContext->decInfo.height;
    pContext->decInfo.outputBuf[i].planeNum = planesNum;
    pContext->decInfo.outputBuf[i].pixelFmt = pContext->chanConfig.pixFmt;
    for (j = 0; j < planesNum; ++j) {
      unsigned int planeW = calc_plane_width(pContext->chanConfig.pixFmt, pContext->decInfo.width, j);

      // allign to 128 byte is request of scaler process!!!
      // if does not send dec output to cnscaler, allign to 64/128/256 is allowed.
      unsigned int stride = ALIGN128(planeW);
      if (pContext->chanConfig.pixFmt == CNCODEC_PIX_FMT_I420 && j == 0) {
        stride = ALIGN256(planeW);  // Y should align to 256 byte for I420 is also the request of scaler
      }

      size = stride * calc_plane_height(pContext->chanConfig.pixFmt, pContext->decInfo.height, j);

      pContext->decInfo.outputBuf[i].plane[j].addr = 0;
      rtRet = cnrtMallocFrameBuffer((void **)(&pContext->decInfo.outputBuf[i].plane[j].addr), size);
      if (rtRet != CNRT_RET_SUCCESS) {
        LOG_ERROR("cnrtMallocFrameBuffer failed\n");
        goto ALLOC_ERR;
      }

      pContext->decInfo.outputBuf[i].plane[j].size = size;
      pContext->decInfo.outputBuf[i].stride[j] = stride;
    }
  }

  return 0;

ALLOC_ERR:
  /*free source*/
  for (i = 0; i < pContext->decInfo.outputBufNum; ++i) {
    for (j = 0; j < planesNum; ++j) {
      if (pContext->decInfo.outputBuf[i].plane[j].addr != 0) {
        cnrtFree((void *)pContext->decInfo.outputBuf[i].plane[j].addr);
      }
    }
  }

  return -1;
}

int allocateDecodeBuffer(videoDecodeContext *pContext) {
  int ret = 0;
  ret = allocateDecodeInputBuffer(pContext);
  if (ret < 0) {
    exit(0);
  }

  ret = allocateDecodeOutputBuffer(pContext);
  if (ret < 0) {
    exit(0);
  }

  return 0;
}

static int releaseDecodeInputBuffer(videoDecodeContext *pContext) {
  unsigned int i = 0;

  for (i = 0; i < pContext->decInfo.inputBufNum; ++i) {
    cnrtFree((void *)pContext->decInfo.inputBuf[i].addr);
  }

  return 0;
}

static int releaseDecodeOutputBuffer(videoDecodeContext *pContext) {
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int planesNum;

  planesNum = get_planes_num(pContext->chanConfig.pixFmt);

  for (i = 0; i < pContext->decInfo.outputBufNum; ++i) {
    for (j = 0; j < planesNum; ++j) {
      cnrtFree((void *)pContext->decInfo.outputBuf[i].plane[j].addr);
    }
  }

  return 0;
}

int releaseDecodeBuffer(videoDecodeContext *pContext) {
  releaseDecodeInputBuffer(pContext);
  releaseDecodeOutputBuffer(pContext);

  return 0;
}

int updateDecodeContext(videoDecodeContext *pContext) {
  cnrtContextInit(0, getBestChannelForDecoder(pContext->chanConfig.decodeChannelId));

  /*release output buffer*/
  if (pContext->decInfo.allocType == CNCODEC_BUF_ALLOC_APP) {
    free(pContext->decInfo.outputBuf);
    releaseDecodeOutputBuffer(pContext);
  }

  /*update decode info*/
  pContext->decInfo.codec = pContext->seqinfo.codec;
  pContext->decInfo.height = pContext->seqinfo.height;
  pContext->decInfo.width = pContext->seqinfo.width;
  pContext->decInfo.inputBufNum = pContext->seqinfo.minInputBufNum;
  pContext->decInfo.outputBufNum = pContext->seqinfo.minOutputBufNum > pContext->decInfo.outputBufNum
                                       ? pContext->seqinfo.minOutputBufNum
                                       : pContext->decInfo.outputBufNum;
  pContext->decInfo.userContext = (void *)pContext;

  /*re-allocate output(capture) buffer*/
  if (pContext->decInfo.allocType == CNCODEC_BUF_ALLOC_APP) {
    pContext->decInfo.outputBuf = (cncodecFrame *)malloc(pContext->decInfo.outputBufNum * sizeof(cncodecFrame));
    allocateDecodeOutputBuffer(pContext);
  }

  return 0;
}

int initDecodeContext(videoDecodeContext *pContext) {
  memset(&pContext->decInfo, 0, sizeof(pContext->decInfo));

  pContext->decInfo.codec = pContext->chanConfig.codec;
  pContext->decInfo.width = pContext->chanConfig.outputWidth > 0 ? pContext->chanConfig.outputWidth : 1920;
  pContext->decInfo.height = pContext->chanConfig.outputHeight > 0 ? pContext->chanConfig.outputHeight : 1080;
  pContext->decInfo.inputBufNum = 5;   // default setting
  pContext->decInfo.outputBufNum = 5;  // default setting
  pContext->decInfo.pixelFmt = pContext->chanConfig.pixFmt;
  pContext->decInfo.progressive = (pContext->chanConfig.interlaced == 0 ? 1 : 0);
  pContext->decInfo.userContext = (void *)pContext;
  pContext->decInfo.instance = pContext->chanConfig.decodeInstanceId;
  pContext->decInfo.allocType = pContext->chanConfig.isAppAllocBuf ? CNCODEC_BUF_ALLOC_APP : CNCODEC_BUF_ALLOC_LIB;

  /* allocate input and output buffer */
  if (pContext->decInfo.allocType == CNCODEC_BUF_ALLOC_APP) {
    pContext->decInfo.inputBuf = (cncodecDevMemory *)malloc(pContext->decInfo.inputBufNum * sizeof(cncodecDevMemory));
    pContext->decInfo.outputBuf = (cncodecFrame *)malloc(pContext->decInfo.outputBufNum * sizeof(cncodecFrame));
    pContext->outputBufMap = (frameCpuAddr *)malloc(pContext->decInfo.outputBufNum * sizeof(frameCpuAddr));
    pContext->inputBufMap = (uint64_t *)malloc(pContext->decInfo.inputBufNum * sizeof(uint64_t));

    cnrtContextInit(0, getBestChannelForDecoder(pContext->chanConfig.decodeChannelId));
    allocateDecodeBuffer(pContext);
  }

  pContext->inFile = fopen(pContext->chanConfig.inputFileName, "rb");
  if (!pContext->inFile) {
    LOG_ERROR("open input file failed\n");
    return -1;
  }

  if (pContext->chanConfig.isEnableDump) {
    pContext->outFile = fopen(pContext->chanConfig.outputFileName, "wb");
    if (!pContext->outFile) {
      fclose(pContext->inFile);
      LOG_ERROR("open input or output file failed\n");
      return -1;
    }
  }

  pContext->eos = false;
  sem_init(&(pContext->eosSemaphore), 0, 0);

  return 0;
}

int deinitDecodeContext(videoDecodeContext *pContext) {
  if (pContext->decInfo.allocType == CNCODEC_BUF_ALLOC_APP) {
    releaseDecodeBuffer(pContext);
    free(pContext->decInfo.inputBuf);
    free(pContext->decInfo.outputBuf);
    free(pContext->inputBufMap);
    free(pContext->outputBufMap);

    pContext->decInfo.inputBuf = NULL;
    pContext->decInfo.outputBuf = NULL;
    pContext->inputBufMap = NULL;
    pContext->outputBufMap = NULL;
  }

  fclose(pContext->inFile);
  pContext->inFile = NULL;

  if (pContext->chanConfig.isEnableDump) {
    fclose(pContext->outFile);
    pContext->outFile = NULL;
  }

  sem_destroy(&(pContext->eosSemaphore));

  return 0;
}

int readChunk(videoDecodeContext *pContext, cnvideoDecInput *pDecInput) {
  pDecInput->streamBuf = pContext->bufInfo.bufRp;
  pDecInput->streamLength = pContext->bufInfo.bufWp - pContext->bufInfo.bufRp;
  if (feof(pContext->inFile)) {
    pContext->eos = true;
    pDecInput->flags |= CNVIDEODEC_FLAG_EOS;
  }

  pContext->bufInfo.bufRp = pContext->bufInfo.bufWp;
  pContext->needReadFileData = true;
  return pDecInput->streamLength;
}

int readNalu(videoDecodeContext *pContext, cnvideoDecInput *pDecInput) {
  uint8_t *rp = pContext->bufInfo.bufRp;
  bool firstNaluFound = false;
  bool is_vcl_data = false;

  while ((rp + NaluHeaderSizeIsFour) <= pContext->bufInfo.bufWp) {
    if (IS_NALU_START_CODE(rp) || IS_NALU_START_CODE1(rp)) {
      u32_t off = IS_NALU_START_CODE(rp) ? NaluHeaderSizeIsFour : NaluHeaderSizeIsThree;

      if ((rp + off == pContext->bufInfo.bufWp) ||
          ((rp + off < pContext->bufInfo.bufWp) && !IsAuxNaluType(pContext->chanConfig.codec, (char)(*(rp + off))))) {
        is_vcl_data = true;
      }

      if (!firstNaluFound) {
        pDecInput->streamBuf = rp;
        firstNaluFound = true;
        LOG_DEBUG("First Nalu Found\n");

        if (IS_NALU_START_CODE(rp)) {
          rp += NaluHeaderSizeIsFour;
        } else {
          rp += NaluHeaderSizeIsThree;
        }
      } else {
        if (is_vcl_data) {
          pDecInput->streamLength = rp - pDecInput->streamBuf;
          // data.end_addr_plus1 = rp;
          pContext->bufInfo.bufRp = rp;
          if ((pContext->bufInfo.bufRp >= pContext->bufInfo.bufWp) && feof(pContext->inFile)) {
            pContext->eos = true;
            pDecInput->flags |= CNVIDEODEC_FLAG_EOS;
            LOG_INFO("EOS found when data in buffer is exhaust\n");
          }
          LOG_DEBUG("Nalu complete streamLength:%d bufRp:%p bufWp:%p\n", pDecInput->streamLength,
                    pContext->bufInfo.bufRp, pContext->bufInfo.bufWp);
          return pDecInput->streamLength;
        } else {
          rp++;
        }
      }
    } else {
      rp++;
    }
  }
  if (pContext->eos) {
    pDecInput->flags |= CNVIDEODEC_FLAG_EOS;
    LOG_INFO("EOS Found\n");
  }
  LOG_DEBUG("Need Read Data From File [rp:%p  wp:%p]\n", pContext->bufInfo.bufRp, pContext->bufInfo.bufWp);
  pContext->needReadFileData = true;

  return pDecInput->streamLength;
}

void readFileToBuffer(videoDecodeContext *pContext, int size) {
  int result = 0;
  size_t realReadCnt = 0;

  if (feof(pContext->inFile)) {
    LOG_INFO("EOS found when reading file\n");
    pContext->eos = true;
    return;
  }

  if ((pContext->bufInfo.bufRp < pContext->bufInfo.bufWp) && (pContext->inFile != NULL)) {
    long lastRemainSize = pContext->bufInfo.bufWp - pContext->bufInfo.bufRp;
    result = fseek(pContext->inFile, -lastRemainSize, SEEK_CUR);
    if (result != 0) {
      LOG_ERROR("file seek size %ld fail\n", lastRemainSize);
      // return result;
    }
    LOG_DEBUG("File seek size %ld success\n", lastRemainSize);
  }

  pContext->bufInfo.bufWp = pContext->bufInfo.bufAddr;
  pContext->bufInfo.bufRp = pContext->bufInfo.bufWp;

  realReadCnt = fread(pContext->bufInfo.bufAddr, sizeof(char), size, pContext->inFile);
  if (realReadCnt == 0) {
    LOG_INFO("EOS found because read no data\n");
    pContext->eos = true;
  }
  pContext->bufInfo.bufWp += realReadCnt;
  LOG_DEBUG("File Read size %d(Expect:%d), eof(%d)\n", (int)(realReadCnt), size, pContext->eos);
  if (pContext->bufInfo.bufWp > pContext->bufInfo.bufRp) {
    pContext->needReadFileData = false;
  }
}

int readBufData(videoDecodeContext *pContext, cnvideoDecInput *pDecInput, DecodeFileReadMode readMode) {
  if (readMode == DEC_CHUNK) {
    return readChunk(pContext, pDecInput);
  } else if (readMode == DEC_NALU) {
    return readNalu(pContext, pDecInput);
  }

  return -1;
}

int readInputStreamData(videoDecodeContext *pContext, cnvideoDecInput *pDecInput, int size) {
  int length = 0;
  while (!pContext->eos) {
    if (pContext->needReadFileData) {
      readFileToBuffer(pContext, size);
      if (pContext->eos) {
        // pDecInput->flags |= CNVIDEODEC_FLAG_EOS;
        length = readBufData(pContext, pDecInput, DEC_CHUNK);  // Use CHUNK Mode To Feed The Last Frame
        if (length != 0) {
          LOG_INFO("Send the last frame\n");
        } else {
          LOG_INFO("Send EOS with no data\n");
        }
        break;
      }
    } else {
      length = readBufData(pContext, pDecInput, pContext->chanConfig.readMode);
      if ((length == 0) && (pContext->needReadFileData)) {
        continue;
      }

      break;
    }
  }
  return 0;
}

void dumpSurfaceData(FILE *file, cncodecFrame *frame) {
  unsigned int i;
  unsigned int j;
  unsigned int planW;
  unsigned int planLen;
  unsigned int planeH;
  cnrtRet_t rtRet;

  for (i = 0; i < frame->planeNum; ++i) {
    planW = calc_plane_width(frame->pixelFmt, frame->width, i);
    planLen = calc_plane_length(frame->pixelFmt, frame->stride[i], frame->height, i);
    planeH = calc_plane_height(frame->pixelFmt, frame->height, i);

    if (frame->stride[i] == planW) {
      // LOG_INFO("frame->stride[i] %u planw %u\n", frame->stride[i], planW);
      void *cpuAddr;
      rtRet = cncodecMap(&cpuAddr, frame->plane[i].addr, frame->plane[i].size);
      if (rtRet != CNRT_RET_SUCCESS) {
        LOG_ERROR("call cncodecMap faild\n");
        return;
      }

      rtRet = cncodecInvalidateCache(cpuAddr, frame->plane[i].size);
      if (rtRet != CNRT_RET_SUCCESS) {
        LOG_ERROR("call cncodecInvalidateCache faild\n");
        return;
      }

      fwrite(cpuAddr, sizeof(char), planLen, file);

      rtRet = cncodecUnmap(cpuAddr, frame->plane[i].size);
      if (rtRet != CNRT_RET_SUCCESS) {
        LOG_ERROR("call cncodecUnmap faild\n");
        return;
      }
    } else {
      void *tmp_buffer1 = malloc(planLen);
      char *tmp_buffer2 = (char *)malloc(planW * planeH);

      cnrtMemcpy(tmp_buffer1, (void *)frame->plane[i].addr, planLen, CNRT_MEM_TRANS_DIR_DEV2HOST);

      for (j = 0; j < planeH; ++j) {
        memcpy(tmp_buffer2 + j * planW, tmp_buffer1 + j * frame->stride[i], planW);
      }

      fwrite(tmp_buffer2, sizeof(char), planW * planeH, file);

      free(tmp_buffer1);
      free(tmp_buffer2);
    }
  }
}

/*
void dumpSurfaceData(FILE *file, cncodecFrame *frame)
{
    unsigned int i;
    unsigned int j;
    unsigned int planW;
    unsigned int planLen;
    unsigned int planeH;
    void *addr;

    for (i = 0; i < frame->planeNum; ++i)
    {
        planW   = calc_plane_width(frame->pixelFmt, frame->width, i);
        planLen = calc_plane_length(frame->pixelFmt, frame->stride[i], frame->height, i);

        addr = malloc(planLen);
        cnrtMemcpy(addr, (void *)frame->plane[i].addr, planLen, CNRT_MEM_TRANS_DIR_DEV2HOST);

        if (frame->stride[i] == planW)
        {
            fwrite(addr, sizeof(char), planLen, file);
        }
        else
        {
            planeH = calc_plane_height(frame->pixelFmt, frame->height, i);

            char *tmpBuffer = (char *)malloc(planW * planeH);

            for (j = 0; j < planeH; ++j)
            {
                memcpy(tmpBuffer + j * planW, addr + j * frame->stride[i], planW);
            }

            fwrite(tmpBuffer, sizeof(char), planW * planeH, file);
            free(tmpBuffer);
        }

        free(addr);
    }
}
*/

int writeFrameToFile(videoDecodeContext *pContext, cncodecFrame *frame) {
  cnrtContextInit(0, getBestChannelForDecoder(pContext->chanConfig.decodeChannelId));

  dumpSurfaceData(pContext->outFile, frame);

  return 0;
}
