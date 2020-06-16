cmake_minimum_required(VERSION 3.14)
project(Testing)
set(GCC_COVERAGE_COMPILE_FLAGS "-Ddormi")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_CXX_STANDARD 14)

add_executable(Testing main.cpp)