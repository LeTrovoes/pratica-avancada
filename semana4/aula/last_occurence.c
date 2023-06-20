#include "stdio.h"
#include "stdlib.h"

int last_occurence(char *s, char c) {
    int current_position = 0;
    int last_occurence = -1;
    while(s[current_position] != '\0') {
        if (s[current_position] == c)
            last_occurence = current_position;
        current_position++;
    }

    return last_occurence;
}

int main() {

    char my_word[] = "Rio de Janeiro";
    int last_pos = last_occurence(my_word, 'o');

    printf("%d\n", last_pos);

    return 0;
}
