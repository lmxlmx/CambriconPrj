#include "cncodec_demo_common.h"

char *codecStrs[] = {"MPEG2", "MPEG4", "H264", "HEVC", "VP8", "VP9", "AVS", "JPEG"};
char *surfaceFmtStrs[] = {"NV12", "NV21",         "I420",         "YV12", "YUYV", "UYVY", "YVYU", "VYUY",
                          "P010", "YUV420_10BIT", "YUV444_10BIT", "ARGB", "ABGR", "BGRA", "RGBA", "RAW"};

cnvideoEncProfile parseH264Profile(const char *profileStr) {
  // LOG_INFO("%s: %s\n", __FUNCTION__, profileStr);

  if (0 == strcmp(profileStr, "Baseline")) {
    return CNVIDEOENC_PROFILE_H264_BASELINE;
  } else if (0 == strcmp(profileStr, "Main")) {
    return CNVIDEOENC_PROFILE_H264_MAIN;
  } else if (0 == strcmp(profileStr, "High")) {
    return CNVIDEOENC_PROFILE_H264_HIGH;
  } else if (0 == strcmp(profileStr, "High_10")) {
    return CNVIDEOENC_PROFILE_H264_HIGH_10;
  }

  return CNVIDEOENC_PROFILE_H264_BASELINE;
}

cnvideoEncProfile parseH265Profile(const char *profileStr) {
  // LOG_INFO("%s: %s\n", __FUNCTION__, profileStr);

  if (0 == strcmp(profileStr, "Main")) {
    return CNVIDEOENC_PROFILE_H265_MAIN;
  } else if (0 == strcmp(profileStr, "Still")) {
    return CNVIDEOENC_PROFILE_H265_MAIN_STILL;
  } else if (0 == strcmp(profileStr, "Intra")) {
    return CNVIDEOENC_PROFILE_H265_MAIN_INTRA;
  } else if (0 == strcmp(profileStr, "Main_10")) {
    return CNVIDEOENC_PROFILE_H265_MAIN_10;
  }

  return CNVIDEOENC_PROFILE_H265_MAIN;
}

cnvideoEncLevel parseH264Level(const char *levelStr) {
  int level_code;
  // LOG_INFO("%s: %s\n", __FUNCTION__, levelStr);

  if (0 == strcmp(levelStr, "1b")) {
    return CNVIDEOENC_LEVEL_H264_1B;
  } else {
    level_code = atoi(levelStr);
    switch (level_code) {
      case 1:
        return CNVIDEOENC_LEVEL_H264_1;
      case 11:
        return CNVIDEOENC_LEVEL_H264_11;
      case 12:
        return CNVIDEOENC_LEVEL_H264_12;
      case 13:
        return CNVIDEOENC_LEVEL_H264_13;
      case 2:
        return CNVIDEOENC_LEVEL_H264_2;
      case 21:
        return CNVIDEOENC_LEVEL_H264_21;
      case 22:
        return CNVIDEOENC_LEVEL_H264_22;
      case 3:
        return CNVIDEOENC_LEVEL_H264_3;
      case 31:
        return CNVIDEOENC_LEVEL_H264_31;
      case 32:
        return CNVIDEOENC_LEVEL_H264_32;
      case 4:
        return CNVIDEOENC_LEVEL_H264_4;
      case 41:
        return CNVIDEOENC_LEVEL_H264_41;
      case 42:
        return CNVIDEOENC_LEVEL_H264_42;
      case 5:
        return CNVIDEOENC_LEVEL_H264_5;
      case 51:
        return CNVIDEOENC_LEVEL_H264_51;
      default:
        break;
    }
  }

  return CNVIDEOENC_LEVEL_H264_4;
}

cnvideoEncLevel parseH265Level(const char *levelStr) {
  // LOG_INFO("%s: %s\n", __FUNCTION__, levelStr);

  if (0 == strcmp(levelStr, "Main_1")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_1;
  } else if (0 == strcmp(levelStr, "High_1")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_1;
  } else if (0 == strcmp(levelStr, "Main_2")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_2;
  } else if (0 == strcmp(levelStr, "High_2")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_2;
  } else if (0 == strcmp(levelStr, "Main_21")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_21;
  } else if (0 == strcmp(levelStr, "High_21")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_21;
  } else if (0 == strcmp(levelStr, "Main_3")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_3;
  } else if (0 == strcmp(levelStr, "High_3")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_3;
  } else if (0 == strcmp(levelStr, "Main_31")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_31;
  } else if (0 == strcmp(levelStr, "High_31")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_31;
  } else if (0 == strcmp(levelStr, "Main_4")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_4;
  } else if (0 == strcmp(levelStr, "High_4")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_4;
  } else if (0 == strcmp(levelStr, "Main_41")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_41;
  } else if (0 == strcmp(levelStr, "High_41")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_41;
  } else if (0 == strcmp(levelStr, "Main_5")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_5;
  } else if (0 == strcmp(levelStr, "High_5")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_5;
  } else if (0 == strcmp(levelStr, "Main_51")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_51;
  } else if (0 == strcmp(levelStr, "High_51")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_51;
  } else if (0 == strcmp(levelStr, "Main_52")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_52;
  } else if (0 == strcmp(levelStr, "High_52")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_52;
  } else if (0 == strcmp(levelStr, "Main_6")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_6;
  } else if (0 == strcmp(levelStr, "High_6")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_6;
  } else if (0 == strcmp(levelStr, "Main_61")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_61;
  } else if (0 == strcmp(levelStr, "High_61")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_61;
  } else if (0 == strcmp(levelStr, "Main_62")) {
    return CNVIDEOENC_LEVEL_H265_MAIN_62;
  } else if (0 == strcmp(levelStr, "High_62")) {
    return CNVIDEOENC_LEVEL_H265_HIGH_62;
  }

  return CNVIDEOENC_LEVEL_H265_MAIN_4;
}

cncodecPixelFormat ParsePixelFormat(const char *surfaceFmtStr) {
  // LOG_INFO("%s: %s\n", __FUNCTION__, surfaceFmtStr);

  if (0 == strcmp(surfaceFmtStr, "NV12")) {
    return CNCODEC_PIX_FMT_NV12;
  } else if (0 == strcmp(surfaceFmtStr, "YV12")) {
    return CNCODEC_PIX_FMT_YV12;
  } else if (0 == strcmp(surfaceFmtStr, "YUYV")) {
    return CNCODEC_PIX_FMT_YUYV;
  } else if (0 == strcmp(surfaceFmtStr, "UYVY")) {
    return CNCODEC_PIX_FMT_UYVY;
  } else if (0 == strcmp(surfaceFmtStr, "P010")) {
    return CNCODEC_PIX_FMT_P010;
  } else if (0 == strcmp(surfaceFmtStr, "I420")) {
    return CNCODEC_PIX_FMT_I420;
  } else if (0 == strcmp(surfaceFmtStr, "NV21")) {
    return CNCODEC_PIX_FMT_NV21;
  } else if (0 == strcmp(surfaceFmtStr, "YUV420_10BIT")) {
    return CNCODEC_PIX_FMT_YUV420_10BIT;
  } else if (0 == strcmp(surfaceFmtStr, "YUV444_10BIT")) {
    return CNCODEC_PIX_FMT_YUV444_10BIT;
  } else if (0 == strcmp(surfaceFmtStr, "ARGB")) {
    return CNCODEC_PIX_FMT_ARGB;
  } else if (0 == strcmp(surfaceFmtStr, "ABGR")) {
    return CNCODEC_PIX_FMT_ABGR;
  } else if (0 == strcmp(surfaceFmtStr, "RGBA")) {
    return CNCODEC_PIX_FMT_RGBA;
  }

  return CNCODEC_PIX_FMT_NV12;
}

cncodecType parseCodecType(const char *codecStr) {
  // LOG_INFO("%s: %s\n", __FUNCTION__, codecStr);

  if (0 == strcmp(codecStr, "MPEG2") || 0 == strcmp(codecStr, "MPEG2")) {
    return CNCODEC_MPEG2;
  } else if (0 == strcmp(codecStr, "MPEG4") || 0 == strcmp(codecStr, "MP4")) {
    return CNCODEC_MPEG2;
  } else if (0 == strcmp(codecStr, "H264")) {
    return CNCODEC_H264;
  } else if (0 == strcmp(codecStr, "H265") || 0 == strcmp(codecStr, "HEVC")) {
    return CNCODEC_HEVC;
  } else if (0 == strcmp(codecStr, "JPEG")) {
    return CNCODEC_JPEG;
  } else if (0 == strcmp(codecStr, "VP8")) {
    return CNCODEC_VP8;
  } else if (0 == strcmp(codecStr, "VP9")) {
    return CNCODEC_VP9;
  } else if (0 == strcmp(codecStr, "AVS")) {
    return CNCODEC_AVS;
  }

  return CNCODEC_TOTAL_COUNT;
}

int calculateFramePicSize(int width, int height, cncodecPixelFormat surfaceFormat) {
  int size = width * height;

  switch (surfaceFormat) {
    case CNCODEC_PIX_FMT_NV12:
    case CNCODEC_PIX_FMT_NV21:
    case CNCODEC_PIX_FMT_I420:
    case CNCODEC_PIX_FMT_YV12:
      size += (size >> 1);
      break;

    case CNCODEC_PIX_FMT_YUYV:
    case CNCODEC_PIX_FMT_UYVY:
      size = (size << 1);
      break;

    case CNCODEC_PIX_FMT_ARGB:
    case CNCODEC_PIX_FMT_RGBA:
    case CNCODEC_PIX_FMT_ABGR:
    case CNCODEC_PIX_FMT_BGRA:
      size = (size << 2);
      break;

    case CNCODEC_PIX_FMT_P010:
      size += (size << 1);
      break;

    default:
      LOG_ERROR("encode planar fmt(%d) not support\n", (int)surfaceFormat);
      break;
  }

  return size;
}

DecodeFileReadMode string2ReadMode(const char *modeString) {
  if (0 == strcmp(modeString, "NALU")) {
    return DEC_NALU;
  } else if (0 == strcmp(modeString, "CHUNK")) {
    return DEC_CHUNK;
  } else if (0 == strcmp(modeString, "YUV")) {
    return ENC_FRAME;
  }

  return STRM_READ_MODE_MAX;
}
