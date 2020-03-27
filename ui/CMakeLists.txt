cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB_RECURSE SRCS *.cpp *.h)

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

add_library(ui ${SRCS})

target_link_libraries(ui PUBLIC Qt5::Widgets server)
