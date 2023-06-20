#include <stdio.h>

int fatorial(int number);
int arranjo(int n, int k);

int main() {
    int n, k;
    printf("n: ");
    scanf(" %d", &n);
    printf("k: ");
    scanf(" %d", &k);
    int resultado = arranjo(n, k);
    printf("resultado: %d\n", resultado);
    return 0;
}

int arranjo(int n, int k) {
    return fatorial(n) / fatorial(n-k);
}

int fatorial(int number) {
    int resultado = 1;

    for (int i = 1; i <= number; i++)
        resultado *= i;

    return resultado;
}
