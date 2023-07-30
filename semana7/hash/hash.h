#ifndef HASH_H
#define HASH_H

typedef struct hash Hash;

typedef struct element HashElement;

Hash *hash_new(int size);
HashElement *hash_add(Hash *hash, int element);
void hash_print(Hash *hash);
void hash_free(Hash *hash);

#endif
