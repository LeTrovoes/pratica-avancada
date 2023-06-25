#ifndef CUSTOMER_QUEUE_H
#define CUSTOMER_QUEUE_H

typedef struct customer Customer;

typedef struct queue Queue;

Queue *queue_new();
void queue_put(Queue *queue, Customer element);
Customer queue_take(Queue *queue);
int queue_is_empty(Queue *queue);
void queue_free(Queue *queue);

#endif
