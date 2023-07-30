#include "stdio.h"
#include "stdlib.h"
#include "hash.h"

struct hash
{
    int size;
    HashElement **table;
};

struct element
{
    int value;
    HashElement *next;
};

static void check_alloc(void *pointer)
{
    if (pointer == NULL)
    {
        printf("Falha ao alocar memória.");
        exit(1);
    }
}

Hash *hash_new(int size)
{
    HashElement **table = malloc(sizeof(HashElement*) * size);
    check_alloc(table);
    Hash *hash = malloc(sizeof(Hash));
    check_alloc(hash);
    hash->size = size;
    hash->table = table;
    return hash;
}

HashElement *hash_add(Hash *hash, int value)
{
    int key = value % hash->size;
    HashElement *current = hash->table[key];

    if (current != NULL)
    {
        while (current->next != NULL)
        {
            if (current->value == value)
                return current;
            current = current->next;
        }
    }

    HashElement *new_element = malloc(sizeof(HashElement));
    check_alloc(new_element);
    new_element->next = NULL;
    new_element->value = value;
    if (current == NULL) {
        hash->table[key] = new_element;
    } else {
        current->next = new_element;
    }
    return new_element;
}

void hash_print(Hash *hash)
{
    for (int i = 0; i < hash->size; i++)
    {
        printf("%d ->", i);
        for (HashElement *el = hash->table[i]; el != NULL; el = el->next)
        {
            printf(" %d ->", el->value);
        }
        printf(" \\\n");
    }
}

void hash_free(Hash *hash)
{
    for (int i = 0; i < hash->size; i++)
    {
        HashElement *current = hash->table[i];
        while (current != NULL)
        {
            HashElement *next = current->next;
            free(current);
            current = next;
        }
    }

    free(hash->table);
    free(hash);
}
