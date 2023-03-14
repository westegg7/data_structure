#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int prec(char op) {
    switch(op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char* exp) {
    Stacktype s;
    init_stack(&s);

    char ch;
    int len = strlen(exp);

    for (int i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {
            case '+': case '-': case '*': case '/':
                if (!is_empty(&s) && prec(peek(&s)) >= prec(ch)) {
                    printf("%c", pop(&s));
                } else push(&s, ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                while (peek(&s) != '(') {
                    printf("%c", pop(&s));
                }
                pop(&s);
                break;
            default:
                printf("%c", ch);
                break;
        }
    }
    while (!is_empty(&s)) {
        printf("%c", pop(&s));
    }

}

int main(void) {
    char *s = "(2+3)*4+9";
    infix_to_postfix(s);
    printf("\n\n");



    return 0;
}