cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

if (CMAKE_VERSION VERSION_GREATER "3.1")
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_EXTENSIONS OFF)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  project(cncodec_v2_test_demo LANGUAGES CXX C)
else()
  project(cncodec_v2_test_demo CXX C)
  set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}" CACHE STRING "apply c++11 standard for cxx conmpile" FORCE)
endif()

set(CMAKE_C_COMPILER /usr/bin/gcc CACHE STRING "Set x64 C Compiler" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/g++ CACHE STRING "Set x64 CXX Compiler" FORCE)
set(CMAKE_AR /usr/bin/ar CACHE STRING "Set x64 ar tool" FORCE)

include_directories(
  ${PROJECT_SOURCE_DIR}/platform/include
  ${PROJECT_SOURCE_DIR}/include        
)

# Common Library Path
link_directories(
  ${PROJECT_SOURCE_DIR}/platform/lib64
)

add_executable(video_decode
    ${PROJECT_SOURCE_DIR}/src/video_decode_context.c
    ${PROJECT_SOURCE_DIR}/src/video_decode_demo.c
    ${PROJECT_SOURCE_DIR}/src/cncodec_demo_common.c)

target_include_directories(video_decode
    PRIVATE
    ${PROJECT_SOURCE_DIR}/platform/include
    PRIVATE
      ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(video_decode
      ${PROJECT_SOURCE_DIR}/platform/lib64/libcncodec.so
      ${PROJECT_SOURCE_DIR}/platform/lib64/libcnrt.so
      ${PROJECT_SOURCE_DIR}/platform/lib64/libcndrv.so
      pthread
      )