#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
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

void print_stack(LinkedStackType* stack) {
    for (StackNode* p = stack->top; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

int main(void) {
    LinkedStackType s;
    init(&s);
    print_stack(&s);
    push(&s, 1);
    print_stack(&s);
    push(&s, 2);
    print_stack(&s);
    push(&s, 3);
    print_stack(&s);
    push(&s, 4);
    print_stack(&s);

    pop(&s);
    print_stack(&s);
    pop(&s);
    print_stack(&s);
    pop(&s);
    print_stack(&s);
    pop(&s);
    print_stack(&s);

    return 0;
}