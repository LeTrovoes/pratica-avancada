#include "graph.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    Grafo *g = grafoLe("grafo2.dat");
    LLNode *result = topological_sort(g);
    grafoLibera(g);

    while (result) {
        printf("%d ", result->value);
        LLNode *old = result;
        result = result->next;
        free(old);
    }
    printf("\n");
    return 0;
}
