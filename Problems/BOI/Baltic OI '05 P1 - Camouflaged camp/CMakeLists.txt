cmake_minimum_required(VERSION 3.16)
project(Baltic_OI__05_P1___Camouflaged_camp)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -fno-sanitize-recover -fstack-protector")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
add_executable(Baltic_OI__05_P1___Camouflaged_camp main.cpp)