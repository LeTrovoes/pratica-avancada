#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "graph.h"
#include "queue.h"

struct viz
{
  int label;
  float weigth;
  Viz *prox;
};

static Viz *criaViz(Viz *head, int noj, float weigth)
{
  /* insere vizinho no inicio da lista */
  Viz *no = (Viz *)malloc(sizeof(Viz));
  assert(no);
  no->label = noj;
  no->weigth = weigth;
  no->prox = head;
  return no;
}

static Graph *graph_new(int nodes, int edges)
{
  int i;
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->nodes = nodes;
  g->edges = edges;
  g->viz = (Viz **)malloc(sizeof(Viz *) * nodes);
  for (i = 0; i < nodes; i++)
    g->viz[i] = NULL;
  return g;
}

Graph *graph_read(char *filename)
{
  /* cria grafo não orientado - supõe que arquivo está correto! */

  FILE *arq = fopen(filename, "rt");
  int nodes, edges, no1, no2 = 0;
  float weigth;
  Graph *novo;

  fscanf(arq, "%d %d", &nodes, &edges);
  novo = graph_new(nodes, edges);
  assert(novo);
  while (fscanf(arq, "%d %d %f", &no1, &no2, &weigth) == 3)
  {
    novo->viz[no1] = criaViz(novo->viz[no1], no2, weigth);
    novo->viz[no2] = criaViz(novo->viz[no2], no1, weigth);
  }
  return novo;
}

Graph *graph_free(Graph *graph)
{
  if (graph)
  {
    int i = 0;
    Viz *no, *aux;
    for (i = 0; i < graph->nodes; i++)
    {
      no = graph->viz[i];
      while (no)
      {
        aux = no->prox;
        free(no);
        no = aux;
      }
    }
    free(graph->viz);
    free(graph);
  }
  return NULL;
}

void graph_show(char *title, Graph *graph)
{
  int i;
  if (title)
    printf("%s", title);
  if (graph)
  {
    printf("NV: %d, NA: %d\n", graph->nodes, graph->edges);
    for (i = 0; i < graph->nodes; i++)
    {
      Viz *viz = graph->viz[i];
      printf("[%d]->", i);
      while (viz)
      {
        printf("{%d, %g}->", viz->label, viz->weigth);
        viz = viz->prox;
      }
      printf("NULL\n");
    }
  }
}

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
        predecessors[i] = -1;
    }

    colors[start] = COLOR_GRAY;
    distances[start] = 0;
    predecessors[start] = -1;

    Queue *queue = queue_new(g->nodes);
    queue_push(queue, start);

    while (!queue_empty(queue))
    {
        int node_queue = queue_pop(queue);
        for (Viz *neighbor = g->viz[node_queue]; neighbor != NULL; neighbor = neighbor->prox)
        {
            int node_n = neighbor->label;
            if (colors[node_n] != COLOR_WHITE)
                continue;
            colors[node_n] = COLOR_GRAY;
            distances[node_n] = distances[node_queue] + 1;
            predecessors[node_n] = node_queue;
            queue_push(queue, node_n);
        }
        colors[node_queue] = COLOR_BLACK;
    }

    queue_free(queue);
    SearchResult *result = malloc(sizeof(SearchResult));
    assert(result);
    result->colors = colors;
    result->distances = distances;
    result->predecessors = predecessors;
    return result;
}
