cmake_minimum_required(VERSION 3.15)
project(Contest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,1000000000")
add_executable(Contest main.cpp)