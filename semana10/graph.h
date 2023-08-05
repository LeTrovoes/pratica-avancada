#ifndef GRAPH_H
#define GRAPH_H

typedef struct viz Viz;
typedef struct graph Graph;

struct graph
{
    int nodes; // numero de nos ou vertices
    int edges; // numero de arestas
    Viz **viz; // viz[i] aponta para a lista de arestas vizinhas do no i
};

Graph *graph_read(char *filename);
Graph *graph_free(Graph *graph);
void graph_show(char *title, Graph *graph);

// BREADTH SEARCH
typedef struct searchResult {
    int *colors;
    int *distances;
    int *predecessors;
} SearchResult;

SearchResult *breadth_search(Graph *g, int start);
void search_result_free(SearchResult *r);

enum Color
{
    COLOR_WHITE,
    COLOR_GRAY,
    COLOR_BLACK
};

#endif
