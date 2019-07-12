cmake_minimum_required(VERSION 3.12)
project(BFS)

set(CMAKE_CXX_STANDARD 14)

add_executable(BFS main.cpp graph.h graph.cpp bfs.h head.h bfs.cpp)