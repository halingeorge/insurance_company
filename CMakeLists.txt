cmake_minimum_required(VERSION 3.5)

project(insurance_company LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Qt5_DIR /Users/halin-george/Qt1/5.14.1/clang_64/lib/cmake/Qt5)

SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

add_subdirectory(server)
add_subdirectory(ui)

add_executable(insurance_company main.cpp)

target_link_libraries(insurance_company ui)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
