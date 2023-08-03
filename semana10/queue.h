typedef struct queue Queue;

Queue *queue_new();
int queue_empty(Queue *q);
void queue_put(Queue *q, int el);
int queue_take(Queue *q);
void queue_free(Queue *q);
