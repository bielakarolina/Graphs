cmake_minimum_required(VERSION 3.7)
project(Graphs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/BFS/BFS.cpp)
add_executable(Graphs ${SOURCE_FILES})