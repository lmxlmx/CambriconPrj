#ifndef _VIDEO_DECODE_CONTEXT_H_
#define _VIDEO_DECODE_CONTEXT_H_

#include <semaphore.h>
#include <stdbool.h>
#include <string.h>
#include "cn_codec_common.h"
#include "cn_video_dec.h"
#include "cncodec_demo_common.h"

#define INPUT_BUFFER_SIZE_FOR_DECODE (4 * 1024 * 1024)  // must be 4k align

typedef enum {
  VIDEO_DECODE_EXCEPTION_CODE_NONE = 0, /*do not test exception case*/
  OUTPUT_BUFFER_NOT_RELEASE_REF,        /*case 1: not all output buffers are releaseref to cncodec*/
  EXCEPTION_CODE_MAX,
} videoDecodeExceptionCode;

typedef struct {
  bool_t isEnableDump;                 /*<enable dump output data>*/
  bool_t interlaced;                   /*<flag to indicate src stream is interlaced file >*/
  i32_t decodeChannelId;               /*<unique decoder channel id > */
  cnvideoDecInstance decodeInstanceId; /*<decode instance id to specify hw core id to run decoding task >*/
  cncodecPixelFormat pixFmt;           /*<decode output yuv surface format > */
  u32_t outputWidth;           /*<decode output frame width, if 0, using stream original width as output width > */
  u32_t outputHeight;          /*<decode output frame height, if 0, using stream original height as output height > */
  cncodecType codec;           /*<source stream codec type >*/
  DecodeFileReadMode readMode; /*<video stream file read mode negotiated by codec type and user setting>*/
  bool isAppAllocBuf;          /*<decoder use app allocated buffer or decoder use internal allcoated buffer >*/
  bool isForceSendEosInNullFrame; /*<test case, force send EOS in null frame after last valid stream data >*/
  char inputFileName[256];
  char outputFileName[256];
  videoDecodeExceptionCode exceptionTestCode; /*<exception test code for different case>*/
} videoDecodeChannelConfig;

typedef struct {
  u8_t *bufAddr;
  u8_t *bufWp;
  u8_t *bufRp;

} streamBufInfo;

typedef struct {
  videoDecodeChannelConfig chanConfig; /*< decode channel config options parsed from command line > */
  cnvideoDecoder handle;               /*< decode handle corresponding to decoder_id>*/
  cnvideoDecSequenceInfo seqinfo;      /*<decode parameters inited by app and updated by decoder after inital parse >*/
  FILE *inFile;                        /*< source file reader to buffer >*/
  FILE *outFile;                       /*< decode output bitstream dump file >*/
  cncodecTestStatistics statistics;    /*< decode channel statistics collection: frame num, total time... > */
  frameCpuAddr *outputBufMap;          /*< record cpumap address for device adress of input buffer*/
  uint64_t *inputBufMap;               /*< record cpumap address for device adress of output buffer*/
  sem_t eosSemaphore;                  /*< semaphore to sync stop between encoder and app enc thread>*/
  cnvideoDecCreateInfo decInfo;
  cnvideoDecInput streamInfo;
  bool eos;
  bool needReadFileData;
  streamBufInfo bufInfo;

} videoDecodeContext;

bool decodeChanConfigParse(int argc, char *argv[], videoDecodeChannelConfig *pConfig);

void printDecConfig(videoDecodeChannelConfig *pConfig);

int allocateDecodeBuffer(videoDecodeContext *pContext);

int releaseDecodeBuffer(videoDecodeContext *pContext);

int initDecodeContext(videoDecodeContext *pContext);

int deinitDecodeContext(videoDecodeContext *pContext);

int readInputStreamData(videoDecodeContext *pContext, cnvideoDecInput *pDecInput, int size);

int writeFrameToFile(videoDecodeContext *pContex, cncodecFrame *frame);

int updateDecodeContext(videoDecodeContext *pContext);

#endif /*_VIDEO_DECODE_CONTEXT_H_ */
