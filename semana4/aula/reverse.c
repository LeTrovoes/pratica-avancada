#include "stdio.h"
#include "stdlib.h"

int get_str_size(char* value) {
    int size = 0;
    while(value[size] != '\0')
        size++;
    return size;
}

char* reverse(char* input) {
    int size = get_str_size(input);
    char* result = malloc((size + 1) * sizeof(char));
    int *a = malloc(sizeof(int));
    *a = 30;
    int pos = 0;
    while (input[pos] != '\0') {
        result[size-pos-1] = input[pos];
        pos++;
    }

    result[size] = 0;
    return result;
}

int main() {

    char input[] = "Sao Paulo";
    char *result = reverse(input);

    printf("%s\n", result);

    return 0;
}
