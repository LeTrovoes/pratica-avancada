#include "stdio.h"
#include "stdlib.h"
#include "queue.h"

#define INITIAL_SIZE 2

struct queue {
    int start;
    int size;
    int capacity;
    char *elements;
};

void *double_queue(Queue *q);
void *halve_queue(Queue *q);

Queue *queue_new() {
    Queue* queue = malloc(sizeof(struct queue));
    char* array = malloc(sizeof(char) * INITIAL_SIZE);

    if (array == NULL) {
        printf("Falha ao alocar memória!\n");
        exit(1);
    }

    queue->elements = array;
    queue->start = 0;
    queue->size = 0;
    queue->capacity = INITIAL_SIZE;

    return queue;
}

void queue_push(Queue *q, char element) {
    if (q->start + q->size == q->capacity) {
        printf("double_queue\n");
        double_queue(q);
    }

    printf("%d %c\n", q->size, element);
    q->elements[q->size] = element;
    q->size++;
}

char queue_pop(Queue *q) {
    char element = q->elements[q->start];
    q->start++;
    q->size--;

    if (q->size == q->capacity/4) {
        halve_queue(q);
    }

    return element;
}

int queue_start(Queue *q) {
    return q->start;
}

int queue_end(Queue *q) {
    return q->start + q->size;
}

int queue_capacity(Queue *q) {
    return q->capacity;
}

void queue_free(Queue *q) {
    free(q);
}

void *double_queue(Queue *q) {
    int new_capacity = q->capacity * 2;
    char *new_array = realloc(q->elements, new_capacity * sizeof(char));
    if (new_array == NULL) {
        printf("Falha ao alocar memória!\n");
        exit(1);
    }

    q->elements = new_array;
    q->capacity = new_capacity;
}

void *halve_queue(Queue *q) {
    int new_capacity = q->capacity / 2;
    char *new_array = realloc(q->elements, new_capacity * sizeof(char));
    if (new_array == NULL) {
        printf("Falha ao alocar memória!\n");
        exit(1);
    }

    q->elements = new_array;
    q->capacity = new_capacity;
}
