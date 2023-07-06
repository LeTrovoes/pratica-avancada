#include "stdio.h"
#include "stdlib.h"

char encode_char(char input) {
    if (input >= 'a' && input <= 'z') {
        return ((input - 'a' + 1) % 26) + 'a';
    }
    if (input >= 'A' && input <= 'Z') {
        return ((input - 'A' + 1) % 26) + 'A';
    }
    return input;
}

void encode(char *s) {
    int pos = 0;
    while (s[pos] != '\0')
    {
        s[pos] = encode_char(s[pos]);
        pos++;
    }
}

int main() {
    char input[81];

    while (scanf(" %s", input) > 0) {
        encode(input);
        printf("%s\n", input);
    }

    return 0;
}
