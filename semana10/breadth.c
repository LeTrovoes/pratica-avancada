#include "./graph.c"
#include "stdlib.h"
#include "./queue.h"

enum Color
{
    COLOR_WHITE,
    COLOR_GRAY,
    COLOR_BLACK
};

typedef struct searchResult {
    int *colors;
    int *distances;
    int *predecessors;
} SearchResult;

void search_result_free(SearchResult *r) {
    free(r->colors);
    free(r->distances);
    free(r->predecessors);
}

SearchResult *breadth_search(Graph *g, int start)
{
    int *colors = malloc(g->nodes * sizeof(int));
    assert(colors);
    int *distances = malloc(g->nodes * sizeof(int));
    assert(distances);
    int *predecessors = malloc(g->nodes * sizeof(int));
    assert(predecessors);

    for (int i = 0; i < g->nodes; i++)
    {
        colors[i] = COLOR_WHITE;
        distances[i] = -1;
        predecessors[i] = NULL;
    }

    colors[start] = COLOR_GRAY;
    distances[start] = 0;
    predecessors[start] = NULL;

    Queue *queue = queue_new(g->nodes);
    queue_put(queue, start);

    while (!queue_empty(queue))
    {
        int node_queue = queue_take(queue);
        for (Viz *neighbor = g->viz[node_queue]; neighbor != NULL; neighbor = neighbor->prox)
        {
            int node_n = neighbor->label;
            if (colors[node_n] != COLOR_WHITE)
                continue;
            colors[node_n] = COLOR_GRAY;
            distances[node_n] = distances[node_queue] + 1;
            predecessors[node_n] = node_queue;
            queue_put(queue, node_n);
        }
        colors[node_queue] = COLOR_BLACK;
    }

    SearchResult *result = malloc(sizeof(SearchResult));
    assert(result);
    result->colors = colors;
    result->distances = distances;
    result->predecessors = predecessors;
    return result;
}
