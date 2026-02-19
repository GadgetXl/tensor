cmake_minimum_required(VERSION 4.0)
project(tensor C)

set(CMAKE_C_STANDARD 23)

add_executable(tensor main.c tensor.c)
