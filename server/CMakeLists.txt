cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRCS *.cpp *.h)

add_library(server ${SRCS})
