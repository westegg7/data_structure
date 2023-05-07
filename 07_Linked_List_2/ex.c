#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top
} LinkedStackType;

void init(LinkedStackType* stack) {
    stack->top = NULL;
}

int is_empty(LinkedStackType* stack) {
    return (stack->top == NULL);
}

int is_full(LinkedStackType* stack) {
    return 0;
}

void push(LinkedStackType* stack, element data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->link = stack->top;
    stack->top = node;
}

element pop(LinkedStackType* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "stack is empty.\n");
        exit(1);
    } else {
        StackNode* temp = stack->top;
        element data = temp->data;
        stack->top = stack->top->link;
        free(temp);

        return data;
    }
}

element peek(LinkedStackType* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "stack is empty.\n");
        exit(1);
    } else {
        return stack->top->data;
    }
}

int main(void)
{


    return 0;
}