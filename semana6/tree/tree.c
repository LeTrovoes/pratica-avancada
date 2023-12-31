#include "stdio.h"
#include "stdlib.h"
#include "tree.h"

struct tree
{
    char element;
    Tree *left;
    Tree *right;
};

Tree *tree_new_empty()
{
    return NULL;
}

Tree *tree_new(char c, Tree *l, Tree *r)
{
    Tree *node = malloc(sizeof(Tree));
    node->element = c;
    node->left = l;
    node->right = r;
    return node;
}

void tree_free(Tree *t)
{
    if (tree_is_empty(t))
        return;

    tree_free(t->left);
    tree_free(t->right);
    free(t);
}

int tree_is_empty(Tree *t)
{
    return t == NULL;
}

int tree_contains(Tree *t, char el)
{
    if (tree_is_empty(t))
        return 0;
    return t->element == el || tree_contains(t->left, el) || tree_contains(t->right, el);
}

void tree_print_prefix(Tree *t)
{
    if (tree_is_empty(t))
        return;
    printf("%c ", t->element);
    tree_print_prefix(t->left);
    tree_print_prefix(t->right);
}

void tree_print_infix(Tree *t)
{
    if (tree_is_empty(t))
        return;
    tree_print_infix(t->left);
    printf("%c ", t->element);
    tree_print_infix(t->right);
}

void tree_print_postfix(Tree *t)
{
    if (tree_is_empty(t))
        return;
    tree_print_postfix(t->left);
    tree_print_postfix(t->right);
    printf("%c ", t->element);
}

int tree_height(Tree *t)
{
    if (tree_is_empty(t))
        return -1;
    int left_height = tree_height(t->left);
    int right_height = tree_height(t->right);
    return left_height > right_height ? left_height + 1 : right_height + 1;
}
