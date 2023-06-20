#include "stdio.h"
#include "stdlib.h"
#include "stack.h"

int main()
{
    int test_cases = 0;
    scanf(" %n", &test_cases);

    for (size_t i = 0; i < test_cases; i++)
    {
        Stack *stack = stack_new();
        char current_char;
        int is_valid = 1;

        while (scanf("%c", &current_char) > 0)
        {
            if (current_char == '(')
            {
                stack_push(stack, 0);
            }

            if (current_char == ')')
            {
                if (stack_is_empty(stack))
                {
                    is_valid = 0;
                }
            }
        }
    }

    return 0;
}
