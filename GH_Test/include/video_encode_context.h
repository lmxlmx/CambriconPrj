#ifndef _VIDEO_ENCODE_CONTEXT_H_
#define _VIDEO_ENCODE_CONTEXT_H_

#include <semaphore.h>
#include <stdbool.h>
#include <string.h>

#include "cn_codec_common.h"
#include "cn_video_enc.h"
#include "cncodec_demo_common.h"

#define OUTPUT_BUFFER_SIZE_FOR_ENCODE (1024 * 4096)  // must be 4k align

typedef struct {
  bool isAppAllocBuf; /* encoder use app allocated buffer or decoder use internal allcoated buffer */
  bool isEnableDump;
  bool jpgApplyUserTable;
  int jpgQuality;
  const int encodeChannelId;
  uint32_t width;
  uint32_t height;
  uint32_t frameSize;
  int fps;
  uint32_t gop_len;
  uint32_t b_frame_num;
  uint32_t IQP;
  uint32_t BQP;
  uint32_t PQP;
  uint32_t maxQP;
  uint32_t minQP;
  uint32_t IRCount;
  uint32_t hRange;
  uint32_t vRange;
  uint32_t maxMBPerSlice;
  uint32_t cabacInitIdc;
  uint32_t bitrate;
  cnvideoEncEntropyMode entropyMode;
  cnvideoEncSliceMode sliceMode;
  cncodecPixelFormat pixFmt;
  cnvideoEncInstance encodeInstanceId;
  cncodecType codec;
  char profile[64];
  char level[64];
  char inputFileName[256];
  char outputFileName[256];
} videoEncodeChannelConfig;

typedef struct {
  videoEncodeChannelConfig chanConfig; /*< encode channel config options parsed from command line > */
  cnvideoEncoder handle;               /*< encoder handle corresponding to decoder_id>*/
  cnvideoEncCreateInfo createInfo;     /*< encode create params >*/
  cnvideoEncInput encInput;            /*< single picture encode parameters >*/
  FILE *inFile;                        /*< source file reader to buffer >*/
  FILE *outFile;                       /*< encode output bitstream dump file >*/
  unsigned long long inFileLen;        /*< input file length >*/
  frameCpuAddr *inputBufMap;           /*< record cpumap address for device adress of input buffer*/
  uint64_t *outputBufMap;              /*< record cpumap address for device adress of output buffer*/
  cncodecTestStatistics statistics;    /*< encode channel statistics collection: frame num, total time... > */
  sem_t eosSemaphore;                  /*< semaphore to sync stop between encoder and app enc thread>*/
  bool eos;
} videoEncodeContext;

bool encodeChanConfigParse(int argc, char *argv[], videoEncodeChannelConfig *pConfig);

void printEncConfig(videoEncodeChannelConfig *pConfig);

int allocateEncodeBuffer(videoEncodeContext *pContext);

int releaseEncodeBuffer(videoEncodeContext *pContext);

int initEncodeContext(videoEncodeContext *pContext);

int deinitEncodeContext(videoEncodeContext *pContext);

int writeBitstreamToFileBymapping(videoEncodeContext *pContext, cnvideoEncOutput *encOutput);

int writeBitstreamToFile(videoEncodeContext *pContext, cnvideoEncOutput *encOutput);

int readVideoFrameByMapping(videoEncodeContext *pContext, cncodecFrame *frame, bool *hasNext);
int readVideoFrame(videoEncodeContext *pContex, cncodecFrame *frame, bool *hasNext);

#endif /*_VIDEO_ENCODE_CONTEXT_H_ */
