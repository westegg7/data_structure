#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
    element data;
    struct QueueNode* link;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} LinkedQueueType;

void init(LinkedQueueType* q) {
    q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
    return (q->front == NULL);
}

void enqueue(LinkedQueueType* q, element data) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = data;
    node->link = NULL;

    if (is_empty(q)) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->link = node;
        q->rear = node;
    }
}

element dequeue(LinkedQueueType* q) {
    if (is_empty(q)) {
        fprintf(stderr, "queue is empty.\n");
        exit(1);
    } else {
        QueueNode* temp = q->front;
        element data = temp->data;
        q->front = q->front->link;
        if (q->front == NULL) 
            q->rear = NULL;
        free(temp);
        return data;
    }
}

void print_queue(LinkedQueueType* q) {
    QueueNode* p;
    for (p = q->front; p != NULL; p = p->link) 
        printf("%d->", p->data);
    printf("\n");
}


int main(void) {
    LinkedQueueType queue;

    init(&queue);
    
    enqueue(&queue, 10);
    print_queue(&queue);
    enqueue(&queue, 20);
    print_queue(&queue);
    enqueue(&queue, 30);
    print_queue(&queue);
    enqueue(&queue, 40);
    print_queue(&queue);
    enqueue(&queue, 50);
    print_queue(&queue);

    dequeue(&queue);
    print_queue(&queue);
    dequeue(&queue);
    print_queue(&queue);
    dequeue(&queue);
    print_queue(&queue);
    dequeue(&queue);
    print_queue(&queue);
    dequeue(&queue);
    print_queue(&queue);

    return 0;
}
