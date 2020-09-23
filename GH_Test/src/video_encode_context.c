#include "video_encode_context.h"
#include "cn_codec_memory.h"
#include "cnrt.h"

void usage(void) {
  LOG_ERROR("usage: encode_demo [encode options]\n\n");
  LOG_ERROR("options: \n");

  LOG_ERROR("encode options (common): \n");
  LOG_INFO("  --height <vertical pix num>     picture frame height, default 1080\n");
  LOG_INFO("  --width  <horizontal pix num>   picture frame width, default 1920\n");
  LOG_INFO("  -e | --encode-id  <encoder id>  selece video encode hw instance (0 ~1), default 0\n");
  LOG_INFO("  -c | --codec  <codec type>      output stream codec type: H264(default) | H265 | JPEG\n");
  LOG_INFO("  -f | --surface-format <surface format>   input surface format:\n");
  LOG_INFO("                                           NV12(default) | NV21 | I420 | YUYV | UYVY | P010\n");
  LOG_INFO("  -i | --input <file name>  source picture file name for encode\n");
  LOG_INFO("  --app-frame-buffer              app allocate frame buffer and config buffer to encode for yuv input\n");
  LOG_INFO("  --output-file <file name>       enable output dump\n\n");
  LOG_INFO("  --stress                        endless stress test, default false\n");

  LOG_ERROR("encode options (for H264/H265): \n");
  LOG_INFO("  -p | --profile <H264/H265 profile>  h264: Baseline(default)/Main/High/High_10\n");
  LOG_INFO("                                      h265: Main(default)/Still/Intra/Main_10\n");
  LOG_INFO("  -l | --level <H264/H265 level>      H264: 4(default)/41/50/51\n");
  LOG_INFO("                                      H265: Main_4(default)/Main_41/Main_50/Main_51\n");
  LOG_INFO("  --fps <frame rate per second>       set encoded stream FPS, default 30fps\n");
  LOG_INFO("  -b | --bitrate <target birate>      default 0, target bitrate for encoder reference\n\n");

  LOG_INFO("  --gop-len             config gop length in gop default 0 \n");
  LOG_INFO("  --b-frame             config b frame number in gop when profile is above main, default 0 \n");
  LOG_INFO("  --h-range             config horizontal search range for calculating motion vector, default 128 \n");
  LOG_INFO("  --v-range             config horizontal search range for calculating motion vector, default 64 \n");
  LOG_INFO("  --i-qp                config fixed QP for I frame, default 0\n");
  LOG_INFO("  --p-qp                config fixed QP for P frame, default 0\n");
  LOG_INFO("  --b-qp                config fixed QP for B frame, default 0\n");
  LOG_INFO("  --max-qp              config max QP for I,P,B frame, valid only when bitrate is set, default 51\n");
  LOG_INFO("  --min-qp              config min QP for I,P,B frame, valid only when bitrate is set, default 0\n");
  LOG_INFO("  --ir-count            config intra MB refresh, default 0\n");
  LOG_INFO("  --slice-max-mb        config slice max MB count, default 0\n");
  LOG_INFO("  --entropy-mode        config entropy mode for H264, 0:CAVLC, 1:CABAC, default CAVLC\n");
  LOG_INFO("  --cabac               config H264 to use CABAC, default using CAVLC for H264\n");
  LOG_INFO("  --cabac-init          config init table for CABAC, 0,1,2 for H264 and 0,1 for HEVC, default 0\n");

  LOG_INFO("  -h | --help                          print above help message\n\n");

  LOG_ERROR("example:\n");

  LOG_ERROR("example#1 :encode input0.nv12 to h264 and dump output\n");
  LOG_INFO(
      "./encode_demo -e 0 -c H264 --input-stream input0.nv12  -f NV12 --width 1920 --height 1080 --output-file "
      "out.h264 --app-frame-buffer\n");

  LOG_ERROR("example#2 :encode input0.nv12 to h264(Main)\n");
  LOG_ERROR("           with setting minQP = 0 maxQP = 40 gop_length = 10 b_frame_num = 2\n");
  LOG_INFO(
      "./encode_demo -e 0 -c H264 --input-stream input0.nv12  -f NV12 --width 1920 --height 1080 --output-file "
      "out.h264 --app-frame-buffer\n");
  LOG_INFO(" --min-qp 0 --max-qp 40 --gop-len 10 --b-frame 2 -b 2000000 --app-frame-buffer\n\n");
}

bool encodeChanConfigParse(int argc, char *argv[], videoEncodeChannelConfig *pConfig) {
  const char *const short_opt = "e:c:f:i:p:l:b:q:";
  struct option long_opt[] = {
      {"height", required_argument, NULL, 'h'},
      {"width", required_argument, NULL, 'w'},
      {"encode-id", required_argument, NULL, 'e'},
      {"codec", required_argument, NULL, 'c'},
      {"surface-format", required_argument, NULL, 'f'},
      {"input-stream", required_argument, NULL, 'i'},
      {"output-file", required_argument, NULL, 'o'},
      {"profile", required_argument, NULL, 'p'},
      {"level", required_argument, NULL, 'l'},
      {"fps", required_argument, NULL, 'x'},
      {"bitrate", required_argument, NULL, 'b'},
      {"user-table", no_argument, NULL, 'u'},
      {"quality", required_argument, NULL, 'q'},
      {"app-frame-buffer", no_argument, NULL, 'r'},
      {"test-round", required_argument, NULL, 'n'},
      {"stress", no_argument, NULL, 's'},
      {"gop-len", required_argument, NULL, 1},
      {"b-frame", required_argument, NULL, 2},
      {"i-qp", required_argument, NULL, 3},
      {"p-qp", required_argument, NULL, 4},
      {"b-qp", required_argument, NULL, 5},
      {"max-qp", required_argument, NULL, 6},
      {"min-qp", required_argument, NULL, 7},
      {"ir-count", required_argument, NULL, 8},
      {"cabac", no_argument, NULL, 9},
      {"h-range", required_argument, NULL, 10},
      {"v-range", required_argument, NULL, 11},
      {"slice-max-mb", required_argument, NULL, 12},
      {"cabac-init", required_argument, NULL, 13},
      {0, 0, 0, 0},
  };

  int opt;
  int opt_idx;
  int i;
  optind = 1;  // re-init linux global opt indx as multiple cli parse may be involved

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

  /*init some default value*/
  const char tmp1[] = "Main";
  const char tmp2[] = "4";

  pConfig->width = 1920;
  pConfig->height = 1080;
  pConfig->encodeInstanceId = CNVIDEOENC_INSTANCE_0;
  pConfig->codec = CNCODEC_H264;
  pConfig->pixFmt = CNCODEC_PIX_FMT_NV12;
  pConfig->isEnableDump = false;

  memcpy(pConfig->profile, tmp1, 64);
  memcpy(pConfig->level, tmp2, 64);

  pConfig->fps = 30;
  pConfig->isAppAllocBuf = false;

  while ((opt = getopt_long(argc, argv, short_opt, long_opt, &opt_idx)) != -1) {
    switch (opt) {
      case 'h':
        pConfig->height = atoi(optarg);
        break;

      case 'w':
        pConfig->width = atoi(optarg);
        break;

      case 'e':
        pConfig->encodeInstanceId = (cnvideoEncInstance)atoi(optarg);
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

      case 'p':
        memcpy(pConfig->profile, optarg, 64);
        break;

      case 'l':
        memcpy(pConfig->level, optarg, 64);
        break;

      case 'x':
        pConfig->fps = atoi(optarg);
        break;

      case 'b':
        pConfig->bitrate = atoi(optarg);
        break;

      case 'u':
        pConfig->jpgApplyUserTable = true;
        break;

      case 'q':
        pConfig->jpgQuality = atoi(optarg);
        break;

      case 'r':
        pConfig->isAppAllocBuf = true;
        break;

      case 1:
        pConfig->gop_len = atoi(optarg);
        break;

      case 2:
        pConfig->b_frame_num = atoi(optarg);
        break;

      case 3:
        pConfig->IQP = atoi(optarg);
        break;

      case 4:
        pConfig->PQP = atoi(optarg);
        break;

      case 5:
        pConfig->BQP = atoi(optarg);
        break;

      case 6:
        pConfig->maxQP = atoi(optarg);
        break;

      case 7:
        pConfig->minQP = atoi(optarg);
        break;

      case 8:
        pConfig->IRCount = atoi(optarg);
        break;

      case 9:
        pConfig->entropyMode = CNVIDEOENC_ENTROPY_MODE_CABAC;
        break;

      case 10:
        pConfig->hRange = atoi(optarg);
        break;

      case 11:
        pConfig->vRange = atoi(optarg);
        break;

      case 12:
        pConfig->maxMBPerSlice = atoi(optarg);
        pConfig->sliceMode = CNVIDEOENC_SLICE_MODE_MAX_MB;
        break;

      case 13:
        pConfig->cabacInitIdc = atoi(optarg);
        break;

      default:
        break;
    }
  }

  printEncConfig(pConfig);

  return true;
}

void printEncConfig(videoEncodeChannelConfig *pConfig) {
  LOG_INFO("\n---------chan[%d] encode(vpu%d) config-----------\n", pConfig->encodeChannelId,
           pConfig->encodeInstanceId);

  LOG_INFO("[in]: planar_fmt [%s] resolution(w %d h %d)\n", surfaceFmtStrs[pConfig->pixFmt], pConfig->width,
           pConfig->height);

  if (pConfig->codec == CNCODEC_JPEG) {
    LOG_INFO("[out] JPEG jpg_apply_user_table(%d) quality(%d)\n", pConfig->jpgApplyUserTable, pConfig->jpgQuality);
  } else {
    LOG_INFO("[out] %s profile(%s), level(%s) fps(%d), br(%d)\n", codecStrs[pConfig->codec], pConfig->profile,
             pConfig->level, pConfig->fps, pConfig->bitrate);
  }

  LOG_INFO("[in] file name:(%s)\n", pConfig->inputFileName);
  LOG_INFO("[out]file name:(%s)\n\n", pConfig->outputFileName);
}

cnrtChannelType_t getBestChannelForEncoder(unsigned int instance) {
  if (instance == CNVIDEOENC_INSTANCE_0) {
    return CNRT_CHANNEL_TYPE_0;
  } else if (instance == CNVIDEOENC_INSTANCE_2) {
    return CNRT_CHANNEL_TYPE_1;
  }

  return CNRT_CHANNEL_TYPE_1;
}

int cnrtContextInit(int deviceId, cnrtChannelType_t channelId) {
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

int allocateEncodeBuffer(videoEncodeContext *pContext) {
  unsigned int i = 0, j = 0;
  unsigned int size;
  unsigned int width;
  unsigned int height;
  cnrtRet_t rtRet;
  uint32_t planesNum;

  planesNum = get_planes_num(pContext->chanConfig.pixFmt);
  width = pContext->chanConfig.width > 0 ? pContext->chanConfig.width : 1920;
  height = pContext->chanConfig.height > 0 ? pContext->chanConfig.height : 1080;
  for (i = 0; i < pContext->createInfo.inputBufNum; ++i) {
    pContext->createInfo.inputBuf[i].width = width;
    pContext->createInfo.inputBuf[i].height = height;
    pContext->createInfo.inputBuf[i].planeNum = planesNum;
    pContext->createInfo.inputBuf[i].pixelFmt = pContext->chanConfig.pixFmt;

    for (j = 0; j < planesNum; ++j) {
      unsigned int planeW = calc_plane_width(pContext->chanConfig.pixFmt, width, j);
      unsigned int stride = ALIGN64(planeW);
      size = stride * calc_plane_height(pContext->chanConfig.pixFmt, height, j);

      pContext->createInfo.inputBuf[i].plane[j].addr = 0;
      rtRet = cnrtMallocFrameBuffer((void **)(&pContext->createInfo.inputBuf[i].plane[j].addr), size);
      if (rtRet != CNRT_RET_SUCCESS) {
        LOG_ERROR("%s() call cnrtMallocFrameBuffer failed\n", __FUNCTION__);
        goto ALLOC_ERR;
      }

      pContext->createInfo.inputBuf[i].plane[j].size = size;
      pContext->createInfo.inputBuf[i].stride[j] = stride;
    }
  }

  for (i = 0; i < pContext->createInfo.outputBufNum; ++i) {
    pContext->createInfo.outputBuf[i].addr = 0;
    rtRet = cnrtMallocFrameBuffer((void **)(&pContext->createInfo.outputBuf[i].addr), OUTPUT_BUFFER_SIZE_FOR_ENCODE);
    if (rtRet != CNRT_RET_SUCCESS) {
      LOG_ERROR("%s() call cnrtMallocFrameBuffer failed\n", __FUNCTION__);
      goto ALLOC_ERR;
    }

    pContext->createInfo.outputBuf[i].size = OUTPUT_BUFFER_SIZE_FOR_ENCODE;
  }

  return 0;

ALLOC_ERR:
  for (i = 0; i < pContext->createInfo.inputBufNum; ++i) {
    for (j = 0; j < planesNum; ++j) {
      if (pContext->createInfo.inputBuf[i].plane[j].addr != 0) {
        cnrtFree((void *)pContext->createInfo.inputBuf[i].plane[j].addr);
      }
    }
  }

  for (i = 0; i < pContext->createInfo.outputBufNum; ++i) {
    if (pContext->createInfo.outputBuf[i].addr != 0) {
      cnrtFree((void *)pContext->createInfo.outputBuf[i].addr);
    }
  }

  return -1;
}

int releaseEncodeBuffer(videoEncodeContext *pContext) {
  cnrtRet_t rtRet;
  unsigned int i = 0, j = 0;

  for (i = 0; i < pContext->createInfo.inputBufNum; ++i) {
    for (j = 0; j < pContext->createInfo.inputBuf[i].planeNum; ++j) {
      rtRet = cnrtFree((void *)(pContext->createInfo.inputBuf[i].plane[j].addr));
      if (rtRet != CNRT_RET_SUCCESS) {
        LOG_ERROR("%s() call cnrtFree failed\n", __FUNCTION__);
      }
    }
  }

  for (i = 0; i < pContext->createInfo.outputBufNum; ++i) {
    rtRet = cnrtFree((void *)(pContext->createInfo.outputBuf[i].addr));
    if (rtRet != CNRT_RET_SUCCESS) {
      LOG_ERROR("%s() call cnrtFree failed\n", __FUNCTION__);
    }
  }

  return 0;
}

int initEncodeContext(videoEncodeContext *pContext) {
  /* init file read and write */
  pContext->inFile = fopen(pContext->chanConfig.inputFileName, "rb");
  if (pContext->chanConfig.isEnableDump) {
    pContext->outFile = fopen(pContext->chanConfig.outputFileName, "wb");
  }

  if (!pContext->inFile) {
    LOG_ERROR("open input file failed\n");
    return -1;
  }

  if (pContext->chanConfig.isEnableDump && !pContext->outFile) {
    LOG_ERROR("open output file failed\n");
    return -1;
  }

  fseek(pContext->inFile, 0, SEEK_END);
  pContext->inFileLen = ftell(pContext->inFile);
  fseek(pContext->inFile, 0, SEEK_SET);

  /* init create parameters */
  memset(&pContext->createInfo, 0, sizeof(pContext->createInfo));
  pContext->createInfo.userContext = (uint64_t)pContext;
  pContext->createInfo.deviceId = 0;
  pContext->createInfo.codec = pContext->chanConfig.codec;
  pContext->createInfo.instance = pContext->chanConfig.encodeInstanceId;
  pContext->createInfo.fpsNumerator = pContext->chanConfig.fps;
  pContext->createInfo.fpsDenominator = 1;
  pContext->createInfo.width = pContext->chanConfig.width;
  pContext->createInfo.height = pContext->chanConfig.height;
  pContext->createInfo.pixelFmt = pContext->chanConfig.pixFmt;
  pContext->createInfo.inputBufNum = 5;
  pContext->createInfo.outputBufNum = 5;
  pContext->createInfo.allocType = pContext->chanConfig.isAppAllocBuf ? CNCODEC_BUF_ALLOC_APP : CNCODEC_BUF_ALLOC_LIB;

  if (pContext->createInfo.allocType == CNCODEC_BUF_ALLOC_LIB)
    pContext->createInfo.suggestedLibAllocBitStrmBufSize = OUTPUT_BUFFER_SIZE_FOR_ENCODE;

  pContext->createInfo.rateCtrl.targetBitrate = pContext->chanConfig.bitrate;
  pContext->createInfo.rateCtrl.constIQP = pContext->chanConfig.IQP;
  pContext->createInfo.rateCtrl.constPQP = pContext->chanConfig.PQP;
  pContext->createInfo.rateCtrl.constBQP = pContext->chanConfig.BQP;
  pContext->createInfo.rateCtrl.gopLength = pContext->chanConfig.gop_len;
  if (pContext->chanConfig.bitrate != 0) {
    pContext->createInfo.rateCtrl.targetBitrate = pContext->chanConfig.bitrate;
    pContext->createInfo.rateCtrl.maxIQP = pContext->chanConfig.maxQP;
    pContext->createInfo.rateCtrl.maxPQP = pContext->chanConfig.maxQP;
    pContext->createInfo.rateCtrl.maxBQP = pContext->chanConfig.maxQP;
    pContext->createInfo.rateCtrl.minIQP = pContext->chanConfig.minQP;
    pContext->createInfo.rateCtrl.minPQP = pContext->chanConfig.minQP;
    pContext->createInfo.rateCtrl.minBQP = pContext->chanConfig.minQP;
  }

  switch (pContext->createInfo.codec) {
    case CNCODEC_H264:
      pContext->createInfo.uCfg.h264.profile = parseH264Profile(pContext->chanConfig.profile);
      pContext->createInfo.uCfg.h264.level = parseH264Level(pContext->chanConfig.level);
      pContext->createInfo.uCfg.h264.BFramesNum = pContext->chanConfig.b_frame_num;
      pContext->createInfo.uCfg.h264.IRCount = pContext->chanConfig.IRCount;
      pContext->createInfo.uCfg.h264.entropyMode = pContext->chanConfig.entropyMode;
      pContext->createInfo.uCfg.h264.horizontalRange = pContext->chanConfig.hRange;
      pContext->createInfo.uCfg.h264.verticalRange = pContext->chanConfig.vRange;
      pContext->createInfo.uCfg.h264.maxMBPerSlice = pContext->chanConfig.maxMBPerSlice;
      pContext->createInfo.uCfg.h264.sliceMode = pContext->chanConfig.sliceMode;
      pContext->createInfo.uCfg.h264.cabacInitIDC = pContext->chanConfig.cabacInitIdc;
      /*to do: add more option*/
      break;

    case CNCODEC_HEVC:
      pContext->createInfo.uCfg.h265.profile = parseH265Profile(pContext->chanConfig.profile);
      pContext->createInfo.uCfg.h265.level = parseH265Level(pContext->chanConfig.level);
      pContext->createInfo.uCfg.h265.BFramesNum = pContext->chanConfig.b_frame_num;
      pContext->createInfo.uCfg.h265.IRCount = pContext->chanConfig.IRCount;
      pContext->createInfo.uCfg.h265.horizontalRange = pContext->chanConfig.hRange;
      pContext->createInfo.uCfg.h265.verticalRange = pContext->chanConfig.vRange;
      pContext->createInfo.uCfg.h265.maxMBPerSlice = pContext->chanConfig.maxMBPerSlice;
      pContext->createInfo.uCfg.h265.sliceMode = pContext->chanConfig.sliceMode;
      pContext->createInfo.uCfg.h265.cabacInitIDC = pContext->chanConfig.cabacInitIdc;
      /*to do: add more option*/
      break;

    default:
      LOG_ERROR("codec %d not support\n", pContext->createInfo.codec);
      break;
  }

  /* allocate input and output buffer, and set buffers to createparametes */
  if (pContext->createInfo.allocType == CNCODEC_BUF_ALLOC_APP) {
    pContext->createInfo.inputBuf = (cncodecFrame *)malloc(pContext->createInfo.inputBufNum * sizeof(cncodecFrame));
    pContext->inputBufMap = (frameCpuAddr *)malloc(pContext->createInfo.inputBufNum * sizeof(frameCpuAddr));

    pContext->createInfo.outputBuf =
        (cncodecDevMemory *)malloc(pContext->createInfo.outputBufNum * sizeof(cncodecDevMemory));
    pContext->outputBufMap = (uint64_t *)malloc(pContext->createInfo.outputBufNum * sizeof(uint64_t));

    cnrtContextInit(0, getBestChannelForEncoder(pContext->chanConfig.encodeInstanceId));

    if (0 != allocateEncodeBuffer(pContext)) {
      LOG_ERROR("allocateEncodeBuffer failed\n");
      exit(0);
    }
  }

  pContext->eos = false;
  sem_init(&(pContext->eosSemaphore), 0, 0);

  return 0;
}

int deinitEncodeContext(videoEncodeContext *pContext) {
  if (pContext->createInfo.allocType == CNCODEC_BUF_ALLOC_APP) {
    releaseEncodeBuffer(pContext);
    free(pContext->createInfo.inputBuf);
    free(pContext->createInfo.outputBuf);
    free(pContext->inputBufMap);
    free(pContext->outputBufMap);

    pContext->createInfo.inputBuf = NULL;
    pContext->createInfo.outputBuf = NULL;
    pContext->inputBufMap = NULL;
    pContext->outputBufMap = NULL;
  }

  fclose(pContext->inFile);
  pContext->inFile = NULL;

  if (pContext->chanConfig.isEnableDump) {
    fclose(pContext->outFile);
    pContext->outFile = NULL;
  }

  memset(&pContext->statistics, 0, sizeof(cncodecTestStatistics));

  sem_destroy(&(pContext->eosSemaphore));

  return 0;
}

int readVideoFrameByMapping(videoEncodeContext *pContext, cncodecFrame *frame, bool *hasNext) {
  unsigned long long int curpos;
  unsigned int realReadCnt;
  unsigned int planW;
  unsigned int planH;
  unsigned int i;
  unsigned int j;
  cnrtRet_t rtRet;

  for (i = 0; i < frame->planeNum; ++i) {
    planW = calc_plane_width(frame->pixelFmt, frame->width, i);
    if (planW == frame->stride[i]) {
      void *cpuAddr;

      /*if the device address has been mapped before, cncodecMap will return the cpu address directly*/
      rtRet = cncodecMap(&cpuAddr, frame->plane[i].addr, frame->plane[i].size);
      CNRT_ERROR_CHECK(rtRet);

      realReadCnt = fread(cpuAddr, sizeof(char), frame->plane[i].size, pContext->inFile);
      if (realReadCnt < frame->plane[i].size) {
        LOG_INFO("no enough data to read\n");
        *hasNext = false;
      }

      /* after acess cpu address, do flush */
      cncodecFlushCache(cpuAddr, frame->plane[i].size);

      /*remember Umap*/
      rtRet = cncodecUnmap(cpuAddr, frame->plane[i].size);
      CNRT_ERROR_CHECK(rtRet);
    } else {
      planH = calc_plane_height(frame->pixelFmt, frame->height, i);
      char *tmpData = malloc(planW * planH);
      realReadCnt = fread(tmpData, sizeof(char), planW * planH, pContext->inFile);

      if (realReadCnt < planW * planH) {
        LOG_INFO("no enough data to read\n");
        *hasNext = false;
      }

      void *cpuAddr;
      rtRet = cncodecMap(&cpuAddr, frame->plane[i].addr, frame->plane[i].size);
      CNRT_ERROR_CHECK(rtRet);

      for (j = 0; j < planH; ++j) {
        memcpy(cpuAddr + j * frame->stride[i], (void *)(tmpData + j * planW), planW);
      }

      cncodecFlushCache(cpuAddr, frame->plane[i].size);
      rtRet = cncodecUnmap(cpuAddr, frame->plane[i].size);
      CNRT_ERROR_CHECK(rtRet);

      *hasNext = false;

      free(tmpData);
      tmpData = NULL;
    }
  }

  curpos = ftell(pContext->inFile);
  if (pContext->inFileLen == curpos) {
    *hasNext = false;
  } else {
    *hasNext = true;
  }

  return 0;
}

int readVideoFrame(videoEncodeContext *pContext, cncodecFrame *frame, bool *hasNext) {
  unsigned long long int curpos;
  unsigned int realReadCnt;
  unsigned int planW;
  unsigned int planH;
  unsigned int i;
  unsigned int j;
  cnrtRet_t rtRet;
  char *tmpData = NULL;

  for (i = 0; i < frame->planeNum; ++i) {
    planW = calc_plane_width(frame->pixelFmt, frame->width, i);
    if (planW == frame->stride[i]) {
      // width is 64 byte aligned, read directly
      tmpData = malloc(frame->plane[i].size);
      realReadCnt = fread(tmpData, sizeof(char), frame->plane[i].size, pContext->inFile);
      if (realReadCnt < frame->plane[i].size) {
        LOG_INFO("no enough data to read\n");
        *hasNext = false;
        goto READ_ERR;
      }
      rtRet =
          cnrtMemcpy((void *)frame->plane[i].addr, (void *)tmpData, frame->plane[i].size, CNRT_MEM_TRANS_DIR_HOST2DEV);
      CNRT_ERROR_CHECK(rtRet);

      free(tmpData);
      tmpData = NULL;
    } else {
      // width is not 64 byte aligned, should copy line by line
      planH = calc_plane_height(frame->pixelFmt, frame->height, i);
      char *tmpData = malloc(planW * planH);
      realReadCnt = fread(tmpData, sizeof(char), planW * planH, pContext->inFile);

      if (realReadCnt < planW * planH) {
        LOG_INFO("no enough data to read\n");
        *hasNext = false;
        goto READ_ERR;
      }

      for (j = 0; j < planH; ++j) {
        rtRet = cnrtMemcpy((void *)(frame->plane[i].addr + j * frame->stride[i]), (void *)(tmpData + j * planW), planW,
                           CNRT_MEM_TRANS_DIR_HOST2DEV);
        CNRT_ERROR_CHECK(rtRet);
      }

      *hasNext = false;

      free(tmpData);
      tmpData = NULL;
    }
  }

  curpos = ftell(pContext->inFile);
  if (pContext->inFileLen == curpos) {
    *hasNext = false;
  } else {
    *hasNext = true;
  }

  return 0;

READ_ERR:
  if (tmpData != NULL) free(tmpData);

  return -1;
}

/*way 01: mapping way*/
int writeBitstreamToFileBymapping(videoEncodeContext *pContext, cnvideoEncOutput *encOutput) {
  void *validDataAddr = NULL;
  cnrtRet_t rtRet;

  /*cnrt context must be init for this thread*/
  cnrtContextInit(0, getBestChannelForEncoder(pContext->chanConfig.encodeInstanceId));

  rtRet = cncodecMap(&validDataAddr, encOutput->streamBuffer.addr, encOutput->streamLength);
  CNRT_ERROR_CHECK(rtRet);

  rtRet = cncodecInvalidateCache(validDataAddr, encOutput->streamLength);
  if (rtRet != CNRT_RET_SUCCESS) {
    LOG_ERROR("%s() call cncodecInvalidateCache failed\n", __FUNCTION__);
  }

  validDataAddr = validDataAddr + encOutput->dataOffset;  // valid data start address skip the data offset

  if (encOutput->streamLength != fwrite(validDataAddr, sizeof(char), encOutput->streamLength, pContext->outFile)) {
    LOG_ERROR("dump output stream data failed\n");
  }

  rtRet = cncodecUnmap(validDataAddr - encOutput->dataOffset, encOutput->streamLength);
  CNRT_ERROR_CHECK(rtRet);

  return 0;
}

/*way 02:  cnrtMemcpy host2device way*/
int writeBitstreamToFile(videoEncodeContext *pContext, cnvideoEncOutput *encOutput) {
  void *validDataAddr = NULL;
  void *tmpData;
  cnrtRet_t rtRet;

  cnrtContextInit(0, getBestChannelForEncoder(pContext->chanConfig.encodeInstanceId));

  // LOG_ERROR("addr %llx len %u\n", encOutput->streamBuffer.addr, encOutput->streamLength);

  validDataAddr = (void *)(encOutput->streamBuffer.addr + encOutput->dataOffset);
  tmpData = malloc(encOutput->streamLength);
  rtRet = cnrtMemcpy(tmpData, (void *)validDataAddr, encOutput->streamLength, CNRT_MEM_TRANS_DIR_DEV2HOST);
  CNRT_ERROR_CHECK(rtRet);

  if (encOutput->streamLength != fwrite((void *)tmpData, sizeof(char), encOutput->streamLength, pContext->outFile)) {
    LOG_ERROR("dump output stream data failed\n");
  }

  free(tmpData);
  tmpData = NULL;

  return 0;
}