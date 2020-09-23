#ifndef CALLBACKAPI_CNML_PARAMS_H_
#define CALLBACKAPI_CNML_PARAMS_H_

#include "cnml.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
  cnmlModel_t model;
  cnmlBaseOp_t op;
  const char * symbol;
} cnpapi_cnmlAddBaseOpToModel_params;


typedef struct {
  cnmlFusionOp_t op;
  cnmlTensor_t input;
} cnpapi_cnmlAddFusionInput_params;


typedef struct {
  cnmlModel_t model;
  cnmlFusionOp_t op;
  const char * symbol;
} cnpapi_cnmlAddFusionOpToModel_params;


typedef struct {
  cnmlFusionOp_t op;
  cnmlTensor_t output;
} cnpapi_cnmlAddFusionOutput_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t* masks;
} cnpapi_cnmlAddLSTMMask_params;


typedef struct {
  cnmlTensor_t tensor;
  cnmlCpuTensor_t cpu_tensor;
  void * cpu_tensor_ptr;
} cnpapi_cnmlBindConstData_params;


typedef struct {
  cnmlTensor_t tensor;
  void * cpu_tensor_ptr;
  bool free_after_binding;
} cnpapi_cnmlBindConstData_V2_params;


typedef struct {
  cnmlTensor_t tensor;
  cnmlCpuTensor_t twinsCpuTensor;
} cnpapi_cnmlBindCpuDataInfo_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlCoreVersion_t version;
} cnpapi_cnmlCheckBaseOpRunnable_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlCoreVersion_t version;
  int core_num;
} cnpapi_cnmlCompileBaseOp_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlCompileBaseOp_V2_params;


typedef struct {
  cnmlFusionOp_t op;
  cnmlCoreVersion_t version;
  int core_num;
} cnpapi_cnmlCompileFusionOp_params;


typedef struct {
  cnmlFusionOp_t op;
} cnpapi_cnmlCompileFusionOp_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeAbsOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeAbsOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeActiveOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeActiveOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeAddOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeAddOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeAddPadChannelOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeAddPadChannelOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeAddPadOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeAddPadOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeAndOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeAndOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeArgmaxOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeArgmaxOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeArgminOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeAvgOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeAvgOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputX;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeAxOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor_A;
  void * input_A;
  cnmlTensor_t input_tensor_X;
  void * input_X;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeAxOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputX;
  void * inputB;
  void * inputY;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeAxpByOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor_A;
  void * input_A;
  cnmlTensor_t input_tensor_X;
  void * input_X;
  cnmlTensor_t input_tensor_B;
  void * input_B;
  cnmlTensor_t input_tensor_Y;
  void * input_Y;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeAxpByOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputX;
  void * inputY;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeAxpyOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor_A;
  void * input_A;
  cnmlTensor_t input_tensor_X;
  void * input_X;
  cnmlTensor_t input_tensor_Y;
  void * input_Y;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeAxpyOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void ** input_state;
  void * output;
  void ** state_output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeBasicRNNProOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t* input_state_tensor;
  void ** input_state;
  cnmlTensor_t output_tensor;
  void * output;
  cnmlTensor_t* state_output_tensor;
  void ** state_output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeBasicRNNProOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeBatch2spaceOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeBatch2spaceOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeBatchDotOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeBatchDotOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeBatchNormOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeBatchNormOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeBroadcastAddOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeBroadcastAddOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeBroadcastLesserOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input1_tensor;
  void * input_1;
  cnmlTensor_t input2_tensor;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeBroadcastLesserOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeBroadcastMultOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input1_tensor;
  void * input_1;
  cnmlTensor_t input2_tensor;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeBroadcastMultOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeBroadcastOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeBroadcastOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeBroadcastSubOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input1_tensor;
  void * input_1;
  cnmlTensor_t input2_tensor;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeBroadcastSubOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCastOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCastOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input1;
  void * input2;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCaxpbyOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeClipOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeClipOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void ** inputs;
  int input_num;
  void ** outputs;
  int output_num;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeConcatOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t* input_tensors;
  void ** inputs;
  int input_num;
  cnmlTensor_t* output_tensors;
  void ** outputs;
  int output_num;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeConcatOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeConvDepthwiseOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeConvDepthwiseOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeConvFirstOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeConvFirstOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeConvGroupOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeConvGroupOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeConvOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeConvOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCosOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCosOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputTensor1;
  void * inputTensor2;
  void * outputTensor;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeCosSimilarityOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input1_tensor;
  void * input1;
  cnmlTensor_t input2_tensor;
  void * input2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCosSimilarityOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCropOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCropOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCustomizedActiveForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCustomizedActiveForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleAddOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleAddOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleAndOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleAndOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleEqualOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleEqualOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleGreaterEqualOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleGreaterEqualOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleGreaterOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleGreaterOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleLessEqualOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleLessEqualOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleLessOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleLessOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleMaxEqualOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleMaxEqualOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleMinEqualOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleMinEqualOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleMultOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleMultOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleNEqualOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleNEqualOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleOrOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleOrOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleSubOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleSubOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeCycleXorOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeCycleXorOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeDeconvOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeDeconvOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t t_queue;
} cnpapi_cnmlComputeDeconvGroupOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeDeconvGroupOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeDeviceMemcpyOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeDeviceMemcpyOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeDivSqrtDimOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeDivSqrtDimOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * inputC;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeDyadicSelectOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t input_tensor3;
  void * input_3;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeDyadicSelectOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void ** indices_cnml_ptr;
  void ** data_cnml_ptr;
  int tensor_num_in_list;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeDynamicStitchOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeEluOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeEluOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeEmbeddingOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeEmbeddingOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeEqualOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor_A;
  void * inputA;
  cnmlTensor_t input_tensor_B;
  void * inputB;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeEqualOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeErfOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeErfOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeExpOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeExpOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeFloorDivOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputTensor1;
  void * inputTensor2;
  void * outputTensor;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeFloorModOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeFloorOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeFloorOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeFrozenBatchNormOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeFrozenBatchNormOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * mom_mean;
  void * mom_var;
  void * gamma;
  void * beta;
  void * output;
  void * mom_mean_out;
  void * mom_var_out;
  void * mean;
  void * var;
  void * bn_out;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeFusedBatchNormOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * es_mean;
  void * es_var;
  void * gamma;
  void * beta;
  void * output;
  void * batch_mean;
  void * batch_var;
  void * mean;
  void * var;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeFusedBatchNormOpForward_V2_params;


typedef struct {
  cnmlFusionOp_t op;
  void ** inputs;
  int inputNum;
  void ** outputs;
  int outputNum;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
  void * inst_addr;
  void * const_addr;
  void * intmd_addr;
} cnpapi_cnmlComputeFusionOpForwardExtra_V2_params;


typedef struct {
  cnmlFusionOp_t op;
  void ** inputs;
  int inputNum;
  void ** outputs;
  int outputNum;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeFusionOpForward_V3_params;


typedef struct {
  cnmlFusionOp_t op;
  cnmlTensor_t* input_tensors;
  void ** inputs;
  int inputNum;
  cnmlTensor_t* output_tensors;
  void ** outputs;
  int outputNum;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeFusionOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void ** state_input;
  void * output;
  void ** state_output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeGRUOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t* state_input_tensors;
  void ** state_input;
  cnmlTensor_t output_tensors;
  void * output;
  cnmlTensor_t* state_output_tensors;
  void ** state_output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeGRUOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void ** state_input;
  void * output;
  void ** state_output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeGRUProOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t* state_input_tensors;
  void ** state_input;
  cnmlTensor_t output_tensor;
  void * output;
  cnmlTensor_t* state_output_tensors;
  void ** state_output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeGRUProOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * index;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeGatherV2OpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t index_tensor;
  void * index;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeGatherV2OpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeGreaterEqualOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor_A;
  void * inputA;
  cnmlTensor_t input_tensor_B;
  void * inputB;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeGreaterEqualOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeGreaterOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeGreaterOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeGrepChannelOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeGrepChannelOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeGrepOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeGrepOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeInterpOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeInterpOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeInvertPermutationOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * x;
  void ** hx;
  void ** cx;
  void ** mask;
  void * y;
  void ** hy;
  void ** cy;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeLSTMMaskProOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * x;
  void ** hx;
  void ** cx;
  void * y;
  void ** hy;
  void ** cy;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeLSTMProOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t x_tensor;
  void * x;
  cnmlTensor_t* hx_tensors;
  void ** hx;
  cnmlTensor_t* cx_tensors;
  void ** cx;
  cnmlTensor_t y_tensor;
  void * y;
  cnmlTensor_t* hy_tensors;
  void ** hy;
  cnmlTensor_t* cy_tensors;
  void ** cy;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeLSTMProOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * beta;
  void * gamma;
  void * output;
  void * mean;
  void * variance;
  void * norm_out;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeLayerNormOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeLessEqualOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeLessEqualOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeLessOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor_A;
  void * inputA;
  cnmlTensor_t input_tensor_B;
  void * inputB;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeLessOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeLog2OpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeLog2OpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeLogOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeLogOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeLogSoftmaxOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeLogSoftmaxOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeLrnOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeLrnOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * label;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeMaskZeroOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t label_tensor;
  void * label;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMaskZeroOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeMatrixBandPartOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * lhs;
  void * rhs;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeMatrixMultOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t lhs_tensor;
  void * lhs;
  cnmlTensor_t rhs_tensor;
  void * rhs;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMatrixMultOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeMaxEqualOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMaxEqualOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  void * index;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeMaxOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnmlTensor_t index_tensor;
  void * index;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMaxOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputTensor1;
  void * inputTensor2;
  void * outputTensor;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeMaximumOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMaximumOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeMinEqualOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMinEqualOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  void * index;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeMinOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnmlTensor_t index_tensor;
  void * index;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMinOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputTensor1;
  void * inputTensor2;
  void * outputTensor;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeMinimumOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMinimumOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeMinusOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMinusOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputs;
  void * outputs;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeMlpOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * inputs;
  cnmlTensor_t output_tensor;
  void * outputs;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMlpOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeMultOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeMultOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeNEqualOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNEqualOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeNdArgmaxOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdArgmaxOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdBatchNormOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputTensor;
  void * outputTensor;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeNdBroadcastOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdBroadcastOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void ** inputs;
  int input_num;
  void ** outputs;
  int output_num;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeNdConcatOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t* input_tensors;
  void ** inputs;
  int input_num;
  cnmlTensor_t* output_tensors;
  void ** outputs;
  int output_num;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdConcatOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleAddOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleAndOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleEqualOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleGreaterEqualOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleLessEqualOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleLessOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleMaxEqualOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleMinEqualOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleMultOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleOrOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleSubOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdCycleXorOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeNdLogSoftmaxOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdLogSoftmaxOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdPreluOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeNdReduceMaxOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdReduceMaxOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeNdReduceMeanOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdReduceMeanOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeNdReduceSumOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdReduceSumOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdScaleOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeNdSoftmaxOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdSoftmaxOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void ** inputs;
  int input_num;
  void ** outputs;
  int output_num;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeNdSplitOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t* input_tensors;
  void ** inputs;
  int input_num;
  cnmlTensor_t* output_tensors;
  void ** outputs;
  int output_num;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdSplitOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeNdStridedSliceOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdStridedSliceOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeNdTransposeProOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNdTransposeProOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeNearestNeighborOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNearestNeighborOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeNmsOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNmsOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  void * scale;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeNormalizeOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnmlTensor_t scale_tensor;
  void * scale;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNormalizeOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeNotOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeNotOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeOrOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeOrOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void ** inputTensors;
  int input_num;
  int axis;
  void * outputTensor;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputePackOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void ** input_ptrs;
  int input_num;
  void ** output_ptrs;
  int output_num;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputePluginOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t* input_tensors;
  void ** inputs;
  int input_num;
  cnmlTensor_t* output_tensors;
  void ** outputs;
  int output_num;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputePluginOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  void * index;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputePoolIndexOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputePoolOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputePoolOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputePowerOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputePowerOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputePreluOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputePreluOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * input_param;
  void * input_mp;
  void * output;
  void * output_param;
  void * output_mp;
  void * mode;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeQuantifyOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeRealDivOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeRealDivOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeReduceMaxOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeReduceMaxOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeReduceMeanOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeReduceMeanOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeReduceProductOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeReduceProductOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeReduceSumOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeReduceSumOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeReorgOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeReorgOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeReshapeOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeReshapeOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeReverseOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeReverseOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * y;
  void * dy;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeRsqrtGradOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeRsqrtOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeRsqrtOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * alpha;
  void * beta;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeScaleOpForwardUltra_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t alpha_tensor;
  void * alpha;
  cnmlTensor_t beta_tensor;
  void * beta;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeScaleOpForwardUltra_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeScaleOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeScaleOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * index;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeScatterOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeSeluOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSeluOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSequenceMaskOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forward_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeSetConstOpBackward_params;


typedef struct {
  cnmlBaseOp_t op;
  void ** inputs;
  void ** outputs;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeShuffleChannelOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeShuffleChannelOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeSignOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeSinOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSinOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeSoftmaxOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSoftmaxOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * dw;
  void * dx;
  void * dy;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeSoftplusGradForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeSoftplusOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSoftplusOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t q;
} cnpapi_cnmlComputeSoftsignOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSoftsignOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeSpace2batchOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSpace2batchOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void ** inputs;
  int input_num;
  void ** outputs;
  int output_num;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeSplitOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t* input_tensors;
  void ** inputs;
  int input_num;
  cnmlTensor_t* output_tensors;
  void ** outputs;
  int output_num;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSplitOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeSqrtOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSqrtOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeSquareOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSquareOpForward_V2_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t inputTensor1;
  void * input1;
  cnmlTensor_t inputTensor2;
  void * input2;
  cnmlTensor_t outputTensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSquaredDiffOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeStdDevOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeStridedSliceOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeStridedSliceOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeSubOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeSubOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input_y;
  void * input_delta_y;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeTanhGradOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeThrsOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeThrsOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeTileOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  void * index;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeTopkOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnmlTensor_t index_tensor;
  void * index;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeTopkOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeTransposeProOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeTransposeProOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeTrilOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  void * count;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeUnarySelectOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnmlTensor_t count_tensor;
  void * count;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeUnarySelectOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputTensor;
  void * outputTensor;
  void * indexTensor;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t queue;
} cnpapi_cnmlComputeUniqueOpForward_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * index;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeUnpoolOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t index_tensor;
  void * index;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeUnpoolOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeVector2NormOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeVector2NormOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  void * count;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeWhereOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnmlTensor_t count_tensor;
  void * count;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeWhereOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * inputA;
  void * inputB;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeXorOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor1;
  void * input_1;
  cnmlTensor_t input_tensor2;
  void * input_2;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeXorOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forw_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeYUVtoGrayOpForward_V3_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t input_tensor;
  void * input;
  cnmlTensor_t output_tensor;
  void * output;
  cnrtQueue_t queue;
  void * extra;
} cnpapi_cnmlComputeYUVtoGrayOpForward_V4_params;


typedef struct {
  cnmlBaseOp_t op;
  void * input;
  void * output;
  cnrtInvokeFuncParam_t * compute_forward_param;
  cnrtQueue_t stream;
} cnpapi_cnmlComputeZeroOpBackward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeAbsOpForward_params;


typedef struct {
  cnmlActiveFunction_t fn;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeActiveOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeAddOpForward_params;


typedef struct {
  cnmlAddPadChannelOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeAddPadChannelOpForward_params;


typedef struct {
  cnmlAddPadOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeAddPadOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeAndOpForward_params;


typedef struct {
  cnmlDimension_t argmax_axis;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeArgmaxOpForward_params;


typedef struct {
  cnmlDimension_t argmin_axis;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeArgminOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeAvgOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeAxOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t input_tensor_3;
  void * input_3;
  cnmlCpuTensor_t input_tensor_4;
  void * input_4;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeAxpByOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t input_tensor_3;
  void * input_3;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeAxpyOpForward_params;


typedef struct {
  cnmlRNNOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t* state_input_tensor;
  void ** state_input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t* state_output_tensor;
  void ** state_output;
  cnmlCpuTensor_t* input_weight_tensor;
  void ** input_weight;
  cnmlCpuTensor_t* state_weight_tensor;
  void ** state_weight;
  cnmlCpuTensor_t* input_bias_tensor;
  void ** input_bias;
  cnmlCpuTensor_t* state_bias_tensor;
  void ** state_bias;
  cnmlActiveFunction_t active_func;
} cnpapi_cnmlCpuComputeBasicRNNProOpForward_params;


typedef struct {
  int w_block_size;
  int h_block_size;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeBatch2spaceOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensorA;
  void * inputA;
  cnmlCpuTensor_t input_tensorB;
  void * inputB;
  cnmlCpuTensor_t output_tensor;
  void * output;
  bool trans_a;
  bool trans_b;
} cnpapi_cnmlCpuComputeBatchDotOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlCpuTensor_t mean_tensor;
  void * mean_buf;
  cnmlCpuTensor_t var_tensor;
  void * var_buf;
} cnpapi_cnmlCpuComputeBatchNormOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeBroadcastAddOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeBroadcastLesserOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeBroadcastMultOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeBroadcastNdOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeBroadcastOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeBroadcastSubOpForward_params;


typedef struct {
  cnmlCastType_t fn;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCastOpForward_params;


typedef struct {
  cnmlCpuTensor_t input1_tensor;
  void * input1_buf;
  cnmlCpuTensor_t input2_tensor;
  void * input2_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  float alpha;
  float beta;
} cnpapi_cnmlCpuComputeCaxpbyOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  double lower_bound;
  double upper_bound;
} cnpapi_cnmlCpuComputeClipOpForward_params;


typedef struct {
  cnmlConcatOpParam_t param;
  cnmlCpuTensor_t * inputs_tensor_ptr;
  void ** inputs;
  int input_num;
  cnmlCpuTensor_t * outputs_tensor_ptr;
  void ** outputs;
  int output_num;
} cnpapi_cnmlCpuComputeConcatOpForward_params;


typedef struct {
  cnmlConvDepthwiseOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t filter_tensor;
  void * filter;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t bias_tensor;
  void * bias;
} cnpapi_cnmlCpuComputeConvDepthwiseOpForward_params;


typedef struct {
  cnmlConvFirstOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t mean_tensor;
  void * mean;
  cnmlCpuTensor_t filter_tensor;
  void * filter;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t bias_tensor;
  void * bias;
  cnmlCpuTensor_t stdt_tensor;
  void * stdt;
} cnpapi_cnmlCpuComputeConvFirstOpForward_params;


typedef struct {
  cnmlConvOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t filter_tensor;
  void * filter;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t bias_tensor;
  void * bias;
  int group;
} cnpapi_cnmlCpuComputeConvGroupOpForward_params;


typedef struct {
  cnmlConvOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t filter_tensor;
  void * filter;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t bias_tensor;
  void * bias;
} cnpapi_cnmlCpuComputeConvOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeCosOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCosSimilarityOpForward_params;


typedef struct {
  cnmlCropOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCropOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleAddOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleAndOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleGreaterEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleGreaterOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleLessEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleLessOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleMaxEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleMinEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleMultOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleNEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleOrOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleSubOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeCycleXorOpForward_params;


typedef struct {
  cnmlDeconvOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t filter_tensor;
  void * filter;
  cnmlCpuTensor_t output_tensor;
  void * output;
  int group;
  cnmlCpuTensor_t bias_tensor;
  void * bias;
} cnpapi_cnmlCpuComputeDeconvGroupOpForward_params;


typedef struct {
  cnmlDeconvOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t filter_tensor;
  void * filter;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t bias_tensor;
  void * bias;
} cnpapi_cnmlCpuComputeDeconvOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeDeviceMemcpyOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeDivSqrtDimOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t input_tensor_3;
  void * input_3;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeDyadicSelectOpForward_params;


typedef struct {
  int num_in_list;
  cnmlCpuTensor_t * inputTensorA;
  void ** indices;
  cnmlCpuTensor_t * inputTensorB;
  void ** data;
  cnmlCpuTensor_t output;
  void * outputs;
} cnpapi_cnmlCpuComputeDynamicStitchOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeEluOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlCpuTensor_t weight_tensor;
  void * weight_buf;
} cnpapi_cnmlCpuComputeEmbeddingOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeErfOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeExpOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeFloorDivOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeFloorModOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeFloorOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t filter_tensor;
  void * filter_buf;
  cnmlCpuTensor_t bias_tensor;
  void * bias_buf;
  cnmlCpuTensor_t mean_tensor;
  void * mean_buf;
  cnmlCpuTensor_t var_tensor;
  void * var_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeFrozenBatchNormOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t mom_mean_tensor;
  void * mom_mean_buf;
  cnmlCpuTensor_t mom_var_tensor;
  void * mom_var_buf;
  cnmlCpuTensor_t gamma_tensor;
  void * gamma_buf;
  cnmlCpuTensor_t beta_tensor;
  void * beta_buf;
  cnmlCpuTensor_t eps_tensor;
  void * eps_buf;
  float momentum;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlCpuTensor_t mom_mean_out_tensor;
  void * mom_mean_out_buf;
  cnmlCpuTensor_t mom_var_out_tensor;
  void * mom_var_out_buf;
  cnmlCpuTensor_t mean_tensor;
  void * mean_buf;
  cnmlCpuTensor_t var_tensor;
  void * var_buf;
  cnmlCpuTensor_t bn_tensor;
  void * bn_buf;
} cnpapi_cnmlCpuComputeFusedBatchNormOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t es_mean_tensor;
  void * es_mean_buf;
  cnmlCpuTensor_t es_var_tensor;
  void * es_var_buf;
  cnmlCpuTensor_t gamma_tensor;
  void * gamma_buf;
  cnmlCpuTensor_t beta_tensor;
  void * beta_buf;
  cnmlCpuTensor_t eps_tensor;
  void * eps_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlCpuTensor_t batch_mean_tensor;
  void * batch_mean_buf;
  cnmlCpuTensor_t batch_var_tensor;
  void * batch_var_buf;
  cnmlCpuTensor_t mean_tensor;
  void * mean_buf;
  cnmlCpuTensor_t var_tensor;
  void * var_buf;
} cnpapi_cnmlCpuComputeFusedBatchNormOpForward_V2_params;


typedef struct {
  cnmlRNNOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t* state_input_tensor;
  void ** state_input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t* state_output_tensor;
  void ** state_output;
  cnmlCpuTensor_t* rx_weight_tensor;
  void ** rx_weight;
  cnmlCpuTensor_t* rh_weight_tensor;
  void ** rh_weight;
  cnmlCpuTensor_t* rx_bias_tensor;
  void ** rx_bias;
  cnmlCpuTensor_t* rh_bias_tensor;
  void ** rh_bias;
  cnmlCpuTensor_t* zx_weight_tensor;
  void ** zx_weight;
  cnmlCpuTensor_t* zh_weight_tensor;
  void ** zh_weight;
  cnmlCpuTensor_t* zx_bias_tensor;
  void ** zx_bias;
  cnmlCpuTensor_t* zh_bias_tensor;
  void ** zh_bias;
  cnmlCpuTensor_t* nx_weight_tensor;
  void ** nx_weight;
  cnmlCpuTensor_t* nh_weight_tensor;
  void ** nh_weight;
  cnmlCpuTensor_t* nx_bias_tensor;
  void ** nx_bias;
  cnmlCpuTensor_t* nh_bias_tensor;
  void ** nh_bias;
} cnpapi_cnmlCpuComputeGRUOpForward_params;


typedef struct {
  cnmlRNNOpParam_t param;
  cnmlGRUMode_t gru_mode;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t* state_input_tensor;
  void ** state_input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t* state_output_tensor;
  void ** state_output;
  cnmlCpuTensor_t* rx_weight_tensor;
  void ** rx_weight;
  cnmlCpuTensor_t* rh_weight_tensor;
  void ** rh_weight;
  cnmlCpuTensor_t* rx_bias_tensor;
  void ** rx_bias;
  cnmlCpuTensor_t* rh_bias_tensor;
  void ** rh_bias;
  cnmlCpuTensor_t* zx_weight_tensor;
  void ** zx_weight;
  cnmlCpuTensor_t* zh_weight_tensor;
  void ** zh_weight;
  cnmlCpuTensor_t* zx_bias_tensor;
  void ** zx_bias;
  cnmlCpuTensor_t* zh_bias_tensor;
  void ** zh_bias;
  cnmlCpuTensor_t* nx_weight_tensor;
  void ** nx_weight;
  cnmlCpuTensor_t* nh_weight_tensor;
  void ** nh_weight;
  cnmlCpuTensor_t* nx_bias_tensor;
  void ** nx_bias;
  cnmlCpuTensor_t* nh_bias_tensor;
  void ** nh_bias;
} cnpapi_cnmlCpuComputeGRUProOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t index_tensor;
  void * index;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlDimension_t axies;
} cnpapi_cnmlCpuComputeGatherV2OpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeGreaterEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeGreaterOpForward_params;


typedef struct {
  cnmlGrepChannelOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeGrepChannelOpForward_params;


typedef struct {
  cnmlGrepOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeGrepOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlInterpOpParam_t param;
} cnpapi_cnmlCpuComputeInterpOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeInvertPermutationOpForward_params;


typedef struct {
  cnmlLSTMProParam_t lstm_pro_param;
  cnmlCpuTensor_t x;
  void * x_ptr;
  cnmlCpuTensor_t* hx;
  void ** hx_ptr;
  cnmlCpuTensor_t* cx;
  void ** cx_ptr;
  cnmlCpuTensor_t y;
  void * y_ptr;
  cnmlCpuTensor_t* hy;
  void ** hy_ptr;
  cnmlCpuTensor_t* cy;
  void ** cy_ptr;
  cnmlCpuTensor_t* filter_forget_x;
  void ** filter_forget_x_ptr;
  cnmlCpuTensor_t* filter_forget_h;
  void ** filter_forget_h_ptr;
  cnmlCpuTensor_t* filter_forget_c;
  void ** filter_forget_c_ptr;
  cnmlCpuTensor_t* bias_forget_x;
  void ** bias_forget_x_ptr;
  cnmlCpuTensor_t* bias_forget_h;
  void ** bias_forget_h_ptr;
  cnmlCpuTensor_t* filter_input_x;
  void ** filter_input_x_ptr;
  cnmlCpuTensor_t* filter_input_h;
  void ** filter_input_h_ptr;
  cnmlCpuTensor_t* filter_input_c;
  void ** filter_input_c_ptr;
  cnmlCpuTensor_t* bias_input_x;
  void ** bias_input_x_ptr;
  cnmlCpuTensor_t* bias_input_h;
  void ** bias_input_h_ptr;
  cnmlCpuTensor_t* filter_update_x;
  void ** filter_update_x_ptr;
  cnmlCpuTensor_t* filter_update_h;
  void ** filter_update_h_ptr;
  cnmlCpuTensor_t* bias_update_x;
  void ** bias_update_x_ptr;
  cnmlCpuTensor_t* bias_update_h;
  void ** bias_update_h_ptr;
  cnmlCpuTensor_t* filter_output_x;
  void ** filter_output_x_ptr;
  cnmlCpuTensor_t* filter_output_h;
  void ** filter_output_h_ptr;
  cnmlCpuTensor_t* filter_output_c;
  void ** filter_output_c_ptr;
  cnmlCpuTensor_t* bias_output_x;
  void ** bias_output_x_ptr;
  cnmlCpuTensor_t* bias_output_h;
  void ** bias_output_h_ptr;
  cnmlCpuTensor_t* filter_rec_proj;
  void ** filter_rec_proj_ptr;
  cnmlCpuTensor_t* bias_rec_proj;
  void ** bias_rec_proj_ptr;
  cnmlCpuTensor_t* filter_out_proj;
  void ** filter_out_proj_ptr;
  cnmlCpuTensor_t* bias_out_proj;
  void ** bias_out_proj_ptr;
} cnpapi_cnmlCpuComputeLSTMProOpForward_params;


typedef struct {
  cnmlLSTMProParam_t lstm_pro_param;
  cnmlCpuTensor_t x;
  void * x_ptr;
  cnmlCpuTensor_t* hx;
  void ** hx_ptr;
  cnmlCpuTensor_t* cx;
  void ** cx_ptr;
  cnmlCpuTensor_t y;
  void * y_ptr;
  cnmlCpuTensor_t* hy;
  void ** hy_ptr;
  cnmlCpuTensor_t* cy;
  void ** cy_ptr;
  cnmlCpuTensor_t* filter_forget_x;
  void ** filter_forget_x_ptr;
  cnmlCpuTensor_t* filter_forget_h;
  void ** filter_forget_h_ptr;
  cnmlCpuTensor_t* filter_forget_c;
  void ** filter_forget_c_ptr;
  cnmlCpuTensor_t* bias_forget_x;
  void ** bias_forget_x_ptr;
  cnmlCpuTensor_t* bias_forget_h;
  void ** bias_forget_h_ptr;
  cnmlCpuTensor_t* filter_input_x;
  void ** filter_input_x_ptr;
  cnmlCpuTensor_t* filter_input_h;
  void ** filter_input_h_ptr;
  cnmlCpuTensor_t* filter_input_c;
  void ** filter_input_c_ptr;
  cnmlCpuTensor_t* bias_input_x;
  void ** bias_input_x_ptr;
  cnmlCpuTensor_t* bias_input_h;
  void ** bias_input_h_ptr;
  cnmlCpuTensor_t* filter_update_x;
  void ** filter_update_x_ptr;
  cnmlCpuTensor_t* filter_update_h;
  void ** filter_update_h_ptr;
  cnmlCpuTensor_t* bias_update_x;
  void ** bias_update_x_ptr;
  cnmlCpuTensor_t* bias_update_h;
  void ** bias_update_h_ptr;
  cnmlCpuTensor_t* filter_output_x;
  void ** filter_output_x_ptr;
  cnmlCpuTensor_t* filter_output_h;
  void ** filter_output_h_ptr;
  cnmlCpuTensor_t* filter_output_c;
  void ** filter_output_c_ptr;
  cnmlCpuTensor_t* bias_output_x;
  void ** bias_output_x_ptr;
  cnmlCpuTensor_t* bias_output_h;
  void ** bias_output_h_ptr;
  cnmlCpuTensor_t* filter_rec_proj;
  void ** filter_rec_proj_ptr;
  cnmlCpuTensor_t* bias_rec_proj;
  void ** bias_rec_proj_ptr;
  cnmlCpuTensor_t* filter_out_proj;
  void ** filter_out_proj_ptr;
  cnmlCpuTensor_t* bias_out_proj;
  void ** bias_out_proj_ptr;
  cnmlCpuTensor_t* mask;
  void ** mask_ptr;
} cnpapi_cnmlCpuComputeLSTMProOpHasMaskForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t beta_tensor;
  void * beta_buf;
  cnmlCpuTensor_t gamma_tensor;
  void * gamma_buf;
  cnmlDimension_t axis;
  float epsilon;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlCpuTensor_t mean_tensor;
  void * mean_buf;
  cnmlCpuTensor_t variance_tensor;
  void * variance_buf;
  cnmlCpuTensor_t norm_out_tensor;
  void * norm_out_buf;
} cnpapi_cnmlCpuComputeLayerNormOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeLessEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeLessOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeLog2OpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeLogOpForward_params;


typedef struct {
  cnmlDimension_t dim;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeLogSoftmaxOpForward_params;


typedef struct {
  cnmlLrnOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeLrnOpForward_params;


typedef struct {
  cnmlMaskZeroLayerParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t label_tensor;
  void * label;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeMaskZeroOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  int num_lower;
  int num_upper;
} cnpapi_cnmlCpuComputeMatrixBandPartOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t filter_tensor;
  void * filter;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t bias_tensor;
  void * bias;
} cnpapi_cnmlCpuComputeMatrixMultOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeMaxEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlCpuTensor_t index_tensor;
  void * index_buf;
} cnpapi_cnmlCpuComputeMaxOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeMaximumOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeMinEqualOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlCpuTensor_t index_tensor;
  void * index_buf;
} cnpapi_cnmlCpuComputeMinOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeMinimumOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeMinusOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t filter_tensor;
  void * filter;
  cnmlCpuTensor_t bias_tensor;
  void * bias;
} cnpapi_cnmlCpuComputeMlpOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeMultOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeNEqualOpForward_params;


typedef struct {
  int dim;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeNdArgmaxOpForward_params;


typedef struct {
  int dim;
  cnmlCpuTensor_t * inputs_tensor_ptr;
  void ** inputs;
  int input_num;
  cnmlCpuTensor_t * outputs_tensor_ptr;
  void ** outputs;
  int output_num;
} cnpapi_cnmlCpuComputeNdConcatOpForward_params;


typedef struct {
  int dim;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeNdLogSoftmaxOpForward_params;


typedef struct {
  int dim;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeNdReduceMaxOpForward_params;


typedef struct {
  int dim;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeNdReduceMeanOpForward_params;


typedef struct {
  int dim;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeNdReduceSumOpForward_params;


typedef struct {
  int dim;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeNdSoftmaxOpForward_params;


typedef struct {
  int dim;
  cnmlCpuTensor_t * inputs_tensor_ptr;
  void ** inputs;
  int input_num;
  cnmlCpuTensor_t * outputs_tensor_ptr;
  void ** outputs;
  int output_num;
} cnpapi_cnmlCpuComputeNdSplitOpForward_params;


typedef struct {
  cnmlNdStridedSliceOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeNdStridedSliceOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlNdTransposeOpParam_t param;
} cnpapi_cnmlCpuComputeNdTransposeProOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlNearestNeighborOpParam_t param;
} cnpapi_cnmlCpuComputeNearestNeighborOpForward_params;


typedef struct {
  cnmlNmsOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeNmsOpForward_params;


typedef struct {
  cnmlNormalizeOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t scale_tensor;
  void * scale;
} cnpapi_cnmlCpuComputeNormalizeOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeNotOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeOrOpForward_params;


typedef struct {
  cnmlCpuTensor_t * input_tensors;
  void ** inputs;
  int input_num;
  int axis_num;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputePackOpForward_params;


typedef struct {
  cnmlPoolOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t index_tensor;
  void * index;
} cnpapi_cnmlCpuComputePoolIndexOpForward_params;


typedef struct {
  cnmlPoolOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputePoolOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  float power_c;
} cnpapi_cnmlCpuComputePowerOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlCpuTensor_t prelu_param_tensor;
  void * prelu_param_buf;
} cnpapi_cnmlCpuComputePreluOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeRealDivOpForward_params;


typedef struct {
  cnmlDimension_t mode;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeReduceMaxOpForward_params;


typedef struct {
  cnmlDimension_t mode;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeReduceMeanOpForward_params;


typedef struct {
  cnmlDimension_t mode;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeReduceProductOpForward_params;


typedef struct {
  cnmlDimension_t mode;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeReduceSumOpForward_params;


typedef struct {
  cnmlReorgOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeReorgOpForward_params;


typedef struct {
  cnmlReshapeOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeReshapeOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlDimension_t reverse_axis;
} cnpapi_cnmlCpuComputeReverseOpForward_params;


typedef struct {
  cnmlCpuTensor_t x_tensor;
  void * x_buf;
  cnmlCpuTensor_t dy_tensor;
  void * dy_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeRsqrtGradOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeRsqrtOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t alpha_tensor;
  void * alpha;
  cnmlCpuTensor_t beta_tensor;
  void * beta;
} cnpapi_cnmlCpuComputeScaleOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t index_tensor;
  void * index;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlScatterOpParam_t param;
} cnpapi_cnmlCpuComputeScatterOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeSeluOpForward_params;


typedef struct {
  cnmlSequenceMaskOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeSequenceMaskOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  float Const;
} cnpapi_cnmlCpuComputeSetConstOpBackward_params;


typedef struct {
  cnmlCpuTensor_t lr_tensor;
  void * lr_buf;
  cnmlCpuTensor_t netparam_tensor;
  void * netparam_buf;
  cnmlCpuTensor_t grad_tensor;
  void * grad_buf;
  cnmlCpuTensor_t updated_netparam_tensor;
  void * updated_netparam_buf;
} cnpapi_cnmlCpuComputeSgdOp_params;


typedef struct {
  cnmlCpuTensor_t * inputs_tensor_ptr;
  void ** inputs;
  cnmlCpuTensor_t * outputs_tensor_ptr;
  void ** outputs;
  int group;
} cnpapi_cnmlCpuComputeShuffleChannelOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeSignOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeSinOpForward_params;


typedef struct {
  cnmlDimension_t dim;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeSoftmaxOpForward_params;


typedef struct {
  cnmlCpuTensor_t dw_tensor;
  void * dw_buf;
  cnmlCpuTensor_t dx_tensor;
  void * dx_buf;
  cnmlCpuTensor_t dy_tensor;
  void * dy_buf;
  float beta;
} cnpapi_cnmlCpuComputeSoftplusGradForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeSoftplusOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeSoftsignOpForward_params;


typedef struct {
  int w_block_size;
  int h_block_size;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeSpace2batchOpForward_params;


typedef struct {
  cnmlSplitOpParam_t param;
  cnmlCpuTensor_t * inputs_tensor_ptr;
  void ** inputs;
  int input_num;
  cnmlCpuTensor_t * outputs_tensor_ptr;
  void ** outputs;
  int output_num;
} cnpapi_cnmlCpuComputeSplitOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeSqrtOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeSquareOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeSquaredDiffOpForward_params;


typedef struct {
  cnmlDimension_t mode;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeStdDevOpForward_params;


typedef struct {
  cnmlStridedSliceOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeStridedSliceOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeSubOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_y_tensor;
  void * input_y;
  cnmlCpuTensor_t input_delta_y_tensor;
  void * input_delta_y;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeTanhGradOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  float threshold;
} cnpapi_cnmlCpuComputeThrsOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeTileOpForward_params;


typedef struct {
  int k;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t index_tensor;
  void * index;
  cnmlDimension_t ch;
} cnpapi_cnmlCpuComputeTopkOpForward_params;


typedef struct {
  int k;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t index_tensor;
  void * index;
  cnmlDimension_t ch;
  cnmlTopkOpMode_t kmode;
} cnpapi_cnmlCpuComputeTopkOpForward_V2_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlTransposeOpParam_t param;
} cnpapi_cnmlCpuComputeTransposeProOpForward_params;


typedef struct {
  cnmlTrilOpParam_t param;
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeTrilOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t count_cpu;
  void * count_cpu_ptr;
} cnpapi_cnmlCpuComputeUnarySelectOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t index_tensor;
  void * index;
} cnpapi_cnmlCpuComputeUniqueOpForward_params;


typedef struct {
  cnmlUnpoolOpParam_t unpool_param;
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t index_tensor;
  void * index_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeUnpoolOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
} cnpapi_cnmlCpuComputeVector2NormOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
  cnmlCpuTensor_t count_tensor;
  void * count;
} cnpapi_cnmlCpuComputeWhereOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor_1;
  void * input_1;
  cnmlCpuTensor_t input_tensor_2;
  void * input_2;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeXorOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input_buf;
  cnmlCpuTensor_t output_tensor;
  void * output_buf;
  cnmlYuvType_t yuv_type;
} cnpapi_cnmlCpuComputeYUVtoGrayOpForward_params;


typedef struct {
  cnmlCpuTensor_t input_tensor;
  void * input;
  cnmlCpuTensor_t output_tensor;
  void * output;
} cnpapi_cnmlCpuComputeZeroOpBackward_params;


typedef struct {
  void * input;
  int num_box;
  int height;
  int width;
} cnpapi_cnmlCpuNmsOpGenerateRois_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateAbsOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateAbsOpForward_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlActiveFunction_t function;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateActiveOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateAddOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlAddPadChannelOpParam_t param;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
} cnpapi_cnmlCreateAddPadChannelOp_params;


typedef struct {
  cnmlAddPadChannelOpParam_t * param;
  int c_front;
  int c_back;
  float pad_value;
} cnpapi_cnmlCreateAddPadChannelOpParam_V2_params;


typedef struct {
  cnmlAddPadChannelOpParam_t * param;
  int channel;
  float pad_value;
} cnpapi_cnmlCreateAddPadChannelOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlAddPadOpParam_t param;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
} cnpapi_cnmlCreateAddPadOp_params;


typedef struct {
  cnmlAddPadOpParam_t * param;
  int pad_ht;
  int pad_hb;
  int pad_wl;
  int pad_wr;
  float pad_value;
} cnpapi_cnmlCreateAddPadOpParam_V2_params;


typedef struct {
  cnmlAddPadOpParam_t * param;
  int pad_h;
  int pad_w;
  float pad_value;
} cnpapi_cnmlCreateAddPadOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateAndOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDimension_t argmax_axis;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateArgmaxOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDimension_t axis;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateArgminOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateAvgOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorX;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateAxOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorX;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t inputTensorY;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateAxpByOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorX;
  cnmlTensor_t inputTensorY;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateAxpyOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlRNNOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t* state_input;
  cnmlTensor_t output;
  cnmlTensor_t* state_output;
  cnmlTensor_t* input_weight;
  cnmlTensor_t* state_weight;
  cnmlTensor_t* input_bias;
  cnmlTensor_t* state_bias;
  cnmlActiveFunction_t active_func;
} cnpapi_cnmlCreateBasicRNNProOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int w_block_size;
  int h_block_size;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateBatch2spaceOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  const cnmlTensor_t inputTensorA;
  const cnmlTensor_t inputTensorB;
  const cnmlTensor_t outputTensor;
  bool trans_a;
  bool trans_b;
} cnpapi_cnmlCreateBatchDotOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t mean;
  cnmlTensor_t var;
} cnpapi_cnmlCreateBatchNormOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t mean;
  cnmlTensor_t var;
} cnpapi_cnmlCreateBatchNormOpForward_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateBroadcastAddOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateBroadcastLesserOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateBroadcastMultOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensor;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateBroadcastOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateBroadcastSubOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlCastType_t castType;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateCastOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input1;
  cnmlTensor_t input2;
  cnmlTensor_t output;
  float alpha;
  float beta;
} cnpapi_cnmlCreateCaxpbyOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensor;
  cnmlTensor_t outputTensor;
  double lower_bound;
  double upper_bound;
} cnpapi_cnmlCreateClipOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlConcatOpParam_t param;
  cnmlTensor_t * inputs_ptr;
  int input_num;
  cnmlTensor_t * outputs_ptr;
  int output_num;
} cnpapi_cnmlCreateConcatOp_params;


typedef struct {
  cnmlConcatOpParam_t * param;
  int input_num;
  int output_num;
  cnmlDimension_t mode;
} cnpapi_cnmlCreateConcatOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlConvDepthwiseOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
} cnpapi_cnmlCreateConvDepthwiseOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlConvDepthwiseOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
} cnpapi_cnmlCreateConvDepthwiseOpForward_params;


typedef struct {
  cnmlConvDepthwiseOpParam_t * param;
  int stride_height;
  int stride_width;
} cnpapi_cnmlCreateConvDepthwiseOpParam_params;


typedef struct {
  cnmlConvDepthwiseOpParam_t * param;
  int stride_height;
  int stride_width;
  int pad_height;
  int pad_width;
} cnpapi_cnmlCreateConvDepthwiseOpParam_V2_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlConvFirstOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t mean;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
  cnmlTensor_t stdt;
} cnpapi_cnmlCreateConvFirstOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlConvFirstOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t mean;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
  cnmlTensor_t stdt;
} cnpapi_cnmlCreateConvFirstOpForward_params;


typedef struct {
  cnmlConvFirstOpParam_t * param;
  int stride_height;
  int stride_width;
  int pad_l;
  int pad_r;
  int pad_t;
  int pad_b;
} cnpapi_cnmlCreateConvFirstOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlConvOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
  int group;
} cnpapi_cnmlCreateConvGroupOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlConvOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
  int group;
} cnpapi_cnmlCreateConvGroupOpForward_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlConvOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
} cnpapi_cnmlCreateConvOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlConvOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
} cnpapi_cnmlCreateConvOpForward_params;


typedef struct {
  cnmlConvOpParam_t * param;
  int stride_height;
  int stride_width;
  int dilation_height;
  int dilation_width;
  int pad_height;
  int pad_width;
} cnpapi_cnmlCreateConvOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateCosOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  const cnmlTensor_t inputTensorA;
  const cnmlTensor_t inputTensorB;
  const cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCosSimilarityOp_params;


typedef struct {
  cnmlCpuTensor_t * cpu_tensor;
  cnmlTensorType_t tensor_type;
  cnmlDataType_t data_type;
  cnmlDataOrder_t data_order;
  int n;
  int c;
  int h;
  int w;
} cnpapi_cnmlCreateCpuTensor_params;


typedef struct {
  cnmlCpuTensor_t * cpu_tensor;
  cnmlTensorType_t tensor_type;
} cnpapi_cnmlCreateCpuTensor_V2_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlCropOpParam_t param;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
} cnpapi_cnmlCreateCropOp_params;


typedef struct {
  cnmlCropOpParam_t * param;
  int start_index_n;
  int start_index_c;
  int start_index_h;
  int start_index_w;
  float space_number;
} cnpapi_cnmlCreateCropOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  void * active_func_ptr;
  cnmlCustomizedActiveOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateCustomizedActiveOp_params;


typedef struct {
  cnmlCustomizedActiveOpParam_t * param;
  float x_start;
  float x_end;
  float y_min;
  int segment_num;
} cnpapi_cnmlCreateCustomizedActiveOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleAddOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleAndOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleGreaterEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleGreaterOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleLessEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleLessOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleMaxEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleMinEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleMultOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleNEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleOrOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleSubOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateCycleXorOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDeconvOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
  int group;
} cnpapi_cnmlCreateDeconvGroupOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDeconvOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
  int group;
} cnpapi_cnmlCreateDeconvGroupOpForward_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDeconvOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
} cnpapi_cnmlCreateDeconvOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDeconvOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
} cnpapi_cnmlCreateDeconvOpForward_params;


typedef struct {
  cnmlDeconvOpParam_t * param;
  int stride_height;
  int stride_width;
  int hu_crop;
  int hd_crop;
  int wl_crop;
  int wr_crop;
} cnpapi_cnmlCreateDeconvOpParam_params;


typedef struct {
  cnmlDeconvOpParam_t * param;
  int stride_height;
  int stride_width;
  int hu_crop;
  int hd_crop;
  int wl_crop;
  int wr_crop;
  int adj_w;
  int adj_h;
} cnpapi_cnmlCreateDeconvOpParam_V2_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateDeviceMemcpyOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateDivSqrtDimOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t inputTensorC;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateDyadicSelectOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t * inputTensorA;
  cnmlTensor_t * inputTensorB;
  int num_in_list;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateDynamicStitchOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateEluOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t weight;
} cnpapi_cnmlCreateEmbeddingOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateErfOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateExpOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateFloorDivOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  const cnmlTensor_t inputTensorA;
  const cnmlTensor_t inputTensorB;
  const cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateFloorModOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateFloorOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t filter;
  cnmlTensor_t bias;
  cnmlTensor_t mean;
  cnmlTensor_t var;
  cnmlTensor_t output;
} cnpapi_cnmlCreateFrozenBatchNormOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t mom_mean;
  cnmlTensor_t mom_var;
  cnmlTensor_t gamma;
  cnmlTensor_t beta;
  cnmlTensor_t eps;
  float momentum;
  cnmlTensor_t output;
  cnmlTensor_t mom_mean_out;
  cnmlTensor_t mom_var_out;
  cnmlTensor_t mean;
  cnmlTensor_t var;
  cnmlTensor_t bn_out;
} cnpapi_cnmlCreateFusedBatchNormOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t es_mean;
  cnmlTensor_t es_var;
  cnmlTensor_t gamma;
  cnmlTensor_t beta;
  cnmlTensor_t eps;
  cnmlTensor_t output;
  cnmlTensor_t batch_mean;
  cnmlTensor_t batch_var;
  cnmlTensor_t mean;
  cnmlTensor_t var;
} cnpapi_cnmlCreateFusedBatchNormOp_V2_params;


typedef struct {
  cnmlFusionOp_t * op;
} cnpapi_cnmlCreateFusionOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlRNNOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t* state_input;
  cnmlTensor_t output;
  cnmlTensor_t* state_output;
  cnmlTensor_t* rx_weight;
  cnmlTensor_t* rh_weight;
  cnmlTensor_t* rx_bias;
  cnmlTensor_t* rh_bias;
  cnmlTensor_t* zx_weight;
  cnmlTensor_t* zh_weight;
  cnmlTensor_t* zx_bias;
  cnmlTensor_t* zh_bias;
  cnmlTensor_t* nx_weight;
  cnmlTensor_t* nh_weight;
  cnmlTensor_t* nx_bias;
  cnmlTensor_t* nh_bias;
} cnpapi_cnmlCreateGRUOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlRNNOpParam_t param;
  cnmlGRUMode_t gru_mode;
  cnmlTensor_t input;
  cnmlTensor_t* state_input;
  cnmlTensor_t output;
  cnmlTensor_t* state_output;
  cnmlTensor_t* rx_weight;
  cnmlTensor_t* rh_weight;
  cnmlTensor_t* rx_bias;
  cnmlTensor_t* rh_bias;
  cnmlTensor_t* zx_weight;
  cnmlTensor_t* zh_weight;
  cnmlTensor_t* zx_bias;
  cnmlTensor_t* zh_bias;
  cnmlTensor_t* nx_weight;
  cnmlTensor_t* nh_weight;
  cnmlTensor_t* nx_bias;
  cnmlTensor_t* nh_bias;
} cnpapi_cnmlCreateGRUProOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensor;
  cnmlTensor_t indexTensor;
  cnmlTensor_t outputTensor;
  cnmlDimension_t axies;
} cnpapi_cnmlCreateGatherV2Op_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateGreaterEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateGreaterOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlGrepChannelOpParam_t param;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
} cnpapi_cnmlCreateGrepChannelOp_params;


typedef struct {
  cnmlGrepChannelOpParam_t * param;
  int c_front;
  int c_back;
} cnpapi_cnmlCreateGrepChannelOpParam_V2_params;


typedef struct {
  cnmlGrepChannelOpParam_t * param;
  int channel;
} cnpapi_cnmlCreateGrepChannelOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlGrepOpParam_t param;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
} cnpapi_cnmlCreateGrepOp_params;


typedef struct {
  cnmlGrepOpParam_t * param;
  int startIndexOfN;
  int startIndexOfH;
  int startIndexOfW;
  float space_number;
} cnpapi_cnmlCreateGrepOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlInterpOpParam_t param;
} cnpapi_cnmlCreateInterpOp_params;


typedef struct {
  cnmlInterpOpParam_t * param;
  int output_width;
  int output_height;
  bool align_corners;
} cnpapi_cnmlCreateInterpOpParam_params;


typedef struct {
  cnmlInterpOpParam_t * param;
  float zoom;
  bool align_corners;
} cnpapi_cnmlCreateInterpOpParamByRatio_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
} cnpapi_cnmlCreateInvertPermutationOp_params;


typedef struct {
  cnmlLSTMClipParam_t * param;
  double min;
  double max;
} cnpapi_cnmlCreateLSTMClipParam_params;


typedef struct {
  cnmlLSTMPeepholeParam_t * param;
  bool enable_peephole;
} cnpapi_cnmlCreateLSTMPeepholeParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlLSTMProParam_t lstm_pro_param;
  cnmlTensor_t x;
  cnmlTensor_t* hx;
  cnmlTensor_t* cx;
  cnmlTensor_t y;
  cnmlTensor_t* hy;
  cnmlTensor_t* cy;
  cnmlTensor_t* filter_forget_x;
  cnmlTensor_t* filter_forget_h;
  cnmlTensor_t* filter_forget_c;
  cnmlTensor_t* bias_forget_x;
  cnmlTensor_t* bias_forget_h;
  cnmlTensor_t* filter_input_x;
  cnmlTensor_t* filter_input_h;
  cnmlTensor_t* filter_input_c;
  cnmlTensor_t* bias_input_x;
  cnmlTensor_t* bias_input_h;
  cnmlTensor_t* filter_update_x;
  cnmlTensor_t* filter_update_h;
  cnmlTensor_t* bias_update_x;
  cnmlTensor_t* bias_update_h;
  cnmlTensor_t* filter_output_x;
  cnmlTensor_t* filter_output_h;
  cnmlTensor_t* filter_output_c;
  cnmlTensor_t* bias_output_x;
  cnmlTensor_t* bias_output_h;
  cnmlTensor_t* filter_rec_proj;
  cnmlTensor_t* bias_rec_proj;
  cnmlTensor_t* filter_out_proj;
  cnmlTensor_t* bias_out_proj;
} cnpapi_cnmlCreateLSTMProOp_params;


typedef struct {
  cnmlLSTMProParam_t * param;
  cnmlRNNOpParam_t rnn_param;
  cnmlLSTMClipParam_t clip_param;
  cnmlLSTMProjectionParam_t proj_param;
  cnmlLSTMPeepholeParam_t peephole_param;
} cnpapi_cnmlCreateLSTMProParam_params;


typedef struct {
  cnmlLSTMProjectionParam_t * param;
  bool is_rec_proj;
  int rec_proj_size;
  cnmlActiveFunction_t rec_act_fun;
  bool is_out_proj;
  int out_proj_size;
  cnmlActiveFunction_t out_act_fun;
} cnpapi_cnmlCreateLSTMProjectionParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t beta;
  cnmlTensor_t gamma;
  cnmlDimension_t axis;
  float epsilon;
  cnmlTensor_t output;
  cnmlTensor_t mean;
  cnmlTensor_t variance;
  cnmlTensor_t norm_out;
} cnpapi_cnmlCreateLayerNormOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateLessEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateLessOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateLog2Op_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateLogOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlDimension_t dim;
} cnpapi_cnmlCreateLogSoftmaxOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlLrnOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateLrnOp_params;


typedef struct {
  cnmlLrnOpParam_t * param;
  cnmlLrnType_t type;
  int local_size;
  double alpha;
  double beta;
  double k;
} cnpapi_cnmlCreateLrnOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlMaskZeroLayerParam_t param;
  cnmlTensor_t input_tensor;
  cnmlTensor_t label_tensor;
  cnmlTensor_t output_tensor;
} cnpapi_cnmlCreateMaskZeroOp_params;


typedef struct {
  cnmlMaskZeroLayerParam_t * param;
  float pad_label;
  float slope;
  bool fuse_relu;
} cnpapi_cnmlCreateMaskZeroOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  int num_lower;
  int num_upper;
} cnpapi_cnmlCreateMatrixBandPartOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t lhsTensor;
  cnmlTensor_t rhsTensor;
  cnmlTensor_t outputTensor;
  cnmlTensor_t biasTensor;
} cnpapi_cnmlCreateMatrixMultOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateMaxEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t index;
} cnpapi_cnmlCreateMaxOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  const cnmlTensor_t inputTensorA;
  const cnmlTensor_t inputTensorB;
  const cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateMaximumOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateMinEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t index;
} cnpapi_cnmlCreateMinOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  const cnmlTensor_t inputTensorA;
  const cnmlTensor_t inputTensorB;
  const cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateMinimumOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateMinusOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensor;
  cnmlTensor_t outputTensor;
  cnmlTensor_t filterTensor;
  cnmlTensor_t biasTensor;
} cnpapi_cnmlCreateMlpOp_params;


typedef struct {
  cnmlModel_t * model;
  const char * name;
} cnpapi_cnmlCreateModel_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateMultOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateNdArgmaxOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t mean;
  cnmlTensor_t var;
} cnpapi_cnmlCreateNdBatchNormOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensor;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdBroadcastOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t * inputs_ptr;
  int input_num;
  cnmlTensor_t * outputs_ptr;
  int output_num;
} cnpapi_cnmlCreateNdConcatOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleAddOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleAndOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleGreaterEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleGreaterOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleLessEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleLessOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleMaxEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleMinEqualOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleMultOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleOrOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleSubOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNdCycleXorOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  int dim;
} cnpapi_cnmlCreateNdLogSoftmaxOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t prelu_param;
} cnpapi_cnmlCreateNdPreluOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateNdReduceMaxOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateNdReduceMeanOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateNdReduceSumOp_params;


typedef struct {
  cnmlReshapeOpParam_t * param;
  int* dims;
  int dim_num;
} cnpapi_cnmlCreateNdReshapeOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t alpha;
  cnmlTensor_t beta;
} cnpapi_cnmlCreateNdScaleOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateNdSoftmaxOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateNdSoftmaxOpForward_params;


typedef struct {
  cnmlBaseOp_t * op;
  int dim;
  cnmlTensor_t * inputs_ptr;
  int input_num;
  cnmlTensor_t * outputs_ptr;
  int output_num;
} cnpapi_cnmlCreateNdSplitOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlNdStridedSliceOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateNdStridedSliceOp_params;


typedef struct {
  cnmlNdStridedSliceOpParam_t * param;
  int dimNum;
  int* begin;
  int* end;
  int* stride;
} cnpapi_cnmlCreateNdStridedSliceOpParam_params;


typedef struct {
  cnmlNdTransposeOpParam_t * param;
  int* dim_order;
  int dim_num;
} cnpapi_cnmlCreateNdTransposeOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlNdTransposeOpParam_t param;
} cnpapi_cnmlCreateNdTransposeProOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlNearestNeighborOpParam_t param;
} cnpapi_cnmlCreateNearestNeighborOp_params;


typedef struct {
  cnmlNearestNeighborOpParam_t * param;
  int output_width;
  int output_height;
} cnpapi_cnmlCreateNearestNeighborOpParam_params;


typedef struct {
  cnmlNearestNeighborOpParam_t * param;
  int zoom;
} cnpapi_cnmlCreateNearestNeighborOpParamByRatio_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlNmsOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateNmsOp_params;


typedef struct {
  cnmlNmsOpParam_t * param;
  int box_size;
  int out_size;
  float nms_thresh;
  float nms_scale;
  float score_thresh;
  bool filter_scores;
  bool normalized_area;
} cnpapi_cnmlCreateNmsOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlNormalizeOpParam_t param;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
  cnmlTensor_t scale_tensor;
  bool is_fix8_mode;
} cnpapi_cnmlCreateNormalizeOp_params;


typedef struct {
  cnmlNormalizeOpParam_t * param;
  int p;
  int use_scale;
  int mode;
  float weight;
} cnpapi_cnmlCreateNormalizeOpParam_params;


typedef struct {
  cnmlNormalizeOpParam_t * param;
  int p;
  int use_scale;
  int mode;
  float weight;
  float bias;
} cnpapi_cnmlCreateNormalizeOpParamV2_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensor;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateNotOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateOrOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  const cnmlTensor_t * inputTensors;
  int input_num;
  int axis;
  const cnmlTensor_t outputTensor;
} cnpapi_cnmlCreatePackOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  const char * name;
  void * kernel_ptr;
  cnrtKernelParamsBuffer_t params;
  cnmlTensor_t * input_ptrs;
  int input_num;
  cnmlTensor_t * output_ptrs;
  int output_num;
  cnmlTensor_t * static_ptrs;
  int static_num;
} cnpapi_cnmlCreatePluginOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlPoolOpParam_t param;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
  cnmlTensor_t index_tensor;
} cnpapi_cnmlCreatePoolIndexOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlPoolOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreatePoolOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlPoolOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreatePoolOpForward_params;


typedef struct {
  cnmlPoolOpParam_t * param;
  int window_height;
  int window_width;
  int stride_height;
  int stride_width;
  int pad_height;
  int pad_width;
  int dilation_height;
  int dilation_width;
  cnmlPoolMode_t pool_mode;
  cnmlPoolStrategyMode_t strategy_mode;
  bool real;
} cnpapi_cnmlCreatePoolOpParam_params;


typedef struct {
  cnmlPoolOpParam_t * param;
  int window_height;
  int window_width;
  int stride_height;
  int stride_width;
  int pad_height;
  int pad_width;
  int dilation_height;
  int dilation_width;
  cnmlPoolMode_t pool_mode;
  cnmlPoolStrategyMode_t strategy_mode;
  bool real;
  float blend_factor;
} cnpapi_cnmlCreatePoolOpParam_V2_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  float power_c;
} cnpapi_cnmlCreatePowerOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t prelu_param;
} cnpapi_cnmlCreatePreluOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input_tensor;
  cnmlTensor_t input_param_tensor;
  cnmlTensor_t input_mp_tensor;
  cnmlTensor_t output_tensor;
  cnmlTensor_t output_param_tensor;
  cnmlTensor_t output_mp_tensor;
  cnmlTensor_t mode;
} cnpapi_cnmlCreateQuantifyOp_params;


typedef struct {
  cnmlQuantizedParam_t * param;
  int pos;
  float scale;
  float offset;
} cnpapi_cnmlCreateQuantizedParam_params;


typedef struct {
  cnmlRNNOpParam_t * param;
  bool is_bidirection;
  int batch_size;
  int vector_size;
  int hidden_size;
  int num_layers;
  cnmlRNNInputMode_t input_mode;
  int max_seqlength;
  int* seqlength_array;
} cnpapi_cnmlCreateRNNOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateRealDivOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDimension_t mode;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateReduceMaxOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDimension_t mode;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateReduceMeanOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDimension_t mode;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateReduceProductOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDimension_t mode;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateReduceSumOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlReorgOpParam_t param;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
} cnpapi_cnmlCreateReorgOp_params;


typedef struct {
  cnmlReorgOpParam_t * param;
  int reorg_h;
  int reorg_w;
  bool reverse;
} cnpapi_cnmlCreateReorgOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlReshapeOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateReshapeOp_params;


typedef struct {
  cnmlReshapeOpParam_t * param;
  int no;
  int co;
  int ho;
  int wo;
  cnmlDataOrder_t df;
} cnpapi_cnmlCreateReshapeOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateReshapeOp_V2_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlDimension_t reverse_axis;
} cnpapi_cnmlCreateReverseOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t y;
  cnmlTensor_t dy;
  cnmlTensor_t output;
} cnpapi_cnmlCreateRsqrtGradOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateRsqrtOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t alpha;
  cnmlTensor_t beta;
} cnpapi_cnmlCreateScaleOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t alpha;
  cnmlTensor_t beta;
} cnpapi_cnmlCreateScaleOpForward_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensor;
  cnmlTensor_t indexTensor;
  cnmlTensor_t outputTensor;
  cnmlScatterOpParam_t param;
} cnpapi_cnmlCreateScatterOp_params;


typedef struct {
  cnmlScatterOpParam_t * param;
  cnmlDimension_t axies;
  int scatter_length;
} cnpapi_cnmlCreateScatterOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateSeluOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlSequenceMaskOpParam_t param;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
} cnpapi_cnmlCreateSequenceMaskOp_params;


typedef struct {
  cnmlSequenceMaskOpParam_t * param;
  bool use_sequence_length;
  int* sequence_length;
  int axis;
  float value;
} cnpapi_cnmlCreateSequenceMaskOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensor;
  cnmlTensor_t outputTensor;
  float Const;
} cnpapi_cnmlCreateSetConstOpBackward_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t lr;
  cnmlTensor_t netparam;
  cnmlTensor_t grad;
  cnmlTensor_t updated_netparam;
} cnpapi_cnmlCreateSgdOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t * inputs_ptr;
  cnmlTensor_t * outputs_ptr;
  int group;
} cnpapi_cnmlCreateShuffleChannelOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input_tensor;
  cnmlTensor_t output_tensor;
} cnpapi_cnmlCreateSignOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateSinOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDimension_t dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateSoftmaxOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDimension_t dim;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateSoftmaxOpForward_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t dw_tensor;
  cnmlTensor_t dx_tensor;
  cnmlTensor_t dy_tensor;
  float beta;
} cnpapi_cnmlCreateSoftplusGrad_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateSoftplusOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateSoftsignOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int w_block_size;
  int h_block_size;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateSpace2batchOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlSplitOpParam_t param;
  cnmlTensor_t * inputs_ptr;
  int input_num;
  cnmlTensor_t * outputs_ptr;
  int output_num;
} cnpapi_cnmlCreateSplitOp_params;


typedef struct {
  cnmlSplitOpParam_t * param;
  int input_num;
  int output_num;
  cnmlDimension_t mode;
} cnpapi_cnmlCreateSplitOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateSqrtOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateSquareOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensor1;
  cnmlTensor_t inputTensor2;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateSquaredDiffOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlDimension_t mode;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateStdDevOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlStridedSliceOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateStridedSliceOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlStridedSliceOpParam_t param;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateStridedSliceOpForward_params;


typedef struct {
  cnmlStridedSliceOpParam_t * param;
  int nb;
  int cb;
  int hb;
  int wb;
  int ne;
  int ce;
  int he;
  int we;
  int ns;
  int cs;
  int hs;
  int ws;
} cnpapi_cnmlCreateStridedSliceOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateSubOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input_y;
  cnmlTensor_t input_delta_y;
  cnmlTensor_t output;
} cnpapi_cnmlCreateTanhGradOp_params;


typedef struct {
  cnmlTensor_t * tensor;
  cnmlTensorType_t tensor_type;
  cnmlDataType_t data_type;
  int n;
  int c;
  int h;
  int w;
} cnpapi_cnmlCreateTensor_params;


typedef struct {
  cnmlTensor_t * tensor;
  cnmlTensorType_t tensor_type;
} cnpapi_cnmlCreateTensor_V2_params;


typedef struct {
  cnmlBaseOp_t * op;
  float threshold;
  cnmlTensor_t inputTensor;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateThrsOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  const cnmlTensor_t inputTensorA;
  const cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateTileOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int k;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t index;
  cnmlDimension_t ch;
} cnpapi_cnmlCreateTopkOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  int k;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t index;
  cnmlDimension_t ch;
  cnmlTopkOpMode_t kmode;
} cnpapi_cnmlCreateTopkOp_V2_params;


typedef struct {
  cnmlTransposeOpParam_t * param;
  cnmlDataOrder_t cpuDataOrder;
  int dimId0;
  int dimId1;
  int dimId2;
  int dimId3;
} cnpapi_cnmlCreateTransposeOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTransposeOpParam_t param;
} cnpapi_cnmlCreateTransposeProOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTrilOpParam_t param;
  cnmlTensor_t inputTensor;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateTrilOp_params;


typedef struct {
  cnmlTrilOpParam_t * param;
  int diagonal;
} cnpapi_cnmlCreateTrilOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
  cnmlTensor_t countTensor;
} cnpapi_cnmlCreateUnarySelectOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t index;
} cnpapi_cnmlCreateUniqueOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t index;
  cnmlTensor_t output;
  cnmlUnpoolOpParam_t unpool_param;
} cnpapi_cnmlCreateUnpoolOp_params;


typedef struct {
  cnmlUnpoolOpParam_t * param;
  int window_height;
  int window_width;
  int stride_height;
  int stride_width;
  cnmlUnpoolMode_t unpool_mode;
} cnpapi_cnmlCreateUnpoolOpParam_params;


typedef struct {
  cnmlUnpoolOpParam_t * param;
  int window_height;
  int window_width;
  int stride_height;
  int stride_width;
  int pad_left;
  int pad_right;
  int pad_up;
  int pad_down;
  cnmlUnpoolMode_t unpool_mode;
  cnmlUnPoolStrategyMode_t pad_mode;
  bool count_include_pad;
} cnpapi_cnmlCreateUnpoolOpParam_V2_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
} cnpapi_cnmlCreateVector2NormOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlTensor_t count;
} cnpapi_cnmlCreateWhereOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensorA;
  cnmlTensor_t inputTensorB;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateXorOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t input;
  cnmlTensor_t output;
  cnmlYuvType_t yuv_type;
} cnpapi_cnmlCreateYUVtoGrayOp_params;


typedef struct {
  cnmlBaseOp_t * op;
  cnmlTensor_t inputTensor;
  cnmlTensor_t outputTensor;
} cnpapi_cnmlCreateZeroOpBackward_params;


typedef struct {
  cnmlAddPadChannelOpParam_t * param;
} cnpapi_cnmlDestroyAddPadChannelOpParam_params;


typedef struct {
  cnmlAddPadOpParam_t * param;
} cnpapi_cnmlDestroyAddPadOpParam_params;


typedef struct {
  cnmlBaseOp_t * op;
} cnpapi_cnmlDestroyBaseOp_params;


typedef struct {
  cnmlConcatOpParam_t * param;
} cnpapi_cnmlDestroyConcatOpParam_params;


typedef struct {
  cnmlConvDepthwiseOpParam_t * param;
} cnpapi_cnmlDestroyConvDepthwiseOpParam_params;


typedef struct {
  cnmlConvFirstOpParam_t * param;
} cnpapi_cnmlDestroyConvFirstOpParam_params;


typedef struct {
  cnmlConvOpParam_t * param;
} cnpapi_cnmlDestroyConvOpParam_params;


typedef struct {
  cnmlCpuTensor_t * cpu_tensor;
} cnpapi_cnmlDestroyCpuTensor_params;


typedef struct {
  cnmlCropOpParam_t * param;
} cnpapi_cnmlDestroyCropOpParam_params;


typedef struct {
  cnmlCustomizedActiveOpParam_t * param;
} cnpapi_cnmlDestroyCustomizedActiveOpParam_params;


typedef struct {
  cnmlDeconvOpParam_t * param;
} cnpapi_cnmlDestroyDeconvOpParam_params;


typedef struct {
  cnmlFusionOp_t * op;
} cnpapi_cnmlDestroyFusionOp_params;


typedef struct {
  cnmlGrepChannelOpParam_t * param;
} cnpapi_cnmlDestroyGrepChannelOpParam_params;


typedef struct {
  cnmlGrepOpParam_t * param;
} cnpapi_cnmlDestroyGrepOpParam_params;


typedef struct {
  cnmlInterpOpParam_t * param;
} cnpapi_cnmlDestroyInterpOpParam_params;


typedef struct {
  cnmlLSTMClipParam_t * param;
} cnpapi_cnmlDestroyLSTMClipParam_params;


typedef struct {
  cnmlLSTMPeepholeParam_t * param;
} cnpapi_cnmlDestroyLSTMPeepholeParam_params;


typedef struct {
  cnmlLSTMProParam_t * param;
} cnpapi_cnmlDestroyLSTMProParam_params;


typedef struct {
  cnmlLSTMProjectionParam_t * param;
} cnpapi_cnmlDestroyLSTMProjectionParam_params;


typedef struct {
  cnmlLrnOpParam_t * param;
} cnpapi_cnmlDestroyLrnOpParam_params;


typedef struct {
  cnmlMaskZeroLayerParam_t * param;
} cnpapi_cnmlDestroyMaskZeroOpParam_params;


typedef struct {
  cnmlModel_t model;
} cnpapi_cnmlDestroyModel_params;


typedef struct {
  cnmlNdStridedSliceOpParam_t * param;
} cnpapi_cnmlDestroyNdStridedSliceOpParam_params;


typedef struct {
  cnmlNdTransposeOpParam_t * param;
} cnpapi_cnmlDestroyNdTransposeOpParam_params;


typedef struct {
  cnmlNearestNeighborOpParam_t * param;
} cnpapi_cnmlDestroyNearestNeighborOpParam_params;


typedef struct {
  cnmlNmsOpParam_t * param;
} cnpapi_cnmlDestroyNmsOpParam_params;


typedef struct {
  cnmlNormalizeOpParam_t * param;
} cnpapi_cnmlDestroyNormalizeOpParam_params;


typedef struct {
  cnmlPoolOpParam_t * param;
} cnpapi_cnmlDestroyPoolOpParam_params;


typedef struct {
  cnmlQuantizedParam_t * param;
} cnpapi_cnmlDestroyQuantizedParam_params;


typedef struct {
  cnmlRNNOpParam_t * param;
} cnpapi_cnmlDestroyRNNOpParam_params;


typedef struct {
  cnmlReorgOpParam_t * param;
} cnpapi_cnmlDestroyReorgOpParam_params;


typedef struct {
  cnmlReshapeOpParam_t * param;
} cnpapi_cnmlDestroyReshapeOpParam_params;


typedef struct {
  cnmlScatterOpParam_t * param;
} cnpapi_cnmlDestroyScatterOpParam_params;


typedef struct {
  cnmlSplitOpParam_t * param;
} cnpapi_cnmlDestroySplitOpParam_params;


typedef struct {
  cnmlStridedSliceOpParam_t * param;
} cnpapi_cnmlDestroyStridedSliceOpParam_params;


typedef struct {
  cnmlTensor_t * tensor;
} cnpapi_cnmlDestroyTensor_params;


typedef struct {
  cnmlTransposeOpParam_t * param;
} cnpapi_cnmlDestroyTransposeOpParam_params;


typedef struct {
  cnmlTrilOpParam_t * param;
} cnpapi_cnmlDestroyTrilOpParam_params;


typedef struct {
  cnmlUnpoolOpParam_t * param;
} cnpapi_cnmlDestroyUnpoolOpParam_params;


typedef struct {
  const char * mlu_res;
  const char * cpu_res;
} cnpapi_cnmlDiffFiles_params;


typedef struct {
  cnmlBaseOp_t op;
  bool bool_index;
  bool batch_index;
} cnpapi_cnmlDyadicSelectOpSetParam_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableConvFirstOpBgraMode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableConvFirstOpFix8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableConvFirstOpFusionPadMode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableConvFirstOpInt8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableConvOpFix8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableConvOpInt8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableDeconvOpFix8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableDeconvOpInt8Mode_params;


typedef struct {
  cnmlFusionOp_t op;
  bool is_support_inst_const_split;
} cnpapi_cnmlEnableFusionOpInstConstSplit_params;


typedef struct {
  cnmlTensor_t tensor;
  cnmlDataType_t cpu_type;
  cnmlDataOrder_t cpu_order;
} cnpapi_cnmlEnableHardwareReshape_params;


typedef struct {
  cnmlBaseOp_t op;
  int inputDataFix8Position;
  float offset;
} cnpapi_cnmlEnableLrnOpFix8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
  float scale;
} cnpapi_cnmlEnableLrnOpFix8ScaleMode_params;


typedef struct {
  cnmlBaseOp_t op;
  int inputDataInt8Position;
  float offset;
} cnpapi_cnmlEnableLrnOpInt8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
  float scale;
} cnpapi_cnmlEnableLrnOpInt8ScaleMode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableMlpOpBinaryMode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableMlpOpFix8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableMlpOpInt8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
  int input_position;
  float input_scale;
} cnpapi_cnmlEnableReorgOpFix8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
  int input_position;
  float input_scale;
} cnpapi_cnmlEnableReorgOpInt8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableXwPlusBOpFix8Mode_params;


typedef struct {
  cnmlBaseOp_t op;
} cnpapi_cnmlEnableXwPlusBOpInt8Mode_params;


typedef struct {
  cnmlFusionOp_t op;
  cnrtFunction_t function;
} cnpapi_cnmlExtractFunctionFromFusionOp_params;


typedef struct {
  cnmlBaseOp_t op;
  cnrtFunction_t function;
} cnpapi_cnmlExtractFunctionFromOp_params;


typedef struct {
  void * ptr;
} cnpapi_cnmlFreeBuffer_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlFusionOp_t fusionOp;
} cnpapi_cnmlFuseOp_params;


typedef struct {
  cnmlDimension_t argmax_axis;
  int ni;
  int ci;
  int hi;
  int wi;
  int * no;
  int * co;
  int * ho;
  int * wo;
} cnpapi_cnmlGetArgmaxOpOutputDim_params;


typedef struct {
  cnmlDimension_t argmin_axis;
  int ni;
  int ci;
  int hi;
  int wi;
  int * no;
  int * co;
  int * ho;
  int * wo;
} cnpapi_cnmlGetArgminOpOutputDim_params;


typedef struct {
  cnmlBaseOp_t op;
  int64_t * size;
} cnpapi_cnmlGetBaseOpRequiredStackSize_params;


typedef struct {
  cnmlTensor_t tensor;
  int * position;
} cnpapi_cnmlGetFix8Position_params;


typedef struct {
  cnmlTensor_t tensor;
  float * scale;
} cnpapi_cnmlGetFix8Scale_params;


typedef struct {
  cnmlFusionOp_t op;
  int64_t * iocount;
} cnpapi_cnmlGetFusionIOCount_params;


typedef struct {
  cnmlFusionOp_t op;
  int64_t * totalmem;
  int64_t * sharemem;
  int64_t * privatemem;
} cnpapi_cnmlGetFusionMaxMemUsed_params;


typedef struct {
  cnmlFusionOp_t op;
  int64_t * size;
} cnpapi_cnmlGetFusionOpRequiredStackSize_params;


typedef struct {
  cnmlBaseOp_t op;
  int64_t * iocount;
} cnpapi_cnmlGetIOCount_params;


typedef struct {
  cnmlBaseOp_t op;
  int64_t * totalmem;
  int64_t * sharemem;
  int64_t * privatemem;
} cnpapi_cnmlGetMaxMemUsed_params;


typedef struct {
  cnmlTensor_t tensor;
  unsigned int * align_bytes;
} cnpapi_cnmlGetMemcpyBatchAlignment_params;


typedef struct {
  cnmlModel_t model;
  uint64_t * size;
} cnpapi_cnmlGetModelSize_params;


typedef struct {
  cnmlTensor_t input;
  cnmlPoolOpParam_t param;
  int * no;
  int * co;
  int * ho;
  int * wo;
} cnpapi_cnmlGetPoolOpOutputDim_params;


typedef struct {
  cnmlTensor_t tensor;
  float * scale;
  float * offset;
} cnpapi_cnmlGetQuant8Param_params;


typedef struct {
  cnmlTensor_t tensor;
  int * position;
} cnpapi_cnmlGetQuantizedPosition_params;


typedef struct {
  cnmlTensor_t tensor;
  float * scale;
} cnpapi_cnmlGetQuantizedScale_params;


typedef struct {
  int reorg_h;
  int reorg_w;
  int ni;
  int ci;
  int hi;
  int wi;
  int * no;
  int * co;
  int * ho;
  int * wo;
  bool reverse;
} cnpapi_cnmlGetReorgOpOutputDim_params;


typedef struct {
  unsigned int * ver;
} cnpapi_cnmlGetVersion_params;


typedef struct {
  cnmlTensor_t tensor;
  char * name;
} cnpapi_cnmlGetWeightName_params;


typedef struct {
  int flag;
} cnpapi_cnmlInit_params;


typedef struct {
  cnmlFusionOp_t op;
  cnrtInvokeFuncParam_t * compute_forw_param;
  void ** const_addr;
} cnpapi_cnmlInitFusionOpConstMemory_params;


typedef struct {
  cnmlFusionOp_t op;
  cnrtInvokeFuncParam_t * compute_forw_param;
  void ** inst_addr;
} cnpapi_cnmlInitFusionOpInstMemory_params;


typedef struct {
  cnmlFusionOp_t op;
  cnrtInvokeFuncParam_t * compute_forw_param;
  void ** intmd_addr;
} cnpapi_cnmlInitFusionOpIntmdMemory_params;


typedef struct {
  const char * filename;
  cnmlCpuTensor_t tensor;
  void * data_addr;
} cnpapi_cnmlLoadTensorFromFile_params;


typedef struct {
  cnmlCpuTensor_t cpu_tensor;
  void * src;
  cnmlTensor_t cnml_tensor;
  void * dst;
  int data_parallelism;
} cnpapi_cnmlMemcpyBatchTensorToDevice_params;


typedef struct {
  cnmlTensor_t cnml_tensor;
  void * src;
  void * dst;
  int data_parallelism;
} cnpapi_cnmlMemcpyBatchTensorToDevice_V2_params;


typedef struct {
  cnmlTensor_t cnml_tensor;
  void * src;
  cnmlCpuTensor_t cpu_tensor;
  void * dst;
  int data_parallelism;
} cnpapi_cnmlMemcpyBatchTensorToHost_params;


typedef struct {
  cnmlTensor_t cnml_tensor;
  void * src;
  void * dst;
  int data_parallelism;
} cnpapi_cnmlMemcpyBatchTensorToHost_V2_params;


typedef struct {
  cnmlCpuTensor_t cpu_tensor;
  void * src;
  cnmlTensor_t cnml_tensor;
  void * dst;
} cnpapi_cnmlMemcpyTensorToDevice_params;


typedef struct {
  cnmlTensor_t cnml_tensor;
  void * src;
  void * dst;
} cnpapi_cnmlMemcpyTensorToDevice_V2_params;


typedef struct {
  cnmlTensor_t cnml_tensor;
  void * src;
  cnmlCpuTensor_t cpu_tensor;
  void * dst;
} cnpapi_cnmlMemcpyTensorToHost_params;


typedef struct {
  cnmlTensor_t cnml_tensor;
  void * src;
  void * dst;
} cnpapi_cnmlMemcpyTensorToHost_V2_params;


typedef struct {
  cnrtKernelParamsBuffer_t params;
  cnmlTensor_t * tensor;
  cnmlDimension_t * dim;
  int mark_num;
} cnpapi_cnmlPluginOpParamsBufferMarkTensorDimension_params;


typedef struct {
  cnmlModel_t model;
  const char * fname;
} cnpapi_cnmlSaveModel_params;


typedef struct {
  cnmlModel_t model;
  void * ptr;
  uint64_t len;
  uint64_t * size;
} cnpapi_cnmlSaveModelToMem_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlCoreVersion_t version;
} cnpapi_cnmlSetBaseOpCoreVersion_params;


typedef struct {
  cnmlBaseOp_t op;
  int core_num;
} cnpapi_cnmlSetBaseOpCorenum_params;


typedef struct {
  cnmlCpuTensor_t tensor;
  cnmlRnnDataMode_t dtype;
} cnpapi_cnmlSetCpuRnnDataMode_params;


typedef struct {
  cnmlCpuTensor_t tensor;
  cnmlDataOrder_t order;
} cnpapi_cnmlSetCpuTensorDataOrder_params;


typedef struct {
  cnmlCpuTensor_t tensor;
  cnmlDataType_t dtype;
} cnpapi_cnmlSetCpuTensorDataType_params;


typedef struct {
  cnmlCpuTensor_t tensor;
  int position;
} cnpapi_cnmlSetCpuTensorFix8Position_params;


typedef struct {
  cnmlCpuTensor_t tensor;
  int dimNum;
  int* dimValues;
} cnpapi_cnmlSetCpuTensorShape_params;


typedef struct {
  cnmlCpuTensor_t tensor;
  int dimNum;
  int* dimValues;
  cnmlDataOrder_t order;
} cnpapi_cnmlSetCpuTensorShapeByOrder_params;


typedef struct {
  cnmlTensor_t tensor;
  int position;
} cnpapi_cnmlSetFix8Position_params;


typedef struct {
  cnmlTensor_t tensor;
  int * positions;
  int positions_size;
} cnpapi_cnmlSetFix8PositionByChannel_params;


typedef struct {
  cnmlTensor_t tensor;
  float scale;
} cnpapi_cnmlSetFix8Scale_params;


typedef struct {
  cnmlTensor_t tensor;
  float * scales;
  int scales_size;
} cnpapi_cnmlSetFix8ScaleByChannel_params;


typedef struct {
  bool fix8_mode;
} cnpapi_cnmlSetFix8ThreadContext_params;


typedef struct {
  cnmlBaseOp_t * op;
  bool high_precision_flag;
} cnpapi_cnmlSetFloorDivHighPrecision_params;


typedef struct {
  cnmlFusionOp_t op;
  cnmlTensor_t * inputs;
  int inputNum;
  cnmlTensor_t * outputs;
  int outputNum;
} cnpapi_cnmlSetFusionIO_params;


typedef struct {
  cnmlFusionOp_t op;
  bool changable;
} cnpapi_cnmlSetFusionOpBatchsizeChangable_params;


typedef struct {
  cnmlFusionOp_t op;
  cnmlCoreVersion_t version;
} cnpapi_cnmlSetFusionOpCoreVersion_params;


typedef struct {
  cnmlFusionOp_t op;
  int core_num;
} cnpapi_cnmlSetFusionOpCorenum_params;


typedef struct {
  cnmlFusionOp_t op;
  bool changable;
} cnpapi_cnmlSetFusionOpCorenumChangable_params;


typedef struct {
  bool fusion_mode;
} cnpapi_cnmlSetFusionThreadContext_params;


typedef struct {
  cnmlNearestNeighborOpParam_t * param;
  bool align_corners;
} cnpapi_cnmlSetNearestNeighborAlignCorner_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t tensor;
  cnmlDataType_t data_type;
} cnpapi_cnmlSetOnlineQuantification_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t tensor;
  cnmlDataType_t data_type;
  cnmlQuantizedParam_t quant_param;
} cnpapi_cnmlSetOperationComputingDataType_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlDataOrder_t cnml_order;
} cnpapi_cnmlSetOperationComputingLayout_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t tensor;
  cnmlDataType_t data_type;
  int position;
  float scale;
  float offset;
} cnpapi_cnmlSetOperatorDataType_params;


typedef struct {
  cnmlBaseOp_t * op;
  bool high_precision_flag;
} cnpapi_cnmlSetPowerHighPrecision_params;


typedef struct {
  cnmlTensor_t tensor;
  float scale;
  float offset;
} cnpapi_cnmlSetQuant8Param_params;


typedef struct {
  cnmlTensor_t tensor;
  int position;
} cnpapi_cnmlSetQuantizedPosition_params;


typedef struct {
  cnmlTensor_t tensor;
  int * positions;
  int positions_size;
} cnpapi_cnmlSetQuantizedPositionByChannel_params;


typedef struct {
  cnmlTensor_t tensor;
  float scale;
} cnpapi_cnmlSetQuantizedScale_params;


typedef struct {
  cnmlTensor_t tensor;
  float * scales;
  int scales_size;
} cnpapi_cnmlSetQuantizedScaleByChannel_params;


typedef struct {
  bool fix8_mode;
} cnpapi_cnmlSetQuantizedThreadContext_params;


typedef struct {
  cnmlBaseOp_t * op;
  bool high_precision_flag;
} cnpapi_cnmlSetRealDivHighPrecision_params;


typedef struct {
  cnmlTensor_t tensor;
  cnmlRnnDataMode_t dtype;
} cnpapi_cnmlSetRnnDataMode_params;


typedef struct {
  cnmlBaseOp_t op;
  cnmlTensor_t tensor;
  cnmlDataOrder_t layout;
} cnpapi_cnmlSetTensorComputingLayoutInOperation_params;


typedef struct {
  cnmlTensor_t tensor;
  cnmlDataType_t dtype;
} cnpapi_cnmlSetTensorDataType_params;


typedef struct {
  cnmlTensor_t tensor;
  int dimNum;
  int* dimValues;
} cnpapi_cnmlSetTensorShape_params;


typedef struct {
  cnmlTensor_t tensor;
  int dimNum;
  int* dimValues;
  int* dimStrides;
} cnpapi_cnmlSetTensorShape_V2_params;


typedef struct {
  cnmlTensor_t tensor;
  char * name;
} cnpapi_cnmlSetWeightName_params;


typedef struct {
  cnmlTensor_t tensor;
  void * value;
} cnpapi_cnmlUpdateWeight_params;


#ifdef __cplusplus
}
#endif

#endif
