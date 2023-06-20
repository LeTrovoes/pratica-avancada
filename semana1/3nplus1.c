#include <stdio.h>
#include <stdlib.h>

#define MAX_ITERATIONS 1000000000

int calculate_3n_plus1_cycle_lenght(int n)
{
    int current = n;
    int cycle_lenght = 1;

    while (current != 1)
    {
        cycle_lenght++;
        if (cycle_lenght >= MAX_ITERATIONS)
        {
            printf("ERROR! Exceeded max iterations limit!\n");
            exit(1);
        }

        if (current % 2 == 0)
            current /= 2;
        else
            current = current * 3 + 1;
    }

    return cycle_lenght;
}

int calculate_max_cycle_lenght_between_numbers(int lower, int upper)
{
    int max_cycle_lenght = 0;

    if (lower > upper) {
        int aux = lower;
        lower = upper;
        upper = aux;
    }

    int i;
    for (i = lower; i <= upper; i++)
    {
        int cycle_lenght = calculate_3n_plus1_cycle_lenght(i);
        if (cycle_lenght > max_cycle_lenght)
            max_cycle_lenght = cycle_lenght;
    }

    return max_cycle_lenght;
}

int main()
{
    while (1)
    {
        int i, j;
        if (scanf("%d %d", &i, &j) != 2)
            break;
        int result = calculate_max_cycle_lenght_between_numbers(i, j);
        printf("%d %d %d\n", i, j, result);
    };

    return 0;
}
