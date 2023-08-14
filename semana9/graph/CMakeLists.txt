cmake_minimum_required(VERSION 3.26)
project(graph C)

set(CMAKE_C_STANDARD 11)

add_executable(graph
        graph.h
        graph.c
        main.c)

file(COPY grafo.dat DESTINATION ${CMAKE_BINARY_DIR}/semana9/graph)
file(COPY grafo2.dat DESTINATION ${CMAKE_BINARY_DIR}/semana9/graph)
