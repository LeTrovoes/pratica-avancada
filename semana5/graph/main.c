#include "graph.h"
#include "stdio.h"
#include "stdlib.h"

int main() {

    int vertices;
    int edges;

    printf("número de vértices: ");
    scanf(" %d", &vertices);
    printf("número de arestas: ");
    scanf(" %d", &edges);

    Graph *graph = graph_new(vertices);

    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        printf(" aresta (a b): ");
        scanf(" %d %d", &source, &destination);;
        graph_add_connection(graph, source, destination);
    }

    graph_print(graph);
    graph_free(graph);
    return 0;
}