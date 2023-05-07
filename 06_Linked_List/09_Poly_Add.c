#include <stdio.h>
#include <stdlib.h>

// Node type
typedef struct ListNode {
    int coef;
    int expon;
    struct ListNode *link;
} ListNode;

// Linked list header
typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

// error function
void error(char *message) {
    fprintf(stderr,"%s\n", message);
    exit(1);
}

ListType* create() {
    ListType *plist = (ListType *)malloc(sizeof(ListType));

    plist->size = 0;
    plist->head = NULL;
    plist->tail = NULL;
    return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    if (temp == NULL) error("Memory allocation error.");
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    
    if (plist->size != 0) {
        plist->tail->link = temp;
        plist->tail = temp;
    } else {
        plist->head = temp;
        plist->tail = temp;
    }
        plist->size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;
    int sum;

    while (a && b) {
        if (a->expon == b->expon) {
            sum = a->coef + b->coef;
            if (sum != 0) insert_last(plist3, sum, a->expon);
            a = a->link;
            b = b->link;
        } else if (a->expon > b->expon) {
            insert_last(plist3, a->coef, a->expon);
            a = a->link;
        } else {
            insert_last(plist3, b->coef, b->expon);
            b = b->link;
        }
    }

    for (; a != NULL; a = a->link) {
        insert_last(plist3, a->coef, a->expon);
    }
    for (; b != NULL; b = b->link) {
        insert_last(plist3, b->coef, b->expon);
    }
}

void poly_print(ListType* plist) {
    ListNode* p = plist->head;

    printf("polynomial = ");
    for (; p; p = p->link) {
        if (p->coef < 0)
            printf("-");
        else
            printf("+");
        printf(" %d^%d ", p->coef, p->expon);
    }
    printf("\n");
}

int main(void) {
    ListType *a = create();
    ListType *b = create();

    insert_last(a, 3, 7);
    insert_last(a, 8, 5);
    insert_last(a, 3, 3);
    insert_last(a, 12, 2);
    insert_last(a, 7, 0);
    poly_print(a);

    insert_last(b, 2, 7);
    insert_last(b, 1, 6);
    insert_last(b, 21, 3);
    insert_last(b, 3, 1);
    poly_print(b);

    ListType *sum = create();
    poly_add(a, b, sum);
    poly_print(sum);

    return 0;
}

