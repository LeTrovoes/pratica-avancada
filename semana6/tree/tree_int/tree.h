#ifndef TREE_H
#define TREE_H

typedef struct tree Tree;

Tree *tree_new_empty();
Tree *tree_new(int c, Tree *l, Tree *r);
void tree_free(Tree *t);
int tree_is_empty(Tree *t);
int tree_contains(Tree *t, int el);

void tree_print_prefix(Tree *t);
void tree_print_infix(Tree *t);
void tree_print_postfix(Tree *t);

int tree_height(Tree *t);
int tree_max_cost(Tree *t);

#endif
