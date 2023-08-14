#include "graph.h"

int main() {

    Grafo *g = grafoLe("grafo.dat");
    mostraCarentes(g);
    grafoLibera(g);

    g = grafoLe("grafo2.dat");
    mostraCarentes(g);
    grafoLibera(g);
    return 0;
}
