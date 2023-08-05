#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue *queue_new();
int queue_empty(Queue *q);
void queue_push(Queue *q, int el);
int queue_pop(Queue *q);
void queue_free(Queue *q);

#endif
