#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_SIZE 100

typedef struct {
    int data;
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

    while((i != 1) && (item.data > h->heap[i/2].data)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    parent = 1;
    child = 2;

    temp = h->heap[(h->heap_size)--];

    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].data < h->heap[child + 1].data)) 
            child++;
        if (temp.data > h->heap[child].data) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;

    return item;
}

int main() {
    element datas[] = { 10, 40, 30, 5, 12, 6, 15, 9, 60 };
    int n = 9;

    HeapType* h = create();
    init(h);

    for (int i = 0; i < n; i++) {
        insert_max_heap(h, datas[i]);
    }
    for (int i = 0; i < n+1; i++) {
        element e = h->heap[i];
        printf("%d ", e.data);
    }
    printf("\n");


    return 0;
}
