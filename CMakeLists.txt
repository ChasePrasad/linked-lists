cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project(LinkedList)
set(SOURCE_FILES main.cpp nvwa/debug_new.cpp)
add_executable(LinkedList ${SOURCE_FILES})