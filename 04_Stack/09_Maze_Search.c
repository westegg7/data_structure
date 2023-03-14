#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6

typedef struct {
    int r;
    int c;
} element;
typedef struct {
    element stack[MAZE_SIZE];
    int top;
} Stacktype;

void init_stack(Stacktype *s) {
    s->top = -1;
}

int is_empty(Stacktype *s) {
    return (s->top == -1);
}

int is_full(Stacktype *s) {
    return (s->top == MAZE_SIZE - 1);
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

element here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1', },
    {'e', '0', '1', '0', '0', '1', },
    {'1', '0', '0', '0', '1', '1', },
    {'1', '0', '1', '0', '1', '1', },
    {'1', '0', '1', '0', '0', 'x', },
    {'1', '1', '1', '1', '1', '1', }
};


// 위치를 스택에 삽입
void push_loc(Stacktype* s, int r, int c) {
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

// 미로를 화면에 출력
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++) {
            printf("%c ", maze[r][c]);
        }
        printf("\n");
    }
}

int main(void) {
    int r, c;
    here = entry;
    Stacktype s;
    init_stack(&s);

    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);
        
        if (is_empty(&s)) {
            printf("Failed.\n");
            return -1;
        } else {
            here = pop(&s);
        }
    }


    return 0;
}