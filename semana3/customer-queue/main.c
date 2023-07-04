#include "stdio.h"
#include "stdlib.h"
#include "customer-queue.h"

int main() {
    Queue *q = queue_new();
    queue_put(q, "Pedro", 1000);
    queue_put(q, "Ana", 2000);
    queue_put(q, "Alex", 3000);

    int count = 0;
    atendimentoCaixaBanco(q, &count);
    printf("count: %d\n", count);
    return 0;
}
