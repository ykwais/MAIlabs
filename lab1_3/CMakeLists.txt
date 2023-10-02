cmake_minimum_required(VERSION 3.23)
project(laboratory1_3 C)

set(CMAKE_C_STANDARD 99)

add_library(MyLIB STATIC functions.c)

add_executable(laboratory1_3 main.c enums.h)

target_link_libraries(laboratory1_3 MyLIB)
