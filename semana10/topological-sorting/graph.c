#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "graph.h"

void dfs_visit(Grafo *grafo, int v, int *visited, int *timeEnter, int *timeExit, char *color, int *time);

static Viz *criaViz(Viz *head, int noj, float peso) {
/* insere vizinho no inicio da lista */
    Viz *no = (Viz *) malloc(sizeof(Viz));
    assert(no);
    no->noj = noj;
    no->peso = peso;
    no->prox = head;
    return no;
}

static Grafo *grafoCria(int nv, int na) {
    int i;
    Grafo *g = (Grafo *) malloc(sizeof(Grafo));
    g->nv = nv;
    g->na = na;
    g->viz = (Viz **) malloc(sizeof(Viz *) * nv);
    for (i = 0; i < nv; i++)
        g->viz[i] = NULL;
    return g;
}

Grafo *grafoLe(char *filename) {
/* cria grafo n�o orientado - sup�e que arquivo est� correto! */

    FILE *arq = fopen(filename, "rt");
    int nv, na, no1, no2 = 0;
    float peso;
    Grafo *novo;

    fscanf(arq, "%d %d", &nv, &na);
    novo = grafoCria(nv, na);
    assert(novo);
    while (fscanf(arq, "%d %d %f", &no1, &no2, &peso) == 3) {
        novo->viz[no1] = criaViz(novo->viz[no1], no2, peso);
        //novo->viz[no2] = criaViz(novo->viz[no2], no1, peso);
    }
    return novo;
}

Grafo *grafoLibera(Grafo *grafo) {
    if (grafo) {
        int i = 0;
        Viz *no, *aux;
        for (i = 0; i < grafo->nv; i++) {
            no = grafo->viz[i];
            while (no) {
                aux = no->prox;
                free(no);
                no = aux;
            }
        }
        free(grafo->viz);
        free(grafo);
    }
    return NULL;
}

void grafoMostra(char *title, Grafo *grafo) {
    int i;
    if (title)
        printf("%s", title);
    if (grafo) {
        printf("NV: %d, NA: %d\n", grafo->nv, grafo->na);
        for (i = 0; i < grafo->nv; i++) {
            Viz *viz = grafo->viz[i];
            printf("[%d]->", i);
            while (viz) {
                printf("{%d, %g}->", viz->noj, viz->peso);
                viz = viz->prox;
            }
            printf("NULL\n");
        }
    }
}

void dfs_visit(Grafo *grafo, int v, int *visited, int *timeEnter, int *timeExit, char *color, int *time) {
    //visited[v] = 1;
    color[v] = 'C';
    (*time)++;
    timeEnter[v] = *time;
    printf("v: %3d %3c \n", v, color[v]);
    for (Viz *w = grafo->viz[v]; w != NULL; w = w->prox) {
        if (color[w->noj] == 'B') {
            visited[w->noj] = v;
            printf("\t%3d - %3d: %3c predecessor: %3d\n", v, w->noj, color[w->noj], visited[w->noj]);
            dfs_visit(grafo, w->noj, visited, timeEnter, timeExit, color, time);
        }
    }
    color[v] = 'P';
    timeExit[v] = ++(*time);
    printf("%3d:>(%3d,%3d,%3c) \n", v, timeEnter[v], timeExit[v], color[v]);
}

void dfs(Grafo *grafo) {
    if (!grafo) return;

    //initialize vector of visited
    int visited[grafo->nv];
    int timeEnter[grafo->nv];
    int timeExit[grafo->nv];
    char color[grafo->nv];
    int time = 0;

    for (int i = 0; i < grafo->nv; i++) {
        visited[i] = -1;
        color[i] = 'B';
    }
    for (int i = 0; i < grafo->nv; i++) {
        if (color[i] == 'B') {
            dfs_visit(grafo, i, visited, timeEnter, timeExit, color, &time);
        }
    }
}
