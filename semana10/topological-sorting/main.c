#include "graph.h"

int main()
{
    Grafo *g = grafoLe("grafo2.dat");
    char texto[] = "\nMeu grafo\n";
    grafoMostra(texto, g);
    dfs(g);
    grafoLibera(g);
    return 0;
}
