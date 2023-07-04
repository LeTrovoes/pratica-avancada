#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "customer-queue.h"

struct customer
{
    char name[NAME_MAX_LENGTH];
    int amount;
};

typedef struct node
{
    Customer customer;
    struct node *next;
} Node;

struct queue
{
    Node *start;
    Node *end;
};

Queue *queue_new()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->start = queue->end = NULL;
    return queue;
}

void queue_put(Queue *queue, char name[NAME_MAX_LENGTH], int amount)
{
    Node *node = malloc(sizeof(Node));
    strcpy(node->customer.name, name);
    node->customer.amount = amount;

    node->next = NULL;

    if (queue_is_empty(queue))
    {
        queue->start = queue->end = node;
        return;
    }

    queue->end->next = node;
    queue->end = node;
}

Customer queue_take(Queue *queue)
{
    Customer customer = queue->start->customer;
    queue->start = queue->start->next;
    free(queue->start);
    return customer;
}

int queue_is_empty(Queue *queue)
{
    return queue->start == NULL;
}

void queue_free(Queue *queue)
{
    Node *current = queue->start;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

int atendimentoCaixaBanco(Queue *queue, int *customerCounter)
{
    int depositsAmountCount = 0;

    Node *current = queue->start;
    while (current != NULL)
    {
        (*customerCounter)++;
        depositsAmountCount += current->customer.amount;
        printf(
            "Cliente %d - %s atendido, deposito de %d reais\n",
            *customerCounter,
            current->customer.name,
            current->customer.amount);
        current = current->next;
    }

    return depositsAmountCount;
}
