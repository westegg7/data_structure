#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} Stacktype;

void init_stack(Stacktype *s) {
    s->top = -1;
}

int is_empty(Stacktype *s) {
    return (s->top == -1);
}

int is_full(Stacktype *s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

void push(Stacktype *s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "This Stack is full.\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}

element pop(Stacktype *s) {
    if (is_empty(s)) {
        fprintf(stderr, "This Stack is empty.\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}

element peek(Stacktype *s) {
    if (is_empty(s)) {
        fprintf(stderr, "This Stack is empty.\n");
        exit(1);
    }
    else return s->stack[s->top];
}


int main(void) {
    Stacktype s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", peek(&s));
    printf("%d\n", pop(&s));

    return 0;
}