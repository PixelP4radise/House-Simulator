cmake_minimum_required(VERSION 3.27)
project(House_Simulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(House_Simulator main.cpp
        habitacao.cpp
        habitacao.h)
