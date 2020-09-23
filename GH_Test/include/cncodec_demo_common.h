#ifndef CNCODEC_DEMO_COMMON_H_
#define CNCODEC_DEMO_COMMON_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "cn_codec_common.h"
#include "cn_video_enc.h"

#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef CNCODEC_TEST_ENABLE_DEBUG_LOG
#define LOG_VERBOSE(fmt, args...)                      \
  do {                                                 \
    fprintf(stdout, "\033[33m" fmt "\033[0m", ##args); \
  } while (0)
#define LOG_DEBUG(fmt, args...)   \
  do {                            \
    fprintf(stdout, fmt, ##args); \
  } while (0)
#else
#define LOG_VERBOSE(fmt, args...)
#define LOG_DEBUG(fmt, args...)
#endif /* CNCODEC_TEST_ENABLE_DEBUG_LOG */

#define LOG_INFO(fmt, args...)                         \
  do {                                                 \
    fprintf(stdout, "\033[32m" fmt "\033[0m", ##args); \
  } while (0)
#define LOG_ERROR(fmt, args...)                        \
  do {                                                 \
    fprintf(stderr, "\033[31m" fmt "\033[0m", ##args); \
  } while (0)

//#define DEMO_CHUNK_SIZE (4 * 1024 * 1024) //can be other value based on different requirements or scenarios

#define ALIGN128(x) ((x + 128 - 1) & (~(128 - 1)))
#define ALIGN256(x) ((x + 256 - 1) & (~(256 - 1)))
#define ALIGN64(x) ((x + 64 - 1) & (~(64 - 1)))

typedef enum { DEC_NALU = 0, DEC_CHUNK = 1, ENC_FRAME = 2, STRM_READ_MODE_MAX } DecodeFileReadMode;

typedef struct { uint64_t cpuAddr[6]; } frameCpuAddr;

#define CNCODEC_TEST_CHECK_NULL_PTR_RET(ptr, ret)                \
  do {                                                           \
    if (ptr == nullptr) {                                        \
      LOG_ERROR("%s:[%d] null pointer", __FUNCTION__, __LINE__); \
      assert(0);                                                 \
      return ret;                                                \
    }                                                            \
  } while (0)

#define CNCODEC_TEST_CHECK_NULL_PTR(ptr)                         \
  do {                                                           \
    if (ptr == nullptr) {                                        \
      LOG_ERROR("%s:[%d] null pointer", __FUNCTION__, __LINE__); \
      assert(0);                                                 \
      return;                                                    \
    }                                                            \
  } while (0)

#define CNRT_ERROR_CHECK(ret)                                           \
  if (ret != CNRT_RET_SUCCESS) {                                        \
    LOG_ERROR("error occur, func: %s, line: %d\n", __func__, __LINE__); \
  }

extern char *codecStrs[];
extern char *surfaceFmtStrs[];

static inline unsigned int get_planes_num(cncodecPixelFormat fmt) {
  if (fmt == CNCODEC_PIX_FMT_NV12 || fmt == CNCODEC_PIX_FMT_NV21 || fmt == CNCODEC_PIX_FMT_P010) {
    return 2;
  } else if (fmt == CNCODEC_PIX_FMT_I420 || fmt == CNCODEC_PIX_FMT_YV12) {
    return 3;
  }

  return 1;
}

static inline unsigned int calc_plane_length(cncodecPixelFormat fmt, unsigned int pitch, unsigned int height,
                                             int plane) {
  unsigned int planeLength;
  if (fmt == CNCODEC_PIX_FMT_NV12 || fmt == CNCODEC_PIX_FMT_NV21 || fmt == CNCODEC_PIX_FMT_I420 ||
      fmt == CNCODEC_PIX_FMT_YV12 || fmt == CNCODEC_PIX_FMT_P010) {
    planeLength = plane == 0 ? (pitch * height) : (pitch * (height >> 1));
  } else {
    planeLength = pitch * height;
  }
  return planeLength;
}

static inline unsigned int calc_plane_height(cncodecPixelFormat fmt, unsigned int height, int plane) {
  if (fmt == CNCODEC_PIX_FMT_NV12 || fmt == CNCODEC_PIX_FMT_NV21 || fmt == CNCODEC_PIX_FMT_I420 ||
      fmt == CNCODEC_PIX_FMT_YV12 || fmt == CNCODEC_PIX_FMT_P010) {
    return plane == 0 ? height : height / 2;
  }

  return height;
}

static inline unsigned int calc_plane_width(cncodecPixelFormat fmt, unsigned int width, int plane) {
  unsigned int planWidth = 0;
  switch (fmt) {
    case CNCODEC_PIX_FMT_NV12:
    case CNCODEC_PIX_FMT_NV21:
      planWidth = width;
      break;

    case CNCODEC_PIX_FMT_P010:
      planWidth = 2 * width;
      break;

    case CNCODEC_PIX_FMT_I420:
    case CNCODEC_PIX_FMT_YV12:
      planWidth = plane == 0 ? width : width / 2;
      break;

    case CNCODEC_PIX_FMT_YUYV:
    case CNCODEC_PIX_FMT_UYVY:
    case CNCODEC_PIX_FMT_VYUY:
    case CNCODEC_PIX_FMT_YVYU:
      planWidth = width * 2;
      break;

    case CNCODEC_PIX_FMT_ABGR:
    case CNCODEC_PIX_FMT_BGRA:
      planWidth = width * 4;
      break;

    default:
      LOG_ERROR("Unknown fmt(%d)\n", fmt);
      break;
  }

  return planWidth;
}

static inline uint32_t calculate_duraion_us(struct timeval *start, struct timeval *end) {
  return (end->tv_sec - start->tv_sec) * 1000 * 1000 + (end->tv_usec - start->tv_usec);
}

#define CNCODEC_TESET_UNUSED(x) \
  do {                          \
    (void)(x);                  \
  } while (0)

typedef struct {
  struct timeval start;
  struct timeval end;
  uint32_t total_time_cost;
  uint32_t total_frame_count;
  uint32_t finished_test_round;
} cncodecTestStatistics;

cnvideoEncProfile parseH264Profile(const char *profileStr);

cnvideoEncProfile parseH265Profile(const char *profileStr);

cnvideoEncLevel parseH264Level(const char *levelStr);

cnvideoEncLevel parseH265Level(const char *levelStr);

cncodecPixelFormat ParsePixelFormat(const char *surfaceFmtStr);

cncodecType parseCodecType(const char *codecStr);

int calculateFramePicSize(int width, int height, cncodecPixelFormat surfaceFormat);

DecodeFileReadMode string2ReadMode(const char *modeString);

#endif /* CNCODEC_DEMO_COMMON_H_ */
