cmake_minimum_required(VERSION 3.21)
project(tape_sort)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH  "${CMAKE_SOURCE_DIR}/tools")
find_package(Catch REQUIRED)

include(tools/TestSolution.cmake)

# add_subdirectory(tests)

add_executable(tape_sort
        main.cpp

        gf.h

        heap.cpp
        heap.h

        tape.h
        file_tape.cpp
        file_tape.h

        )
