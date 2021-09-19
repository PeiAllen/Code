cmake_minimum_required(VERSION 3.17)
project(E__Falling_Sand)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000000")

add_executable(E__Falling_Sand eric.cpp f1validator.cpp main1.cpp)