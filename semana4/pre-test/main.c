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

        queue_debug(queue);
    }

    queue_free(queue);
}
