#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue *queue_new();
void queue_push(Queue *q, char element);
char queue_pop(Queue *q);
int queue_start(Queue *q);
int queue_end(Queue *q);
int queue_capacity(Queue *q);
void queue_free(Queue *q);

#endif
