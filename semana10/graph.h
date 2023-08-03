#ifndef _GRAPH_H
#define _GRAPH_H

typedef struct _viz Viz;
typedef struct _graph Graph;

Graph *graph_read(char *filename);
Graph *graph_free(Graph *graph);
void graph_show(char *title, Graph *graph);

#endif
