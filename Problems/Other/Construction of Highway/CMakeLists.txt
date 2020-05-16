cmake_minimum_required(VERSION 3.14)
project(Construction_of_Highway)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")
add_executable(Construction_of_Highway main.cpp)