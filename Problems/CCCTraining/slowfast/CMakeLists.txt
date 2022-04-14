cmake_minimum_required(VERSION 3.20)
project(slowfast)

set(CMAKE_CXX_STANDARD 14)

add_executable(slowfast main.cpp brute.cpp gen.cpp)
