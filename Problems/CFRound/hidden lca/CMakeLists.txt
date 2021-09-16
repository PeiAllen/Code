cmake_minimum_required(VERSION 3.17)
project(hidden_lca)

set(CMAKE_CXX_STANDARD 14)

add_executable(hidden_lca petergen.cpp bro.cpp petergen2.cpp gen_killcentroid.cpp mainleaf.cpp petergen3.cpp)