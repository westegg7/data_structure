#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

/*
    원형큐의 구현 (p.157)
*/
typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} QueueType;

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void init_queue(QueueType* q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(QueueType* q) {
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

int is_full(QueueType* q) {
    if (q->front - 1 == q->rear % MAX_QUEUE_SIZE)
        return 1;
    else
        return 0;
}

void queue_print(QueueType* q) {
    printf("QUEUE(front=%d, rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n"); 
}

void enqueue(QueueType* q, element data) {
    if (is_full(q)) 
        error("The Queue is full.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) 
        error("The Queue is empty.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType* q) {
    if (is_empty(q)) 
        error("The Queue is empty.");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main() {



    return 0;
}