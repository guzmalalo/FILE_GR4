cmake_minimum_required(VERSION 3.27)
project(FILE_GR4 C)

set(CMAKE_C_STANDARD 11)

add_executable(FILE_GR4 main.c
        libFile.c
        libFile.h
)
