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

int eval(char* str) {
    int op1, op2, val, i = 0;
    int len = strlen(str);
    char ch;
    Stacktype s;

    init_stack(&s);
    for (i = 0; i < len; i++) {
        ch = str[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            val = ch - '0';     // String으로 표현된 '0'가 아스키코드 48번. 숫자 0-9는 아스키코드 0-9까지 있는 것을 이용.
            push(&s, val);
        } else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main(void) {
    int result;

    result = eval("82/3-32*+");


    printf("\n%d\n\n", result);


    return 0;
}