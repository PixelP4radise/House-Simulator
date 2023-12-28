cmake_minimum_required(VERSION 3.27)
project(House_Simulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(House_Simulator main.cpp
        sourceFiles/house.cpp
        headerFiles/house.h
        sourceFiles/room.cpp
        headerFiles/room.h
        exceptions/positionOcuppied.h
        sourceFiles/houseElements.cpp
        headerFiles/houseElements.h
        exceptions/roomNotFound.h)
