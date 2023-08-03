#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "./graph.h"

struct _viz
{
  int label;
  float weigth;
  Viz *prox;
};

struct _graph
{
  int nodes; // numero de nos ou vertices
  int edges; // numero de arestas
  Viz **viz; // viz[i] aponta para a lista de arestas vizinhas do no i
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
