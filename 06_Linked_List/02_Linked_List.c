#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct 
    ListNode* link;
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

element get_entry(ListNode *L, int index) {
    element value;
    ListNode *node = L;
    for (int i = 0; i < index; i++) {
        if (node->link == NULL) {
            fprintf(stderr, "The node is pointing NULL\n");
            exit(1);
        }
        node = node->link;
    }
    value = node->data;

    return value;
}

int get_length(ListNode *head) {
    ListNode *node = head;
    int n = 0;
    while (node != NULL) {
        n++;
        node = node->link;
    }
    return n;
}

ListNode* search_list(ListNode *head, element x) {
    ListNode *p = head;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->link;
    }
    return NULL;
}

void print_list(ListNode *head) {
    int n = 0;
    for (ListNode *p = head; p != NULL; p = p->link) {
        n++;
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int main(void) {
    ListNode *head = NULL;

    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }

    int n = 4;
    printf("\n");
    printf("value of index %d = %d\n", n, get_entry(head, n));
    printf("length of the node is %d\n", get_length(head));

    // searching
    int sword = 3;
    if (search_list(head, sword) != NULL) {
        printf("we found %d in the list!\n", sword);
    } else {
        printf("we can't found %d in the list..\n", sword);
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }
    printf("length of the node is %d\n", get_length(head));



    return 0;
}