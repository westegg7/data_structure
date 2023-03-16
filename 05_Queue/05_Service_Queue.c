#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 10

/*
    원형큐의 구현 (p.157)
*/
typedef struct {
    int id;
    int arrival_time;
    int service_time;
} element;

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
    int minutes = 60;
    int total_wait = 0;
    int total_customer = 0;
    int service_time = 0;
    int service_customer = 0;
    QueueType queue;
    init_queue(&queue);

    srand(time(NULL));

    for (int clock = 0; clock < minutes; clock++) {
        printf("현재시각 = %d\n", clock);
        if (rand() % 10 < 3) {
            element customer;
            customer.id = total_customer++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 5;
            enqueue(&queue, customer);
            printf("고객 %d가 %d분에 들어옵니다. 업무처리시간= %d분\n", customer.id, customer.arrival_time, customer.service_time);
        }
        if (service_time > 0) {
            printf("고객 %d 업무처리중입니다.\n", service_customer);
            service_time--;
        } else {
            if (!is_empty(&queue)) {
                element customer;
                customer = dequeue(&queue);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("고객 %d가 %d분에 업무를 시작합니다. 대기시간 = %d분\n", service_customer, clock, clock - customer.arrival_time);
                total_wait += (clock - customer.arrival_time);
            }
        }
    }
    printf("전체 대기시간 : %d분.\n", total_wait);


    return 0;
}