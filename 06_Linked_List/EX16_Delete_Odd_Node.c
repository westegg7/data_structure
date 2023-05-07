#include <stdio.h>
#include <stdlib.h>


typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode *head, int value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, int value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;

    return head;
}

ListNode* delete_first(ListNode *head) {
    if (head == NULL) {
        printf("the linked list is empty.\n");
        return head;
    }
    ListNode *removed;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode *head, ListNode *pre) {
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);

    return head;
}

void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

ListNode* delete_odd_node(ListNode* head) {
    ListNode* p = head;
    ListNode* pre = NULL;
    ListNode* removed = NULL;
    int n = 0;
    
    while (p != NULL) {
        n++;
        if (n == 1) {
            removed = p;
            p = p->link;
            head = p;
            free(removed);
        } else if (n % 2 == 1) {
            removed = p;
            pre->link = p->link;
            p = pre->link;
            free(removed);
        } else {
            pre = p;
            p = p->link;
        }
    }
    return head;
}

int main(void) {
    ListNode* plist = NULL;
    for (int i = 10; i > 0; i--) {
        plist = insert_first(plist, i);
    }
    print_list(plist);

    plist = delete_odd_node(plist);
    print_list(plist);

    return 0;
}


