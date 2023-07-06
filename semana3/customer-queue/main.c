#include "stdio.h"
#include "stdlib.h"
#include "customer-queue.h"

int main() {
    Queue *q = queue_new();

    char name[80];
    int amount;

    while (scanf(" %s", name) > 0)
    {
        scanf(" %d", &amount);
        queue_put(q, name, amount);
    }

    int count = 0;
    int sum = atendimentoCaixaBanco(q, &count);

    printf("Total de clientes: %d\n", count);
    printf("Deposito total: %d reais\n", sum);

    queue_free(q);
    return 0;
}
