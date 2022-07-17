cmake_minimum_required(VERSION 3.0.0)
project(c++11 VERSION 0.1.0)

set(SOURCES
    c++11/src/sharedfuture1.cc
)

# Add an executable with the above sources
add_executable(asyncTest ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build_cache) 

add_executable(threadTest c++11/src/thread1.cc)
#
add_executable(promiseTest c++11/src/promise1.cc)