#include "stdio.h"
#include "stdlib.h"
#include "tree.h"

void print_tree_all_orders(Tree *tree);

int main()
{
    // ARVORE 1
    Tree *tree1 = tree_new(
        'D',
        tree_new(
            'B',
            tree_new('A', NULL, NULL),
            tree_new('C', NULL, NULL)),
        tree_new(
            'F',
            tree_new('E', NULL, NULL),
            tree_new('G', NULL, NULL)));

    printf("Arvore 1\n");
    print_tree_all_orders(tree1);
    tree_free(tree1);

    // ARVORE 2
    Tree *tree2 = tree_new(
        'C',
        tree_new(
            'B',
            tree_new('A', NULL, NULL),
            NULL),
        tree_new(
            'D',
            NULL,
            tree_new('E', NULL, NULL)));

    printf("\nArvore 2\n");
    print_tree_all_orders(tree2);
    tree_free(tree2);

    // ARVORE 3
    Tree *tree3 = tree_new(
        'E',
        tree_new(
            'C',
            tree_new('B',
                     tree_new('A', NULL, NULL),
                     NULL),
            tree_new('D', NULL, NULL)),
        tree_new(
            'H',
            tree_new('F',
                     NULL,
                     tree_new('G', NULL, NULL)),
            tree_new('I', NULL, NULL)));

    printf("\nArvore 3\n");
    print_tree_all_orders(tree3);
    tree_free(tree3);

    return 0;
}

void print_tree_all_orders(Tree *tree)
{
    printf("Pre-ordem\n");
    tree_print_prefix(tree);

    printf("\nEm-ordem\n");
    tree_print_infix(tree);

    printf("\nPos-ordem\n");
    tree_print_postfix(tree);
    printf("\n");
}
