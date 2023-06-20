#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack *stack_new();
void stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
int stack_is_empty(Stack *stack);
int stack_free(Stack *stack);

#endif
