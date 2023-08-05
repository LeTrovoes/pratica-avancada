#include "stdio.h"
#include "stdlib.h"
#include "queue.h"

#define INITIAL_SIZE 2

struct queue {
    int head;
    int size;
    int capacity;
    int *vector;
};

int queue_tail(Queue *q) {
    return (q->head+q->size) % q->capacity;
}

static void *double_queue(Queue *q);
static void *halve_queue(Queue *q);
static void change_capacity(Queue *q, int new_capacity);

Queue *queue_new() {
    Queue* queue = malloc(sizeof(struct queue));
    int* vector = malloc(sizeof(int) * INITIAL_SIZE);

    if (vector == NULL) {
        printf("Falha ao alocar memória!\n");
        exit(1);
    }

    queue->vector = vector;
    queue->head = 0;
    queue->size = 0;
    queue->capacity = INITIAL_SIZE;

    return queue;
}

void queue_push(Queue *q, int element) {
    if (q->size + 1 == q->capacity) {
        double_queue(q);
    }

    int next_pos = queue_tail(q);
    q->vector[next_pos] = element;
    q->size++;
}

int queue_pop(Queue *q) {
    int element = q->vector[q->head];
    q->vector[q->head] = ' ';
    q->head = (q->head + q->capacity + 1) % q->capacity;
    q->size--;

    if (q->size == q->capacity/4) {
        halve_queue(q);
    }

    return element;
}

int queue_empty(Queue *q) {
    return q->size == 0;
}

void queue_free(Queue *q) {
    free(q->vector);
    free(q);
}

static void *double_queue(Queue *q) {
    int new_capacity = q->capacity * 2;
    change_capacity(q, new_capacity);
}

static void *halve_queue(Queue *q) {
    int new_capacity = q->capacity / 2;
    change_capacity(q, new_capacity);
}

static void change_capacity(Queue *q, int new_capacity) {
    int *new_vector = malloc(new_capacity * sizeof(int));

    if (new_vector == NULL) {
        printf("Falha ao alocar memória!\n");
        exit(1);
    }

    for (int i = 0; i < q->size; i++) {
        int source_index = (i+q->head+q->capacity)%q->capacity;
        new_vector[i] = q->vector[source_index];
    }

    free(q->vector);
    q->vector = new_vector;
    q->head = 0;
    q->capacity = new_capacity;
}
