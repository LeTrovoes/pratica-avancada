#include "./graph.h"
#include "./breadth.c"

int main()
{
    Graph *g = graph_read("grafo.dat");
    char texto[] = "\nMeu grafo\n";
    graph_show(texto, g);

    SearchResult *result = breadth_search(g, 0);

    printf("predecessors: ");
    for (int i = 0; i < g->nodes; i++)
        printf("%d ", result->predecessors[i]);
    printf("\n");

    printf("colors: ");
    for (int i = 0; i < g->nodes; i++)
        printf("%d ", result->colors[i]);
    printf("\n");

    printf("distances: ");
    for (int i = 0; i < g->nodes; i++)
        printf("%d ", result->distances[i]);
    printf("\n");

    graph_free(g);
    search_result_free(result);

    return 0;
}
