#ifndef GRAPH_H
#define GRAPH_H

typedef struct grafo Grafo;
typedef struct viz Viz;

struct viz {
    int noj;
    float peso;
    Viz *prox;
};

struct grafo {
    int nv; /* numero de nos ou vertices */
    int na; /* numero de arestas */
    Viz **viz; /* viz[i] aponta para a lista de arestas vizinhas do no i */
};

Grafo *grafoLe(char *filename);

void grafoMostra(char *title, Grafo *grafo);

Grafo *grafoLibera(Grafo *grafo);

void dfs(Grafo *grafo);

#endif
