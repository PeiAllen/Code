cmake_minimum_required(VERSION 3.15)
project(JOI__13___Synchronization)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,1073741824")

add_executable(JOI__13___Synchronization main.cpp)