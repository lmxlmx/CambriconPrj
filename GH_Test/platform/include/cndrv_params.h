#ifndef CALLBACKAPI_CNDRV_PARAMS_H_
#define CALLBACKAPI_CNDRV_PARAMS_H_

#include "cndrv_api.h"

#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
  unsigned int Flags;
} cnpapi_mluInit_params;


typedef struct {
  unsigned int Flags;
} cnpapi_mluExit_params;


typedef struct {
  int * count;
} cnpapi_mluGetDeviceCount_params;


typedef struct {
  MLUdev * dev;
  int ordinal;
} cnpapi_mluDeviceGet_params;


typedef struct {
  char * name;
  unsigned int len;
  MLUdev dev;
} cnpapi_mluDeviceGetName_params;


typedef struct {
  int * pi;
  MLUdevice_attribute attrib;
  MLUdev dev;
} cnpapi_mluDeviceGetAttribute_params;


typedef struct {
  MLUdev dev;
} cnpapi_mluDeviceOpen_params;


typedef struct {
  MLUdev dev;
} cnpapi_mluDeviceClose_params;


typedef struct {
  MLUdev dev;
  int * driverVersion;
} cnpapi_mluDriverGetVersion_params;


typedef struct {
  MLUresult error;
  const char ** pStr;
} cnpapi_mluGetErrorName_params;


typedef struct {
  MLUresult error;
  const char ** pStr;
} cnpapi_mluGetErrorString_params;


typedef struct {
  MLUdev dev;
  unsigned int * count;
} cnpapi_mluGetMaxQueueCount_params;


typedef struct {
  MLUdev dev;
  MLUqueue * phqueue;
  int flags;
} cnpapi_mluCreateQueue_params;


typedef struct {
  MLUdev dev;
  MLUqueue * phqueue;
  unsigned int flags;
  int priority;
} cnpapi_mluCreateQueueWithPriority_params;


typedef struct {
  MLUdev dev;
  MLUqueue hqueue;
} cnpapi_mluDestroyQueue_params;


typedef struct {
  MLUdev dev;
  MLUqueue hqueue;
} cnpapi_mluQueryQueue_params;


typedef struct {
  MLUdev dev;
  MLUqueue hqueue;
} cnpapi_mluQueueSync_params;


typedef struct {
  MLUdev dev;
  MLUqueue hqueue;
  MLUnotifier hnotifier;
} cnpapi_mluQueueWaitNotifier_params;


typedef struct {
  MLUdev dev;
  MLUnotifier * phnotifier;
  unsigned int flags;
} cnpapi_mluCreateNotifier_params;


typedef struct {
  MLUdev dev;
  MLUnotifier hnotifier;
} cnpapi_mluDestroyNotifier_params;


typedef struct {
  MLUdev dev;
  MLUnotifier hnotifier;
} cnpapi_mluWaitNotifier_params;


typedef struct {
  MLUdev dev;
  MLUnotifier hnotifier;
} cnpapi_mluQueryNotifier_params;


typedef struct {
  MLUdev dev;
  MLUnotifier hnotifier;
  MLUqueue hqueue;
} cnpapi_mluPlaceNotifyNotifier_params;


typedef struct {
  MLUdev dev;
  struct timeval * ptv;
  MLUnotifier hstart;
  MLUnotifier hend;
} cnpapi_mluNotifierElapsedTime_params;


typedef struct {
  MLUdev dev;
  MLUaddr mlu_addr;
  const HOSTaddr host_addr;
  uint64_t size;
  MLUqueue hqueue;
} cnpapi_mluMemcpyHtoDAsync_params;


typedef struct {
  MLUdev dev;
  MLUaddr mlu_addr;
  const HOSTaddr host_addr;
  uint64_t size;
  MLUqueue hqueue;
} cnpapi_mluMemcpyDtoHAsync_params;


typedef struct {
  MLUdev dev;
  MLUaddr dst_addr;
  MLUaddr src_addr;
  uint64_t size;
  MLUqueue hqueue;
} cnpapi_mluMemcpyPeerAsync_params;


typedef struct {
  MLUdev dev;
  MLUaddr dst_addr;
  MLUaddr src_addr;
  MLUqueue hqueue;
  uint64_t size;
} cnpapi_mluMemcpyPeer2PeerAsync_params;


typedef struct {
  MLUdev dev;
  MLUIpcNotifierHandle * pHandle;
  MLUnotifier notifier;
  unsigned int flag;
} cnpapi_mluIpcGetNotifierHandle_params;


typedef struct {
  MLUdev dev;
  MLUIpcNotifierHandle Handle;
  MLUnotifier * pnotifier;
  unsigned int flag;
} cnpapi_mluIpcOpenNotifierHandle_params;


typedef struct {
  HOSTaddr * addr;
  unsigned int size;
} cnpapi_mluMallocHost_params;


typedef struct {
  HOSTaddr addr;
} cnpapi_mluFreeHost_params;


typedef struct {
  MLUdev dev;
  uint64_t * bytes;
} cnpapi_mluDeviceTotalMem_params;


typedef struct {
  MLUaddr * mlu_addr;
  MLUdev dev;
  uint64_t size;
  uint64_t alignment;
  unsigned int channel;
} cnpapi_mluMalloc_params;


typedef struct {
  MLUaddr mlu_addr;
  MLUdev dev;
  int value;
  uint64_t size;
} cnpapi_mluMemset_params;


typedef struct {
  MLUaddr * mlu_addr;
  MLUdev dev;
  uint64_t size;
  uint64_t alignment;
  unsigned int channel;
} cnpapi_mluZmalloc_params;


typedef struct {
  MLUaddr * mlu_addr;
  MLUdev dev;
  uint64_t size;
  uint64_t alignment;
  unsigned int channel;
} cnpapi_mluMallocConstant_params;


typedef struct {
  MLUaddr * mlu_addr;
  MLUdev dev;
  uint64_t size;
  uint64_t alignment;
  unsigned int channel;
} cnpapi_mluMallocFrameBuffer_params;


typedef struct {
  MLUaddr * mluMerge_addr;
  MLUdev dev;
  unsigned int count;
  const MLUaddr * mlu_addrs;
} cnpapi_mluMemMerge_params;


typedef struct {
  MLUdev dev;
  MLUaddr mlu_addr;
} cnpapi_mluFree_params;


typedef struct {
  MLUdev dev;
  MLUaddr mlu_addr;
  const HOSTaddr host_addr;
  uint64_t size;
} cnpapi_mluMemcpyHtoD_params;


typedef struct {
  MLUdev dev;
  const MLUaddr mlu_addr;
  HOSTaddr host_addr;
  uint64_t size;
} cnpapi_mluMemcpyDtoH_params;


typedef struct {
  MLUdev devSrc;
  MLUdev devDst;
} cnpapi_mluMemcpyPeerAble_params;


typedef struct {
  MLUdev dev;
  MLUaddr dst_addr;
  MLUaddr src_addr;
  uint64_t size;
} cnpapi_mluMemcpyPeer2Peer_params;


typedef struct {
  MLUdev dev;
  MLUaddr src_addr;
  MLUaddr dst_addr;
  uint64_t size;
} cnpapi_mluMemcpyDtoD_params;


typedef struct {
  MLUdev dev;
  MLUIpcMemHandle * pHandle;
  MLUaddr addr;
} cnpapi_mluIpcGetMemHandle_params;


typedef struct {
  MLUdev dev;
  MLUaddr * pdptr;
  MLUIpcMemHandle handle;
  unsigned int flag;
} cnpapi_mluIpcOpenMemHandle_params;


typedef struct {
  MLUdev dev;
  MLUaddr dptr;
} cnpapi_mluIpcCloseMemHandle_params;


#ifdef __cplusplus
}
#endif

#endif
