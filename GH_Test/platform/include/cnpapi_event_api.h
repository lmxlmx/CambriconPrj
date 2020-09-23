#ifndef CNPAPI_EVENT_API_H  // NOLINT
#define CNPAPI_EVENT_API_H  // NOLINT
#include "cnpapi_types.h"  // NOLINT
#ifdef __cplusplus
extern "C" {
#endif
typedef void *cnpapiEventGroup;
typedef uint64_t cnpapiEventId;
typedef uint64_t cnpapiEventDomain;

enum cnpapiDeviceInfoType {
  CNPAPI_DEVICE_INFO_MAX_EVENT_ID = 1,
  CNPAPI_DEVICE_INFO_MAX_EVENT_DOMAIN_ID = 2,
};

enum cnpapiEventDomainInfoType {
  CNPAPI_EVENT_DOMAIN_INFO_NAME = 0,
};

enum cnpapiEventInfoType {
  CNPAPI_EVENT_INFO_NAME = 0,
};

enum cnpapiEventGroupInfoType {
  CNPAPI_EVENT_GROUP_INFO_EVENT_DOMAIN_ID = 0,
};

CNPAPI_EXPORT cnpapiResult cnpapiEnumEventDomain(uint64_t device_id, size_t *domainSize,
                                                 cnpapiEventDomain *domain);

CNPAPI_EXPORT cnpapiResult cnpapiDeviceGetInformation(uint64_t device_id, cnpapiDeviceInfoType info,
                                                      size_t *valueSize, void *value);
CNPAPI_EXPORT cnpapiResult cnpapiDeviceGetNameByDomain(uint64_t device_id, cnpapiEventDomain eventDomain,
                                                       size_t *nameSize, char *value);
CNPAPI_EXPORT cnpapiResult cnpapiDeviceGetEventDomainInformation(uint64_t device_id,
                                                               cnpapiEventDomain eventDomain,
                                                               cnpapiEventDomainInfoType info,
                                                               size_t *valueSize, void *value);

CNPAPI_EXPORT cnpapiResult cnpapiGetNumEventDomain(uint64_t device_id, uint32_t *numDomains);

CNPAPI_EXPORT cnpapiResult cnpapiEventDomainEnumEvents(cnpapiEventDomain eventdomain,
                                                       size_t *eventSize, cnpapiEventId *event);
CNPAPI_EXPORT cnpapiResult cnpapiEventDomainGetNumEvents(cnpapiEventDomain eventdomain,
                                                         uint32_t *numEvents);
CNPAPI_EXPORT cnpapiResult cnpapiEventGetInformation(cnpapiEventId event, cnpapiEventInfoType info,
                                                     size_t *valueSize, void *value);
CNPAPI_EXPORT cnpapiResult cnpapiEventGetIdFromName(uint64_t device_id, const char *eventName,
                                                    cnpapiEventId *event);

CNPAPI_EXPORT cnpapiResult cnpapiEventGroupAddEvent(cnpapiEventGroup eventGroup,
                                                    cnpapiEventId event);
CNPAPI_EXPORT cnpapiResult cnpapiEventGroupCreate(uint64_t device_id, cnpapiEventGroup *eventGroup);
CNPAPI_EXPORT cnpapiResult cnpapiEventGroupDestory(cnpapiEventGroup eventGroup);
CNPAPI_EXPORT cnpapiResult cnpapiEventGroupDisable(cnpapiEventGroup eventGroup);
CNPAPI_EXPORT cnpapiResult cnpapiEventGroupEnable(cnpapiEventGroup eventGroup);
CNPAPI_EXPORT cnpapiResult cnpapiEventGroupGetInformation(cnpapiEventGroup eventGroup,
                                                          cnpapiEventGroupInfoType info,
                                                          size_t *valueSize, void *value);
CNPAPI_EXPORT cnpapiResult cnpapiEventGroupReadAllEvents(
    cnpapiEventGroup eventGroup,  size_t *eventValueBufferSizeBytes,
    uint64_t *eventValueBuffer, size_t *eventIdArraySizeBytes, cnpapiEventId *eventIdArray,
    size_t *numEventIdsRead);

CNPAPI_EXPORT cnpapiResult cnpapiEventGroupReadEvent(cnpapiEventGroup eventGroup,
                                                     cnpapiEventId event,
                                                     size_t *eventValueBufferSizeBytes,
                                                     uint64_t *eventValueBuffer);
CNPAPI_EXPORT cnpapiResult cnpapiEventGroupRemoveAllEvents(cnpapiEventGroup eventGroup);
CNPAPI_EXPORT cnpapiResult cnpapiEventGroupRemoveEvent(cnpapiEventGroup eventGroup,
                                                       cnpapiEventId event);
CNPAPI_EXPORT cnpapiResult cnpapiEventGetDeviceCount(int *num);
#ifdef __cplusplus
}
#endif

#endif  // NOLINT
