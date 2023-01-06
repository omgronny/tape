cmake_minimum_required(VERSION 3.21)
project(sort)

set(CMAKE_CXX_STANDARD 20)

add_executable(sort
        main.cpp

        gf.h

        heap.cpp
        heap.h

        tape.h
        file_tape.cpp
        file_tape.h

        )
