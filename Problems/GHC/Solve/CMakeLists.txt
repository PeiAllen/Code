cmake_minimum_required(VERSION 3.17)
project(Solve)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")
set(CMAKE_CXX_STANDARD 14)

add_executable(Solve main.cpp)