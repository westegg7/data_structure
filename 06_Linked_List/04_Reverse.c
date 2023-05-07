#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode* insert_first(ListNode *head, int value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode *head) {
    int n = 0;
    for (ListNode *p = head; p != NULL; p = p->link) {
        n++;
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

ListNode* reverse(ListNode *head) {
    ListNode *p, *q, *r;

    p = head;   // p는 역순으로 바꿀 리스트
    q = NULL;   // q는 역순으로 바꿀 노드
    while (p != NULL) {
        r = q;  // r은 역순으로 된 리스트. r은 q를, q는 p를 차례로 따라간다.
        q = p;
        p = p->link;
        q->link = r;
    }

    return q;
}

int main(void) {
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = reverse(head1);
    print_list(head2);

    return 0;
}