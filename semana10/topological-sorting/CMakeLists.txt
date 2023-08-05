cmake_minimum_required(VERSION 3.26)
project(topological-sorting C)

set(CMAKE_C_STANDARD 11)

add_executable(topological-sorting
        graph.h
        graph.c
        main.c)

file(COPY grafo2.dat DESTINATION ${CMAKE_BINARY_DIR}/semana10/topological-sorting)
