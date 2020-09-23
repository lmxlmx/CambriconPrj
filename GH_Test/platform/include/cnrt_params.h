#ifndef CALLBACKAPI_CNRT_PARAMS_H_
#define CALLBACKAPI_CNRT_PARAMS_H_

#include "cnrt.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
  void * param;
  char * name;
  int len;
  void * data;
} cnpapi_cnrtAddParam_params;


typedef struct {
  void ** pParam;
} cnpapi_cnrtAllocParam_params;


typedef struct {
  int dev_ordinal;
} cnpapi_cnrtClearCurrentThreadAffinity_params;


typedef struct {
  uint16_t * f16;
  double x;
} cnpapi_cnrtConvertDoubleToHalf_params;


typedef struct {
  uint16_t * f16;
  float d;
} cnpapi_cnrtConvertFloatToHalf_params;


typedef struct {
  double * d;
  uint16_t f16;
} cnpapi_cnrtConvertHalfToDouble_params;


typedef struct {
  float * d;
  uint16_t f16;
} cnpapi_cnrtConvertHalfToFloat_params;


typedef struct {
  cnrtFunction_t * dst;
  cnrtFunction_t src;
} cnpapi_cnrtCopyFunction_params;


typedef struct {
  cnrtKernelParamsBuffer_t dst_params_buf;
  cnrtKernelParamsBuffer_t src_params_buf;
} cnpapi_cnrtCopyKernelParamsBuffer_params;


typedef struct {
  cnrtFunction_t * pfunction;
} cnpapi_cnrtCreateFunction_params;


typedef struct {
  cnrtNotifier_t * notifier;
} cnpapi_cnrtCreateNotifier_params;


typedef struct {
  cnrtQueue_t * pQueue;
} cnpapi_cnrtCreateQueue_params;


typedef struct {
  cnrtRuntimeContext_t * pctx;
  cnrtFunction_t src_func;
  void * extra;
} cnpapi_cnrtCreateRuntimeContext_params;


typedef struct {
} cnpapi_cnrtDestroy_params;

typedef struct {
  void * param;
} cnpapi_cnrtDestoryParam_params;




typedef struct {
  cnrtFunction_t function;
} cnpapi_cnrtDestroyFunction_params;


typedef struct {
  cnrtKernelParamsBuffer_t params;
} cnpapi_cnrtDestroyKernelParamsBuffer_params;


typedef struct {
  cnrtNotifier_t * notifier;
} cnpapi_cnrtDestroyNotifier_params;


typedef struct {
  cnrtQueue_t queue;
} cnpapi_cnrtDestroyQueue_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
} cnpapi_cnrtDestroyRuntimeContext_params;


typedef struct {
  cnrtFunction_t * pfunction;
  cnrtModel_t model;
  const char * symbol;
} cnpapi_cnrtExtractFunction_params;


typedef struct {
  void * dst;
  void * src;
  int n;
  int h;
  int w;
  int c;
  cnrtDataType_t type;
} cnpapi_cnrtFilterReshape_params;


typedef struct {
  void * ptr;
} cnpapi_cnrtFree_params;


typedef struct {
  void ** ptr;
  int length;
} cnpapi_cnrtFreeArray_params;


typedef struct {
  void * ptr;
} cnpapi_cnrtFreeHost_params;


typedef struct {
  cnrtChannelType_t * pChannel;
} cnpapi_cnrtGetCurrentChannel_params;


typedef struct {
  cnrtDev_t * dev;
} cnpapi_cnrtGetCurrentDevice_params;



typedef struct {
  cnrtDeviceAffinity_t * affinity;
  int dev_ordinal;
} cnpapi_cnrtGetDeviceAffinity_params;


typedef struct {
  unsigned int * dev_num;
} cnpapi_cnrtGetDeviceCount_params;


typedef struct {
  cnrtDev_t * pdev;
  int ordinal;
} cnpapi_cnrtGetDeviceHandle_params;


typedef struct {
  cnrtFunction_t function;
  int64_t * pMemused;
} cnpapi_cnrtGetFunctionMemUsed_params;


typedef struct {
  cnrtModel_t model;
  int * func_num;
} cnpapi_cnrtGetFunctionNumber_params;




typedef struct {
  cnrtKernelParamsBuffer_t * params;
} cnpapi_cnrtGetKernelParamsBuffer_params;


typedef struct {
  cnrtModel_t model;
  int64_t * pMemused;
} cnpapi_cnrtGetModelMemUsed_params;


typedef struct {
  const char * fname;
  int * size;
} cnpapi_cnrtGetModelSize_params;


typedef struct {
  void * param;
  char * name;
  void * out;
  int outlen;
} cnpapi_cnrtGetParam_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  cnrtRuntimeContextInfo_t key;
  void ** out;
} cnpapi_cnrtGetRuntimeContextInfo_params;


typedef struct {
  unsigned int * pStacksize;
} cnpapi_cnrtGetStackMem_params;


typedef struct {
  unsigned int * ver;
} cnpapi_cnrtGetVersion_params;


typedef struct {
  unsigned int flags;
} cnpapi_cnrtInit_params;


typedef struct {
  cnrtFunction_t function;
  void ** const_addr;
} cnpapi_cnrtInitFunctionConstMemory_params;


typedef struct {
  cnrtFunction_t function;
  void ** intmd_addr;
  int dataParallelism;
} cnpapi_cnrtInitFunctionIntmdMemory_params;


typedef struct {
  cnrtFunction_t function;
  cnrtFunctionType_t func_type;
} cnpapi_cnrtInitFunctionMemory_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  void * extra;
} cnpapi_cnrtInitRuntimeContext_params;


typedef struct {
  cnrtFunction_t function;
  cnrtDim3_t dim;
  void ** params;
  cnrtFunctionType_t func_type;
  cnrtQueue_t queue;
  void * extra_param;
} cnpapi_cnrtInvokeFunction_V2_params;


typedef struct {
  const void * function;
  cnrtDim3_t dim;
  cnrtKernelParamsBuffer_t params;
  cnrtFunctionType_t func_type;
  cnrtQueue_t queue;
} cnpapi_cnrtInvokeKernel_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  void ** params;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnrtInvokeRuntimeContext_params;


typedef struct {
  cnrtKernelParamsBuffer_t params;
  void * data;
  size_t bytes;
} cnpapi_cnrtKernelParamsBufferAddParam_params;


typedef struct {
  cnrtKernelParamsBuffer_t params;
} cnpapi_cnrtKernelParamsBufferMarkInput_params;


typedef struct {
  cnrtKernelParamsBuffer_t params;
} cnpapi_cnrtKernelParamsBufferMarkOutput_params;


typedef struct {
  cnrtKernelParamsBuffer_t params;
} cnpapi_cnrtKernelParamsBufferMarkStatic_params;


typedef struct {
  cnrtModel_t * pmodel;
  const char * fname;
} cnpapi_cnrtLoadModel_params;


typedef struct {
  cnrtModel_t * pmodel;
  char * ptr;
} cnpapi_cnrtLoadModelFromMem_params;


typedef struct {
  void ** pPtr;
  size_t bytes;
} cnpapi_cnrtMalloc_params;


typedef struct {
  void ** pPtr;
  size_t bytes;
  int dataParallelism;
} cnpapi_cnrtMallocBatch_params;


typedef struct {
  void ** pPtr;
  void * param;
} cnpapi_cnrtMallocBufferEx_params;


typedef struct {
  void ** pPtr;
  size_t bytes;
} cnpapi_cnrtMallocFrameBuffer_params;


typedef struct {
  void ** pPtr;
  size_t bytes;
  cnrtMemType_t type;
} cnpapi_cnrtMallocHost_params;


typedef struct {
  void * dest;
  void * src;
  size_t bytes;
  cnrtMemTransDir_t dir;
} cnpapi_cnrtMemcpy_params;


typedef struct {
  void * dest;
  void * src;
  size_t bytes;
  int dataParallelism;
  cnrtMemTransDir_t dir;
} cnpapi_cnrtMemcpyBatch_params;


typedef struct {
  void * ptr;
  int c;
  size_t bytes;
} cnpapi_cnrtMemset_params;


typedef struct {
  cnrtNotifier_t start;
  cnrtNotifier_t end;
  float * us;
} cnpapi_cnrtNotifierDuration_params;


typedef struct {
  cnrtNotifier_t notifier;
  cnrtQueue_t queue;
} cnpapi_cnrtPlaceNotifier_params;


typedef struct {
  cnrtModel_t model;
  cnrtCoreVersion_t * coreVersion;
} cnpapi_cnrtQueryCoreVersion_params;


typedef struct {
  cnrtModel_t model;
  int * modelParallelism;
} cnpapi_cnrtQueryModelParallelism_params;


typedef struct {
  cnrtModel_t model;
  uint64_t * stack_size;
} cnpapi_cnrtQueryModelStackSize_params;


typedef struct {
  void * dst;
  void * src;
  int n;
  int h;
  int w;
  int c;
  cnrtDataType_t type;
} cnpapi_cnrtReshapeNCHWToNHWC_params;


typedef struct {
  void * dst;
  void * src;
  int n;
  int h;
  int w;
  int c;
  cnrtDataType_t type;
} cnpapi_cnrtReshapeNHWCToNCHW_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  cnrtQueue_t * queue;
} cnpapi_cnrtRuntimeContextCreateQueue_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  cnrtQueue_t queue;
} cnpapi_cnrtRuntimeContextDestroyQueue_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  void * ptr;
} cnpapi_cnrtRuntimeContextFree_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  void ** ptr;
  int length;
} cnpapi_cnrtRuntimeContextFreeArray_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  cnrtQueue_t queue;
} cnpapi_cnrtRuntimeContextSyncQueue_params;


typedef struct {
  cnrtChannelType_t channel;
} cnpapi_cnrtSetCurrentChannel_params;


typedef struct {
  cnrtDev_t dev;
} cnpapi_cnrtSetCurrentDevice_params;


typedef struct {
  int dev_ordinal;
} cnpapi_cnrtSetCurrentThreadAffinity_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  cnrtChannelType_t channel;
} cnpapi_cnrtSetRuntimeContextChannel_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  int data_parallelism;
} cnpapi_cnrtSetRuntimeContextDataParallelism_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  int dev_ordinal;
} cnpapi_cnrtSetRuntimeContextDeviceId_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  bool enabled;
} cnpapi_cnrtSetRuntimeContextInstConstShareble_params;


typedef struct {
  unsigned int stacksize;
} cnpapi_cnrtSetStackMem_params;


typedef struct {
  cnrtQueue_t queue;
} cnpapi_cnrtSyncQueue_params;


typedef struct {
  int cpuid;
  uint64_t * count;
  uint64_t * ordinal_array;
} cnpapi_cnrtTopologyGetCpuRelatedDevices_params;


typedef struct {
  cnrtTopologyRelationshipEnum_t relationship;
  uint64_t * count;
  uint64_t * ordinal_array;
  int dev_ordinal;
} cnpapi_cnrtTopologyGetNearestDevices_params;


typedef struct {
  cnrtTopologyRelationshipEnum_t * relationship;
  int dev_ordinal1;
  int dev_ordinal2;
} cnpapi_cnrtTopologyGetRelationship_params;


typedef struct {
  cnrtModel_t model;
} cnpapi_cnrtUnloadModel_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  cnrtParamDesc_t * param_descs;
  void ** param_buffers;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnrtInvokeRuntimeContext_V2_params;
typedef struct {
  cnrtParamDesc_t * param_desc;
} cnpapi_cnrtCreateParamDesc_params;


typedef struct {
  cnrtParamDescArray_t * param_descs;
  int param_num;
} cnpapi_cnrtCreateParamDescArray_params;


typedef struct {
  cnrtParamDesc_t param_desc;
} cnpapi_cnrtDestroyParamDesc_params;


typedef struct {
  cnrtParamDescArray_t param_descs;
  int param_num;
} cnpapi_cnrtDestroyParamDescArray_params;


typedef struct {
  cnrtParamDesc_t param_desc;
  int * dims;
  int dim_num;
} cnpapi_cnrtSetShapeToParamDesc_params;


typedef struct {
  cnrtParamDesc_t param_desc;
  char * name;
  int name_size;
} cnpapi_cnrtSetNameToParamDesc_params;


typedef struct {
  cnrtParamDesc_t param_desc;
  cnrtDataType_t dtype;
} cnpapi_cnrtSetDataTypeToParamDesc_params;


typedef struct {
  cnrtParamDesc_t param_desc;
  int ** dims;
  int * dim_num;
} cnpapi_cnrtGetShapeFromParamDesc_params;


typedef struct {
  cnrtParamDesc_t param_desc;
  char ** name;
  int * name_size;
} cnpapi_cnrtGetNameFromParamDesc_params;


typedef struct {
  cnrtParamDesc_t param_desc;
  int * id;
} cnpapi_cnrtGetIdFromParamDesc_params;


typedef struct {
  cnrtParamDesc_t param_desc;
  cnrtDataType_t * dtype;
} cnpapi_cnrtGetDataTypeFromParamDesc_params;


typedef struct {
  cnrtParamDesc_t param_desc;
  cnrtDimOrder_t * dim_order;
} cnpapi_cnrtGetDimOrderFromParamDesc_params;


typedef struct {
  cnrtParamDesc_t param_desc;
  size_t * num;
} cnpapi_cnrtGetParamElementNum_params;


typedef struct {
  cnrtParamDesc_t param_desc;
  int64_t * size;
} cnpapi_cnrtGetParamDescSize_params;


typedef struct {
  cnrtParamDesc_t * param_desc;
  cnrtParamDescArray_t param_descs;
  int param_num;
  const char * name;
} cnpapi_cnrtGetParamDescFromParamDescArrayByName_params;


typedef struct {
  int * index;
  cnrtParamDescArray_t param_descs;
  int param_num;
  const char * name;
} cnpapi_cnrtGetIndexFromParamDescArrayByName_params;


typedef struct {
  void * src_addr;
  cnrtDataType_t data_type;
  void * dst_addr;
  int dimNum;
  int* dimValues;
  int* dimOrder;
} cnpapi_cnrtTransDataOrder_params;


typedef struct {
  void * src_addr;
  cnrtDataType_t src_type;
  void * dst_addr;
  cnrtDataType_t dst_type;
  cnrtQuantizedParam_t param;
  int dimNum;
  int* dimValues;
  int* dimOrder;
} cnpapi_cnrtTransOrderAndCast_params;


typedef struct {
  int64_t ** sizeArray;
  int * num;
  cnrtFunction_t function;
} cnpapi_cnrtGetOutputDataSize_params;


typedef struct {
  int64_t ** sizeArray;
  int * num;
  cnrtFunction_t function;
} cnpapi_cnrtGetInputDataSize_params;


typedef struct {
  cnrtDataType_t ** dtypes;
  int * num;
  cnrtFunction_t function;
} cnpapi_cnrtGetOutputDataType_params;


typedef struct {
  cnrtDataType_t ** dtypes;
  int * num;
  cnrtFunction_t function;
} cnpapi_cnrtGetInputDataType_params;


typedef struct {
  int ** dimValues;
  int * dimNum;
  int index;
  cnrtFunction_t function;
} cnpapi_cnrtGetInputDataShape_params;


typedef struct {
  int ** dimValues;
  int * dimNum;
  int index;
  cnrtFunction_t function;
} cnpapi_cnrtGetOutputDataShape_params;


typedef struct {
  void * src_addr;
  cnrtDataType_t src_data_type;
  void * dst_addr;
  cnrtDataType_t dst_data_type;
  int data_num;
  cnrtQuantizedParam_t param;
} cnpapi_cnrtCastDataType_params;


typedef struct {
  cnrtQuantizedParam_t * param;
  int pos;
  float scale;
  int offset;
} cnpapi_cnrtCreateQuantizedParam_params;


typedef struct {
  cnrtQuantizedParam_t * param;
  int * poses;
  float * scales;
  float * offsets;
  int dimNum;
  int * dimValues;
  int channelDim;
} cnpapi_cnrtCreateQuantizedParamByChannel_params;


typedef struct {
  cnrtQuantizedParam_t param;
} cnpapi_cnrtDestroyQuantizedParam_params;


typedef struct {
  void * src_addr;
  cnrtDataType_t data_type;
  void * dst_addr;
  int dimNum;
  int * dimValues;
  int * dimStride;
} cnpapi_cnrtAddDataStride_params;


typedef struct {
  cnrtNotifier_t notifier;
} cnpapi_cnrtWaitNotifier_params;


typedef struct {
  cnrtNotifier_t notifier;
} cnpapi_cnrtQueryNotifier_params;


typedef struct {
  cnrtNotifier_t notifier;
  cnrtQueue_t queue;
  unsigned int flag;
} cnpapi_cnrtQueueWaitNotifier_params;


typedef struct {
  cnrtModel_t model;
  uint64_t * local_mem_size;
} cnpapi_cnrtQueryModelLocalMemSize_params;


typedef struct {
  const char * fname;
  int * model_level;
} cnpapi_cnrtGetModelLevelFromFile_params;


typedef struct {
  void ** host_ptr;
  void * dev_ptr;
} cnpapi_cnrtMap_params;


typedef struct {
  void * host_ptr;
} cnpapi_cnrtUnmap_params;


typedef struct {
  void * mappped_host_ptr;
  void ** dev_ptr;
} cnpapi_cnrtFindDevAddrByMappedAddr_params;


typedef struct {
  void * host_ptr;
  cnrtCacheOps_t opr;
} cnpapi_cnrtCacheOperation_params;


typedef struct {
  unsigned int local_mem_size;
} cnpapi_cnrtSetLocalMem_params;


typedef struct {
  unsigned int * pLocalsize;
} cnpapi_cnrtGetLocalMem_params;


typedef struct {
  unsigned int * canPeer;
  int Dev;
  int PeerDev;
} cnpapi_cnrtGetPeerAccessibility_params;


typedef struct {
  void * dst;
  int dstDevice;
  void * src;
  int srcDevice;
  size_t count;
} cnpapi_cnrtMemcpyPeer_params;


typedef struct {
  cnrtIpcMemHandle * handle;
  void * devPtr;
} cnpapi_cnrtAcquireMemHandle_params;


typedef struct {
  void ** devPtr;
  cnrtIpcMemHandle handle;
  int flag;
} cnpapi_cnrtMapMemHandle_params;


typedef struct {
  void * devPtr;
} cnpapi_cnrtUnMapMemHandle_params;


typedef struct {
  void * dest_addr;
  void * src_addr;
  size_t bytes;
  cnrtQueue_t queue;
  cnrtMemTransDir_t dir;
} cnpapi_cnrtMemcpyAsync_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
} cnpapi_cnrtSetCurrentContextDevice_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  void *** ptr;
  size_t * bytesArray;
  int length;
} cnpapi_cnrtRuntimeContextMallocBySizeArray_params;


typedef struct {
  cnrtRuntimeContext_t pctx;
  cnrtNotifier_t * pnotifier;
} cnpapi_cnrtRuntimeContextCreateNotifier_params;


typedef struct {
  cnrtKernelInitParam_t * param;
} cnpapi_cnrtCreateKernelInitParam_params;


typedef struct {
  cnrtKernelInitParam_t param;
} cnpapi_cnrtDestroyKernelInitParamAndMemory_params;


typedef struct {
  const void * function;
  cnrtKernelInitParam_t init_param;
} cnpapi_cnrtInitKernelMemory_params;


typedef struct {
  const void * function;
  cnrtKernelInitParam_t init_param;
  cnrtDim3_t dim;
  cnrtKernelParamsBuffer_t params;
  cnrtFunctionType_t func_type;
  cnrtQueue_t queue;
  void * extra_param;
} cnpapi_cnrtInvokeKernel_V3_params;


typedef struct {
  const void * function;
  cnrtDim3_t dim;
  cnrtKernelParamsBuffer_t params;
  cnrtFunctionType_t func_type;
  cnrtQueue_t queue;
} cnpapi_cnrtInvokeKernel_V2_params;


typedef struct {
  cnrtDeviceInfo_t * info;
  int device_ordinal;
} cnpapi_cnrtGetDeviceInfo_params;


typedef struct {
  cnrtFunction_t func;
  int input_num;
  cnrtParamDescArray_t input_params;
  int output_num;
  cnrtParamDescArray_t output_params;
} cnpapi_cnrtInferFunctionOutputShape_params;


typedef struct {
  cnrtFunction_t func;
  const char * name;
  int * index;
} cnpapi_cnrtGetParamIndexByName_params;


typedef struct {
  cnrtFunction_t func;
  const char * name;
  int * dim_shape;
} cnpapi_cnrtGetSupportedParamShapeByName_params;


typedef struct {
  cnrtFunction_t func;
  const char * name;
  int * dim_num;
} cnpapi_cnrtGetSupportedParamDimNumberByName_params;


typedef struct {
  cnrtFunction_t func;
  const char * name;
  cnrtDataType_t * dtype;
} cnpapi_cnrtGetSupportedParamDataTypeByName_params;


typedef struct {
  cnrtFunction_t func;
  const char * name;
  cnrtDimOrder_t * dorder;
} cnpapi_cnrtGetSupportedParamLayoutByName_params;


#ifdef __cplusplus
}
#endif

#endif
