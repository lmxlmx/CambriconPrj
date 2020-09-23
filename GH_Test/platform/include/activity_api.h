#ifndef ACTIVITY_ACTIVITY_API_H_
#define ACTIVITY_ACTIVITY_API_H_
#include "callbackapi_types.h"  // NOLINT
#include "cnpapi.h"  // NOLINT
#ifdef __cplusplus
extern "C" {
#endif
enum cnpapiActivityType {
  CNPAPI_ACTIVITY_TYPE_CNRT = 1,
  CNPAPI_ACTIVITY_TYPE_CNML = 2,
  CNPAPI_ACTIVITY_TYPE_EVENT = 3,
  CNPAPI_ACTIVITY_TYPE_BANGC = 4
};
struct cnpapiActCallBackData {
  cnpapiActivityType type;
  cnpapi_CallbackDomain domain;
  cnpapi_CallbackId cbid;
  size_t tid;
  cnpapi_CallbackData data;
  size_t function_param_size;
  uint64_t time_stamp;
};

struct cnpapiActEventData {
    cnpapiActivityType type;
    uint64_t device_id;
    cnpapiEventId event_id;
    uint64_t value;
    size_t tid;
    uint64_t time_stamp;
};

struct cnpapiActivity {
    cnpapiActivityType type;
};

typedef void (*cnpapi_request)(uint64_t **buffer, size_t *size, size_t *maxNumRecords);
typedef void (*cnpapi_complete)(uint64_t *buffer, size_t size, size_t validSize);
CNPAPI_EXPORT cnpapiResult cnpapiActivityEnable(cnpapiActivityType Kind);
CNPAPI_EXPORT cnpapiResult cnpapiActivityRegisterCallbacks(cnpapi_request bufferRequested,
                                                           cnpapi_complete bufferCompleted);
CNPAPI_EXPORT cnpapiResult cnpapiActivityGetNextRecord(void *buffer, size_t RealSize,
                                                       cnpapiActivity **record);
#ifdef __cplusplus
}
#endif
#endif  // ACTIVITY_ACTIVITY_API_H_

