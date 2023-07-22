#include "stdio.h"
#include "stdlib.h"
#include "queue.h"

#define INITIAL_SIZE 2

struct queue {
    int head;
    int size;
    int capacity;
    char *vector;
};

void *double_queue(Queue *q);
void *halve_queue(Queue *q);
void change_capacity(Queue *q, int new_capacity);

Queue *queue_new() {
    Queue* queue = malloc(sizeof(struct queue));
    char* vector = malloc(sizeof(char) * INITIAL_SIZE);

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

void queue_push(Queue *q, char element) {
    if (q->size + 1 == q->capacity) {
        double_queue(q);
    }

    int next_pos = queue_tail(q);
    q->vector[next_pos] = element;
    q->size++;
}

char queue_pop(Queue *q) {
    char element = q->vector[q->head];
    q->vector[q->head] = ' ';
    q->head = (q->head + q->capacity + 1) % q->capacity;
    q->size--;

    if (q->size == q->capacity/4) {
        halve_queue(q);
    }

    return element;
}

int queue_start(Queue *q) {
    return q->head;
}

int queue_tail(Queue *q) {
    return (q->head+q->size) % q->capacity;
}

int queue_capacity(Queue *q) {
    return q->capacity;
}

void queue_free(Queue *q) {
    free(q->vector);
    free(q);
}

void *double_queue(Queue *q) {
    int new_capacity = q->capacity * 2;
    change_capacity(q, new_capacity);
}

void *halve_queue(Queue *q) {
    int new_capacity = q->capacity / 2;
    change_capacity(q, new_capacity);
}

void change_capacity(Queue *q, int new_capacity) {
    char *new_vector = malloc(new_capacity * sizeof(char));

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

void queue_debug(Queue *q) {
    printf("index:  ");
    for (int i = 0; i < q->capacity; i++)
    {
        printf("%2d ", i);
    }

    printf("\ncontent:");
    for (int i = 0; i < q->capacity; i++)
    {
        char content = q->vector[i];
        if (content == ' ' || content == 0) content = '.';
        printf(" %c ", content);
    }

    printf("\n         ");

    printf("H: %d  T: %d", q->head, queue_tail(q));

    // int tail = queue_tail(q);
    // for (int i = 0; i < q->capacity; i++)
    // {

    //     if (i == q->head) {
    //         printf("H  ");
    //     } else if (i == tail) {
    //         printf("T  ");
    //     } else {
    //         printf("   ");
    //     }
    // }
    printf("\n");
}
