#include "stdlib.h"
#include "stdio.h"
#include "queue.h"

int main() {
    char input;
    Queue *queue = queue_new();

    while (scanf(" %c", &input) > 0) {
        if (input == '-') {
            char element = queue_pop(queue);
            printf("dequeued %c\n", element);
        } else {
            queue_push(queue, input);
            printf("enqueued %c\n", input);
        }

        printf(
            "start: %d end: %d cap: %d\n",
            queue_start(queue),
            queue_end(queue),
            queue_capacity(queue)
        );
    }
}

/*
A B C D E F G H
. B
. . C
. . D
. . . E
. . . . F
. . . . . G
H .

*/