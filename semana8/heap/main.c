#include "stdio.h"
#include "stdlib.h"
#include "heap.h"

int main()
{
    int size;
    scanf("%d", &size);

    int *vector = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", vector + i);
    }

    Heap *heap = heap_from(vector, size);

    for (int i = 0; i < size; i++)
    {
        int *heap_vec = heap_vector(heap);
        printf("%d ", heap_vec[i]);
    }
    printf("\n");

    free(vector);
    heap_free(heap);
    return 0;
}
