cmake_minimum_required(VERSION 3.26)
project(breadth C)

set(CMAKE_C_STANDARD 11)

# include_directories(semana10)

add_executable(breadth
        graph.h
        queue.h
        graph.c
        queue.c
        main.c)

file(COPY ./grafo.dat DESTINATION ${CMAKE_BINARY_DIR}/semana10)
