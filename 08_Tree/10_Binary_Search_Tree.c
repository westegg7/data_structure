#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* search_recursive(TreeNode *node, int key) {
    if (node == NULL) return NULL;
    if (key == node->key) return node;
    else if (key < node->key) 
        return search_recursive(node->left, key);
    else
        return search_recursive(node->right, key);
}

TreeNode* search_loop(TreeNode *node, int key) {
    while (node != NULL) {
        if (key == node->key)
            return node;
        if (key < node->key) 
            node = node->left;
        else 
            node = node->right;
    }
    return NULL;    // 탐색에 실패했을 경우 NULL 반환
}

TreeNode* new_node(int item) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = item;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insert_node(TreeNode *node, int key) {
    if (node == NULL) return new_node(key);

    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);

    return node;
}

TreeNode* min_value_node(TreeNode *node) {
    TreeNode *current = node;

    while (current->left != NULL) 
        current = current->left;

    return current;
}

TreeNode* delete_node(TreeNode *root, int key) {
    if (root == NULL) return root;
    // 키가 루트보다 작으면 왼쪽 서브트리에 있는 것임
    if (key < root->key)
        root->left = delete_node(root->left, key);
    // 키가 루트보다 크면 오른쪽 서브트리에 있는 것임
    else if (key > root->key) 
        root->right = delete_node(root->right, key);
    // 키가 루트와 같으면 이 노드를 삭제
    else {
        // 단말노드이거나, 하나의 서브트리만 가지는 경우
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        // 두개의 서브트리를 가지는 경우
        TreeNode *temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

int main(void) {
    TreeNode *root = NULL;
    TreeNode *tmp = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    root = delete_node(root, 30);

    printf("이진 탐색 트리 중위 순회 결과 \n");
    inorder(root);
    printf("\n\n");

    int n = 30;
    if (search_loop(root, n) != NULL) 
        printf("이진 탐색 트리에서 %d을 발견함 \n", n);
    else
        printf("이진 탐색 트리에서 %d을 발견못함 \n", n);

    return 0;
}