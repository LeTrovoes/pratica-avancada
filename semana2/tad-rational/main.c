#include "stdio.h"
#include "stdlib.h"
#include "rational.h"

int main()
{
    int test_cases = 0;
    scanf(" %d", &test_cases);

    for (int i = 0; i < test_cases; i++)
    {
        int n1, d1, n2, d2;
        char operation;
        scanf(" %d / %d %c %d / %d", &n1, &d1, &operation, &n2, &d2);

        RationalNumber *r1 = rational_new(n1, d1);
        RationalNumber *r2 = rational_new(n2, d2);
        RationalNumber *result;

        switch (operation)
        {
        case '+':
            result = rational_sum(r1, r2);
            break;
        case '-':
            result = rational_subtract(r1, r2);
            break;
        case '*':
            result = rational_multiply(r1, r2);
            break;
        case '/':
            result = rational_divide(r1, r2);
            break;

        default:
            printf("Invalid operation");
            exit(1);
        }

        RationalNumber *simplified_result = rational_simplify(result);

        rational_print(result);
        printf(" = ");
        rational_print(simplified_result);
        printf("\n");

        rational_free(r1);
        rational_free(r2);
        rational_free(result);
        rational_free(simplified_result);
    }

    return 0;
}
