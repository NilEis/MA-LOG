cmake_minimum_required(VERSION 3.9.0)
project(ma-log VERSION 1.0.0 LANGUAGES C)

add_library(ma-log INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/ma-log.h)

target_include_directories(ma-log INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)

option(BUILD_EXAMPLES "build an example" OFF)

if(BUILD_EXAMPLES)
    message("Build examples")
    add_executable(ma-log_example src/main.c)
    target_include_directories(ma-log_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
    target_link_libraries(ma-log_example INTERFACE ma-log)
endif()
