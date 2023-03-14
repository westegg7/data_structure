#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;
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


int check_matching(const char *in) {
    Stacktype s;
    char ch, open_ch;
    int n = strlen(in);
    init_stack(&s);

    for (int i = 0; i < n; i++) {
        ch = in[i];
        switch (ch) {
            case '(': case '{': case '[':
                push(&s, ch);
                break;
            case ')': case '}': case ']':
                if (is_empty(&s)) return 0;
                else {
                    open_ch = pop(&s);
                    if (open_ch == '(' && ch != ')' ||
                        open_ch == '{' && ch != '}' ||
                        open_ch == '[' && ch != ']') {
                            return 0;
                    }
                    break;
                }
        }
    }
    if (!is_empty(&s)) return 0;
    return 1;
}


int main(void) {
    char *p = "{ A[(i+1)]=0; }";
    
    if (check_matching(p) == 1) 
        printf("%s 괄호 검사 통과.\n", p);
    else
        printf("%s 괄호 검사 실패.\n", p);

    return 0;
}