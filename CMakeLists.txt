cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

project(Vector)

add_executable(${PROJECT_NAME} main.c vector.c)
