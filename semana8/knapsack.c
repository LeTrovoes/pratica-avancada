#include "stdio.h"
#include "stdlib.h"

#define DEBUG 1

typedef struct item {
    char name;
    int weight;
    int value;
} Item;

typedef struct result {
    Item **items;
    int count;
    int total_weight;
    int total_value;
} Result;

Item *new_item(char name, int value, int weight);
Result *knapsack(Item **items, int count, int capacity);

int main() {
    int n = 5;
    int capacity = 15;
    Item **items = malloc(n * sizeof(Item*));

    items[0] = new_item('A', 4, 12);
    items[1] = new_item('B', 2, 1);
    items[2] = new_item('C', 10, 4);
    items[3] = new_item('D', 2, 2);
    items[4] = new_item('E', 1, 1);


    Result *result = knapsack(items, n, capacity);

    printf("Count: %d, Weight: %d, Value: %d\n", result->count, result->total_weight, result->total_value);

    return 0;
}

Item *new_item(char name, int value, int weight) {
    Item *item = malloc(sizeof(Item));
    item->name = name;
    item->value = value;
    item->weight = weight;
    return item;
}

int compare(const void *a, const void *b) {
    Item *item_a = *(Item**) a;
    Item *item_b = *(Item**) b;

    float cost_befenit_a = (float) item_a->value / item_a->weight;
    float cost_befenit_b = (float) item_b->value / item_b->weight;

#ifdef DEBUG
    printf("  %c %03f | %c %03f\n", item_a->name, cost_befenit_a, item_b->name, cost_befenit_b);
#endif

    if (cost_befenit_a > cost_befenit_b) return 1;
    if (cost_befenit_a < cost_befenit_b) return -1;
    return 0;
}

Result *knapsack(Item **items, int count, int capacity) {
#ifdef DEBUG
    printf("Sorting items based on value / weight\n");
#endif

    qsort(items, count, sizeof(Item*), compare);

    int allocated_capacity = 0;
    int allocated_value = 0;
    int allocated_count = 0;
    Item **allocated_items = malloc(count * sizeof(Item*));

#ifdef DEBUG
    printf("Picking items\n");
#endif

    for (int i = 0; i < count; i++)
    {
        if (allocated_capacity >= capacity) {
            #ifdef DEBUG
                printf("capacity reached, break\n");
            #endif
            break;
        }

#ifdef DEBUG
    printf("  deciding on %c with weight %d: ", items[i]->name, items[i]->weight);
#endif

        if (items[i]->weight <= capacity - allocated_capacity) {
            #ifdef DEBUG
                printf("pick\n");
            #endif
            allocated_capacity += items[i]->weight;
            allocated_value += items[i]->value;
            allocated_items[allocated_count++] = items[i];

            #ifdef DEBUG
                printf("  current weight: %d\n", allocated_capacity);
            #endif

        } else {
            #ifdef DEBUG
                printf("pass\n");
            #endif
        }
    }

    Result *result = malloc(sizeof(Result));
    result->items = allocated_items;
    result->count = allocated_count;
    result->total_value = allocated_value;
    result->total_weight = allocated_capacity;
    return result;
}
