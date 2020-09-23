#ifndef _JPEG_DECODE_CONTEXT_H_
#define _JPEG_DECODE_CONTEXT_H_

#include <semaphore.h>
#include <string.h>

#include "cn_codec_common.h"
#include "cn_jpeg_dec.h"
#include "cncodec_demo_common.h"

#define INPUT_BUFFER_SIZE_FOR_DECODE (4 * 1024 * 1024)

typedef struct {
  bool isEnableDump;                  /*<enable dump output data>*/
  bool interlaced;                    /*<flag to indicate src stream is interlaced file >*/
  int decodeChannelId;                /*<unique decoder channel id > */
  cnjpegDecInstance decodeInstanceId; /*<decode instance id to specify hw core id to run decoding task >*/
  cncodecPixelFormat pixFmt;          /*<decode output yuv surface format > */
  u32_t outputWidth;           /*<decode output frame width, if 0, using stream original width as output width > */
  u32_t outputHeight;          /*<decode output frame height, if 0, using stream original height as output height > */
  cncodecType codec;           /*<source stream codec type >*/
  DecodeFileReadMode readMode; /*<video stream file read mode negotiated by codec type and user setting>*/
  bool isAppAllocBuf;          /*<decoder use app allocated buffer or decoder use internal allcoated buffer >*/
  bool isForceSendEosInNullFrame; /*<test case, force send EOS in null frame after last valid stream data >*/
  char inputFileName[256];
  char outputFileName[256];
  u32_t test_round;
  bool decode_run_mode_sync;
} jpegDecodeChannelConfig;

typedef struct {
  jpegDecodeChannelConfig chanConfig; /*< decode channel config options parsed from command line > */
  cnjpegDecoder handle;               /*< decode handle corresponding to decoder_id>*/
  FILE *inFile;                       /*< source file reader to buffer >*/
  FILE *outFile;                      /*< decode output bitstream dump file >*/
  unsigned long long inFileLen;       /*< input file length >*/
  cncodecTestStatistics statistics;   /*< decode channel statistics collection: frame num, total time... > */
  sem_t eosSemaphore;                 /*< semaphore to sync stop between encoder and app enc thread>*/
  cnjpegDecCreateInfo createInfo;
  cnjpegDecInput decInput;
  bool eos;
} jpegDecodeContext;

bool decodeChanConfigParse(int argc, char *argv[], jpegDecodeChannelConfig *pConfig);

void printDecConfig(jpegDecodeChannelConfig *pConfig);

int allocateDecodeBuffer(jpegDecodeContext *pContext);

int releaseDecodeBuffer(jpegDecodeContext *pContext);

int initDecodeContext(jpegDecodeContext *pContext);

int deinitDecodeContext(jpegDecodeContext *pContext);

int readStreamData(jpegDecodeContext *pContext, cnjpegDecInput *pDecInput, int size, DecodeFileReadMode readMode,
                   bool *hasNext);

int writeFrameToFile(jpegDecodeContext *pContex, cncodecFrame *frame);

void resetStreamPositionToStart(jpegDecodeContext *pContext);

int allocateDecCodecFrameBuffer(jpegDecodeContext *pContext, cncodecFrame *frame);

int releaseDecCodecFrameBuffer(cncodecFrame *outputFrame);

#endif /*_JPEG_DECODE_CONTEXT_H_ */
