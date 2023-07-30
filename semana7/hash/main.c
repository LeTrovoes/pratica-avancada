#include "stdio.h"
#include "hash.h"

int main()
{
    int size, count;
    if (scanf("%d %d", &size, &count) != 2)
        return 1;

    Hash *hash = hash_new(size);

    for (int i = 0; i < count; i++)
    {
        int el;
        scanf("%d", &el);
        hash_add(hash, el);
    }

    hash_print(hash);
    hash_free(hash);
    return 0;
}
