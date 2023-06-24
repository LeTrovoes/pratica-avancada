#include "stdio.h"
#include "stdlib.h"
#include "stack.h"

#define MAX_LENGTH 1000

struct stack
{
    int size;
    int elements[MAX_LENGTH];
};

Stack *stack_new()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = 0;
    return stack;
}

void stack_push(Stack *stack, int value)
{
    if (stack->size == MAX_LENGTH)
    {
        printf("Error! Exceeded stack max capacity.\n");
        exit(1);
    }

    stack->elements[stack->size] = value;
    stack->size++;
}

int stack_pop(Stack *stack)
{
    if (stack_is_empty(stack))
    {
        printf("Error! Stack is empty.\n");
        exit(1);
    }

    int element = stack->elements[stack->size - 1];
    stack->size--;
    return element;
}

int stack_is_empty(Stack *stack)
{
    return stack->size == 0;
}

int stack_free(Stack *stack)
{
    free(stack);
}
