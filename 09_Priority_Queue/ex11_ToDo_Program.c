#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_SIZE 100

typedef struct {
    char todo[50];
    int priority;
} element;

typedef struct {
    element heap[MAX_HEAP_SIZE];
    int heap_size;
} HeapType;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.priority > h->heap[i/2].priority)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
    int parent, child;
    element item;
    element temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];

    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].priority < h->heap[child + 1].priority)) 
            child++;
        if (temp.priority > h->heap[child].priority) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;

    return item;
}


int main() {
    setbuf(stdout, NULL);
    char input;
    char c;
    element temp;

    HeapType *h = create();
    init(h);

    while (1) {
        printf("삽입(i), 삭제(d): ");
        scanf("%c", &input);
        
        switch (input) {
            case 'i': 
                printf("할일 : ");
                scanf("%s", temp.todo);
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("우선순위 : ");
                scanf("%d", &temp.priority);
                while ((c = getchar()) != '\n' && c != EOF) {}
                insert_max_heap(h, temp);
                break;
            case 'd': 
                if (h->heap_size <= 0) {
                    printf("비어있음\n");
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    break;
                }
                temp = delete_max_heap(h);
                printf("제일 우선 순위가 높은 일은 \"%s\". 우선순위 : %d", temp.todo, temp.priority);
                while ((c = getchar()) != '\n' && c != EOF) {}
                break;
            case 'q':
                printf("빠잉!\n");
                return 0;
            default:
                printf("올바른 입력을 부탁!.\n");
                while ((c = getchar()) != '\n' && c != EOF) {}
                break;
        }
        printf("\n");
    }
    
    return 0;
}