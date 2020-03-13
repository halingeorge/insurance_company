cmake_minimum_required(VERSION 3.15)
project(insurance_company)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${PROJECT_SOURCE_DIR}/server)

add_executable(insurance_company main.cpp)

target_link_libraries(insurance_company server)
