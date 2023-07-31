#include "stdio.h"
#include "stdlib.h"
#include "heap.h"

#ifdef DEBUG
#define PRINT_DEBUG(...) printf(__VA_ARGS__)
#else
#define PRINT_DEBUG(...) do { } while(0)
#endif

struct heap
{
    int max_size;
    int next_position;
    int *priorities;
};

static void swap(int a, int b, int *v);
static void fix_above(Heap *heap, int pos);
static void fix_below(int *priorities, int current, int size);

Heap *heap_new(int max)
{
    Heap *heap = malloc(sizeof(struct heap));
    heap->max_size = max;
    heap->next_position = 0;
    heap->priorities = malloc(max * sizeof(int));
    return heap;
}

Heap *heap_from(int *vector, int size)
{
    Heap *heap = malloc(sizeof(struct heap));
    heap->max_size = size;
    heap->next_position = size - 1;
    heap->priorities = malloc(size * sizeof(int));

    int vec_pos = 0;
    for (int heap_pos = size / 2; heap_pos < size; heap_pos++)
    {
        heap->priorities[heap_pos] = vector[vec_pos];
        PRINT_DEBUG("1 | heap[%02d] <- vector[%02d] | %d\n", heap_pos, vec_pos, vector[vec_pos]);
        vec_pos++;
    }

    for (int heap_pos = (size / 2) - 1; heap_pos >= 0; heap_pos--)
    {
        PRINT_DEBUG("2 | heap[%02d] <- vector[%02d] | %d\n", heap_pos, vec_pos, vector[vec_pos]);
        heap->priorities[heap_pos] = vector[vec_pos];
        fix_below(heap->priorities, heap_pos, size);
        vec_pos++;
    }

    return heap;
}

void heap_insert(Heap *heap, int priority, int data)
{
    if (heap->next_position < heap->max_size)
    {
        heap->priorities[heap->next_position] = priority;
        fix_above(heap, heap->next_position);
        heap->next_position++;
    }
    else
        printf("Heap CHEIO!\n");
}

static void swap(int a, int b, int *v)
{
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

static void fix_above(Heap *heap, int pos)
{
    int parent;
    while (pos > 0)
    {
        parent = (pos - 1) / 2;
        if (heap->priorities[parent] < heap->priorities[pos])
            swap(pos, parent, heap->priorities);
        else
            break;
        pos = parent;
    }
}

int heap_remove(Heap *heap)
{
    if (heap->next_position > 0)
    {
        int top = heap->priorities[0];
        heap->priorities[0] = heap->priorities[heap->next_position - 1];
        heap->next_position--;
        fix_below(heap->priorities, 0, heap->next_position);
        return top;
    }
    else
    {
        printf("Heap VAZIO!");
        return -1;
    }
}

static void fix_below(int *priorities, int current, int size)
{
    int parent = current;
    int left, right, child;
    while (2 * parent + 1 < size)
    {
        left = 2 * parent + 1;
        right = 2 * parent + 2;
        if (right >= size)
            right = left;
        if (priorities[left] > priorities[right])
            child = left;
        else
            child = right;
        if (priorities[parent] < priorities[child])
            swap(parent, child, priorities);
        else
            break;
        parent = child;
    }
}

int *heap_vector(Heap *heap)
{
    return heap->priorities;
}

void heap_free(Heap *heap)
{
    free(heap->priorities);
    free(heap);
}
