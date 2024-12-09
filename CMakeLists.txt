cmake_minimum_required(VERSION 3.30)
project(simd)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/simde-amalgamated-0.8.2)
add_executable(simd main.cpp)
