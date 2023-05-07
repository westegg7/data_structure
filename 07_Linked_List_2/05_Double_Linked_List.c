#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<-| |%d| |-> ", p->data);
    }
    printf("\n");
}

void dinsert(DListNode* before, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* node) {
    if (node == head) return;
    node->llink->rlink = node->rlink;
    node->rlink->llink = node->llink;
    free(node);
}

int main(void) {
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    printf("추가 단계\n");
    for (int i = 0; i < 5; i++) {
        dinsert(head, i);
        print_dlist(head);
    }
    printf("삭제단계\n");
    for (int i = 0; i < 5; i++) {
        print_dlist(head);
        ddelete(head, head->rlink);
    }
    free(head);


    return 0;
}




