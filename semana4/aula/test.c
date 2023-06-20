#include "stdio.h"

int main() {
    char s1[] = "Sao Paulo";
    s1[0] = 'J';
    printf("%s\n", s1);

    char* s2 = "Sao Paulo";
    s2[0] = 'J';
    printf("%s\n", s2);
    return 0;
}
