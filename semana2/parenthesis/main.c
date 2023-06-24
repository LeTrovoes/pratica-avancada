#include "stdio.h"
#include "stdlib.h"
#include "stack.h"

#define MAX_INPUT_LEN 1000

int validate_paranthesis(char *input)
{
    Stack *stack = stack_new();
    int is_valid = 1;
    for (int i = 0; input[i] != '\0'; i++)
    {
        char current_char = input[i];

        if (current_char == '(')
        {
            stack_push(stack, 1);
            continue;
        }

        if (current_char == ')')
        {
            if (stack_is_empty(stack))
            {
                is_valid = 0;
                break;
            }

            stack_pop(stack);
            continue;
        }
    }

    if (is_valid)
        is_valid = stack_is_empty(stack);

    stack_free(stack);
    return is_valid;
}

int main()
{
    char *input = malloc(MAX_INPUT_LEN * sizeof(char));

    if (input == NULL)
    {
        printf("Não foi possível alocar memória suficiente.");
        exit(1);
    }

    while (scanf("%s", input) > 0)
    {
        int is_valid = validate_paranthesis(input);
        if (is_valid)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    free(input);
    return 0;
}
