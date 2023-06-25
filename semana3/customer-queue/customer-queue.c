#include "stdio.h"
#include "stdlib.h"
#include "customer-queue.h"

#define NAME_MAX_LENGTH 100

struct customer {
    char name[80];
    int amount;
};

typedef struct node
{
    Customer customer;
    Node *next;
} Node;

struct queue {
    Node *start;
    Node *end;
};

Queue *queue_new() {}

void queue_put(Queue *queue, Customer element) {}

Customer queue_take(Queue *queue) {}

int queue_is_empty(Queue *queue) {}

void queue_free(Queue *queue) {}
