cmake_minimum_required(VERSION 3.19)
project(Caso_7)

set(CMAKE_CXX_STANDARD 14)

include_directories(utils)

add_executable(Caso_7
        program/Main.cpp
        utils/FileManager.h)
