#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph Graph;

Graph *graph_new(int vertices);
void *graph_add_connection(Graph *graph, int source, int destination);
void graph_print(Graph *graph);
void *graph_free(Graph *graph);

#endif
