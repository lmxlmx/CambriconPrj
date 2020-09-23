#ifndef CNPAPI_H_
#define CNPAPI_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "cnpapi_types.h"  // NOLINT
#include "callbackapi.h" // NOLINT
#include "cnpapi_event_api.h"  // NOLINT
#include "activity_api.h"  // NOLINT
CNPAPI_EXPORT cnpapiResult cnpapiInit();
#ifdef __cplusplus
}
#endif

#endif  // CNPAPI_H_
