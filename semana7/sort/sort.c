#include "stdio.h"
#include "stdlib.h"

static int compare(const void *_a, const void *_b) {
    int a = *(int*) _a;
    int b = *(int*) _b;
    return b-a;
}

int main()
{
    int citizen_count, query_count;
    if (scanf("%d %d", &citizen_count, &query_count) != 2)
        return 1;

    int *grades = malloc(sizeof(int) * citizen_count);
    if (grades == NULL)
        return 1;

    for (int i = 0; i < citizen_count; i++)
    {
        int grade;
        scanf("%d", &grade);
        grades[i] = grade;
    }

    qsort(grades, citizen_count, sizeof(int), compare);

    for (int i = 0; i < query_count; i++)
    {
        int position;
        scanf("%d", &position);
        printf("%d\n", grades[position-1]);
    }

    free(grades);
    return 0;
}
