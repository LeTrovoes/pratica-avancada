#include <stdio.h>

float serie_harmonica(int n);

int main()
{
    int input;
    scanf(" %d", &input);
    float result = serie_harmonica(input);
    printf("%.3f\n", result);
    return 0;
}

float serie_harmonica(int n)
{
    float result = 0;

    for (int i = 1; i <= n; i++)
    {
        result += (float)1 / i;
    }

    return result;
}
