#ifndef CNPAPI_HOOKLIB_CALLBACKAPI_TYPES_H_
#define CNPAPI_HOOKLIB_CALLBACKAPI_TYPES_H_
#include "cnpapi_types.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef enum {
  CNPAPI_API_ENTER = 0,
  CNPAPI_API_EXIT = 1
} cnpapi_CallbackSite;

typedef struct {
  cnpapi_CallbackSite callbackSite;
  const char * functionName;
  const void * functionParams;
  const void* functionReturnValue;
  const char * symbolName;
} cnpapi_CallbackData;

typedef enum {
  CNPAPI_CB_DOMAIN_CNRT_API = 0,
  CNPAPI_CB_DOMAIN_CNML_API = 1,
  CNPAPI_CB_DOMAIN_CNDRV_API = 2,
  CNPAPI_CB_DOMAIN_SIZE = 3,
  CNPAPI_CB_DOMAIN_FORCE_INT = 0x7fffffff
} cnpapi_CallbackDomain;
typedef i32_t cnpapi_CallbackId;

typedef void (*cnpapi_CallbackFunc)(void * userdata,
                                   cnpapi_CallbackDomain domain,
                                   cnpapi_CallbackId cbid,
                                   const void* cbdata);
typedef void* cnpapi_SubscriberHandle;
#ifdef __cplusplus
}
#endif

#endif  // CNPAPI_HOOKLIB_CALLBACKAPI_TYPES_H_
