#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 10

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


int main(void) {
    QueueType queue;
    int element;

    init_queue(&queue);
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        // 20%의 확률로 enqueue.
        if (rand() % 5 == 0) {
            enqueue(&queue, rand()%100);
        }
        queue_print(&queue);
        // 10%의 확률로 dequeue. -> 큐가 가득 찰 확률이 높다.
        if (rand() % 10 == 0) {
            int data = dequeue(&queue);
        }
        queue_print(&queue);
    }


    return 0;
}