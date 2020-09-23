#ifndef _JPEG_ENCODE_CONTEXT_H_
#define _JPEG_ENCODE_CONTEXT_H_

#include <semaphore.h>
#include <stdbool.h>
#include <string.h>

#include "cn_jpeg_enc.h"
#include "cncodec_demo_common.h"

#define OUTPUT_BUFFER_SIZE_FOR_ENCODE (1024 * 8192)

typedef struct {
  bool isAppAllocBuf; /* encoder use app allocated buffer or decoder use internal allcoated buffer */
  bool jpgApplyUserTable;
  int jpgQuality;
  const int encodeChannelId;
  uint32_t width;
  uint32_t height;
  uint32_t frameSize;
  cncodecPixelFormat pixFmt;
  cnjpegEncInstance encodeInstanceId;
  cncodecType codec;
  char inputFileName[256];
  char outputFileName[256];
  u32_t test_round;
  bool decode_run_mode_sync;
} jpegEncodeChannelConfig;

typedef struct {
  jpegEncodeChannelConfig chanConfig; /*< encode channel config options parsed from command line > */
  cnjpegEncoder handle;               /*< encoder handle corresponding to decoder_id>*/
  cnjpegEncCreateInfo createInfo;     /*< encode create params >*/
  cnjpegEncInput encInput;            /*< single picture encode parameters >*/
  FILE *inFile;                       /*< source file reader to buffer >*/
  FILE *outFile;                      /*< encode output bitstream dump file >*/
  unsigned long long inFileLen;       /*< input file length >*/
  cncodecTestStatistics statistics;   /*< encode channel statistics collection: frame num, total time... > */
  sem_t eosSemaphore;                 /*< semaphore to sync stop between encoder and app enc thread>*/
  bool eos;
} jpegEncodeContext;

bool encodeChanConfigParse(int argc, char *argv[], jpegEncodeChannelConfig *pConfig);

int set_attribuite(jpegEncodeContext *pContext);

void printEncConfig(jpegEncodeChannelConfig *pConfig);

int allocateEncodeBuffer(jpegEncodeContext *pContext);

int releaseEncodeBuffer(jpegEncodeContext *pContext);

int initEncodeContext(jpegEncodeContext *pContext);

int deinitEncodeContext(jpegEncodeContext *pContext);

int writeBitstreamToFile(jpegEncodeContext *pContext, cnjpegEncOutput *encOutput);

int readYuvFrame(jpegEncodeContext *pContex, cncodecFrame *frame, bool *hasNext);

void resetStreamPositionToStart(jpegEncodeContext *pContext);

int allocateSyncEncodeInOutBuffer(jpegEncodeContext *pContext, cncodecFrame *in_frame,
                                  cncodecDevMemory *out_stream_mem);

int releaseSyncEncodeInOutBuffer(cncodecFrame *in_frame, cncodecDevMemory *out_stream_mem);

#endif /*_JPEG_ENCODE_CONTEXT_H_ */
