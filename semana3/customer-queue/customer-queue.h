#ifndef CUSTOMER_QUEUE_H
#define CUSTOMER_QUEUE_H
#define NAME_MAX_LENGTH 80

typedef struct customer Customer;

typedef struct queue Queue;

Queue *queue_new();
void queue_put(Queue *queue, char name[NAME_MAX_LENGTH], int amount);
Customer queue_take(Queue *queue);
int queue_is_empty(Queue *queue);
void queue_free(Queue *queue);

int atendimentoCaixaBanco(Queue *queue, int *customerCounter);

#endif
