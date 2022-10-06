cmake_minimum_required(VERSION 3.0.0)
project(mergesort VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(mergesort src/main.cpp)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)