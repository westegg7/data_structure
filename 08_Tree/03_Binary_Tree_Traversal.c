#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//     15
//   4     20
// 1     16  25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;

// 중위순회
void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

// 전위순회
void preorder(TreeNode *root) {
    if (root != NULL) {
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 후위순회
void postorder(TreeNode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->data);
    }
}

int main(void) {
    printf("Inorder Traversal = ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal = ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal = ");
    postorder(root);
    printf("\n");

    return 0;
}


