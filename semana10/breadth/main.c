#include "graph.h"
#include "stdio.h"

int main()
{
    Graph *g = graph_read("grafo.dat");
    char text[] = "\nMeu grafo\n";
    graph_show(text, g);

    SearchResult *result = breadth_search(g, 0);

    printf("predecessors: ");
    for (int i = 0; i < g->nodes; i++)
        printf("%2d ", result->predecessors[i]);
    printf("\n");

    printf("      colors: ");
    for (int i = 0; i < g->nodes; i++)
        printf("%2d ", result->colors[i]);
    printf("\n");

    printf("   distances: ");
    for (int i = 0; i < g->nodes; i++)
        printf("%2d ", result->distances[i]);
    printf("\n");

    graph_free(g);
    search_result_free(result);

    return 0;
}
