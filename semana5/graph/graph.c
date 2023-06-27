#include "graph.h"
#include "stdio.h"
#include "stdlib.h"

struct graph
{
    int vertices;
    int **matrix;
};

void check_pointer(void *pointer)
{
    if (pointer == NULL)
    {
        printf("Falha ao alocar memória\n");
        exit(1);
    }
}

Graph *graph_new(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));

    graph->vertices = vertices;

    int **matrix = malloc(sizeof(int *) * vertices);
    check_pointer(matrix);

    for (int i = 0; i < vertices; i++)
    {
        matrix[i] = calloc(vertices, sizeof(int));
        check_pointer(matrix[i]);
    }

    graph->matrix = matrix;
    return graph;
}

void *graph_add_connection(Graph *graph, int source, int destination)
{
    graph->matrix[source][destination] = 1;
    graph->matrix[destination][source] = 1;
}

void graph_print(Graph *graph)
{
    printf("Matriz de adjacência\n\e[1;31m  ");
    for (int i = 0; i < graph->vertices; i++)
        printf("%d ", i);
    printf("\e[0;37m\n");

    for (int i = 0; i < graph->vertices; i++)
    {
        printf("\e[1;31m%d\e[0;37m ", i);
        for (int j = 0; j < graph->vertices; j++)
        {
            if (graph->matrix[i][j])
                printf("\e[1;35m");
            printf("%d ", graph->matrix[i][j]);
            printf("\e[0m");
        }
        printf("\n");
    }
}

void *graph_free(Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}
