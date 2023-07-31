#ifndef HEAH_H
#define HEAP_H

typedef struct heap Heap;

Heap *heap_new(int max);
Heap *heap_from(int *vector, int size);
void heap_insert(Heap *heap, int priority, int data);
int heap_remove(Heap *heap);
int *heap_vector(Heap *heap);
void heap_free(Heap *heap);

#endif
