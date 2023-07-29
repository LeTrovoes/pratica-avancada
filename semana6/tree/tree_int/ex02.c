#include "stdio.h"
#include "stdlib.h"
#include "tree.h"

int main()
{
    Tree *tree1 = tree_new(
        34,
        tree_new(
            24,
            tree_new(11,
                     tree_new(5, NULL, NULL),
                     NULL),
            tree_new(19, NULL, NULL)),
        tree_new(
            17,
            tree_new(7, NULL, NULL),
            tree_new(9, NULL, NULL)));

    printf("Arvore 1:\n");
    printf("altura = %d\n", tree_height(tree1));
    printf("soma dos pesos do maior caminho = %d\n", tree_max_cost(tree1));
    tree_free(tree1);

    Tree *tree2 = tree_new(
        4,
        tree_new(
            4,
            tree_new(3,
                     tree_new(1, NULL, NULL),
                     tree_new(1, NULL, NULL)),
            tree_new(3,
                     tree_new(1, NULL, NULL),
                     NULL)),
        tree_new(
            3,
            tree_new(1, NULL, NULL),
            tree_new(1, NULL, NULL)));

    printf("\nArvore 2:\n");
    printf("altura = %d\n", tree_height(tree2));
    printf("soma dos pesos do maior caminho = %d\n", tree_max_cost(tree2));
    tree_free(tree2);

    return 0;
}
