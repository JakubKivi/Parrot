cmake_minimum_required(VERSION 3.9)
project(Parrot)

set(CMAKE_CXX_STANDARD 11)

add_executable(Parrot
        Board.cpp
        Board.h
        Figures.cpp
        File.cpp
        Game.cpp
        GameObject.cpp
        Header.h
        main.cpp)
