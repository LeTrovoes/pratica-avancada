Stack *stack_new() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->start = 0;
    stack->length = 0;
    return stack;
}

void stack_push(Stack *stack, int value) {
    if (stack->length == MAX_LENGTH) {
        printf("Error! Exceeded stack max capacity.\n");
        exit(1);
    }

    int next_position = (stack->start + stack->length) % MAX_LENGTH;
    stack->elements[next_position] = value;
    stack->length++;
}

int stack_pop(Stack *stack) {
    if (stack_is_empty(stack)) {
        printf("Error! Stack is empty.\n");
        exit(1);
    }

    int element = stack->elements[stack->start];
    stack->start = (stack->start + 1) % MAX_LENGTH;
    stack->length--;
    return element;
}

int stack_is_empty(Stack *stack) {
    return stack->length == 0;
}

int stack_free(Stack *stack) {
    free(stack);
}
