cmake_minimum_required(VERSION 3.17)
project(Contest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000000")


add_executable(Contest brute.cpp)