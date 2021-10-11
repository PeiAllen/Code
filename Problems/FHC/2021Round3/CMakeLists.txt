cmake_minimum_required(VERSION 3.20)
project(2021Round3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000000")

add_executable(2021Round3 main.cpp)
