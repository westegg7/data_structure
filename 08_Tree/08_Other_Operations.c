#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a, b) ((a > b) ? a : b)

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int get_node_count(TreeNode *node) {
    int count = 0;
    if (node != NULL) {
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    }
    return count;
}

int get_leaf_count(TreeNode *node) {
    int count = 0;

    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) 
            return 1;
        else 
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
    }
    return count;
}

int get_nonleaf_count(TreeNode *node) {
    int count = 0;

    if (node != NULL) {
        if (node->left != NULL || node->right != NULL)
            count = 1 + get_nonleaf_count(node->left) + get_nonleaf_count(node->right);
    }
    return count;
}

int get_height(TreeNode *node) {
    int height = 0;

    if (node != NULL) {
        height = 1 + max(get_height(node->left), get_height(node->right));
    }
    return height;
}

bool is_equal(TreeNode *t1, TreeNode *t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->data == t2->data) && is_equal(t1->left, t2->left) && is_equal(t1->right, t2->right);
}

//     15
//  4      20
//1     16    25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;

TreeNode t1 = { 1, NULL, NULL };
TreeNode t2 = { 4, &t1, NULL };
TreeNode t3 = { 16, NULL, NULL };
TreeNode t4 = { 25, NULL, NULL };
TreeNode t5 = { 20, &t3, &t4 };
TreeNode t6 = { 15, &t2, &t5 };
TreeNode *root2 = &t6;

int main(void) {
    setbuf(stdout, NULL);
    printf("전체 노드의 개수 : %d\n", get_node_count(root));
    printf("단말 노드의 개수 : %d\n", get_leaf_count(root));
    printf("비단말 노드의 개수 : %d\n", get_nonleaf_count(root));
    printf("트리의 높이 : %d\n", get_height(root));
    printf("root와 root2는 동일한 데이터를 가진 트리인가? : ");
    if (is_equal(root, root2)) 
        printf("Yes.\n");
    else 
        printf("No.\n");

    return 0;
}