#ifndef CNPAPI_TYPES_H_
#define CNPAPI_TYPES_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __CNPAPI_TYPES_H
#define __CNPAPI_TYPES_H
#if defined(WIN32) || defined(WINDOWS)
#define CNPAPI_EXPORT
#define CNPAPI_DISABLE_EXPORT
  typedef unsigned __int64 u64_t;
  typedef __int64 i64_t;
  typedef unsigned __int32 u32_t;
  typedef unsigned __int16 u16_t;
  typedef unsigned __int8 u8_t;
  typedef signed __int32 i32_t;
  typedef signed __int16 i16_t;
  typedef signed __int8 i8_t;
  typedef u64_t camb_size_t;

#else /*!WIN32 || WINDOWS*/
#define CNPAPI_EXPORT __attribute__((visibility("default")))
#define CNPAPI_DISABLE_EXPORT __attribute__((visibility("hidden")))
  typedef uint64_t u64_t;
  typedef int64_t i64_t;
  typedef uint32_t u32_t;
  typedef uint16_t u16_t;
  typedef uint8_t u8_t;
  typedef int32_t i32_t;
  typedef int16_t i16_t;
  typedef int8_t i8_t;
  typedef u64_t camb_size_t;

#endif /*WIN32||WINDOWS*/
#endif /*__CNPAPI_TYPES_H*/

typedef enum {
  CNPAPI_SUCCESS,
  CNPAPI_ERROR_NOT_INITIALIZED,
  CNPAPI_ERROR_INVALID_DEVICE,
  CNPAPI_ERROR_INVALID_ARGUMENT,
  CNPAPI_ERROR_EVENT_GROUP_ENABLED, // when manipulate with event group, should disable it first
  CNPAPI_ERROR_INSUFFICIENT_MEMORY,
  CNPAPI_ERROR_NO_DRIVER,
  CNPAPI_ERROR_INVALID_DEVICE_ID,
  CNPAPI_ERROR_UNKNOWN,
  CNPAPI_ERROR_MAX_LIMIT_REACHED,
  CNPAPI_ERROR_DRIVER_COMMUNICATION_FAILED,
  CNPAPI_ERROR_DEVICE_BUSY,
  CNPAPI_ERROR_ALREADY_IN_USE,
  CNPAPI_ERROR_ACTIVITY_CALLBACK_NOT_REGISTERD
} cnpapiResult;

#ifdef __cplusplus
}
#endif

#endif // CNPAPI_TYPES_H_
