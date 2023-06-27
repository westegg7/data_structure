#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} element;

typedef struct TreeNode {
    element key;
    TreeNode *left, *right;
} TreeNode;

int compare(element n1, element n2) {
    return strcmp(n1.word, n2.word);
}

void display(TreeNode *p) {
    if (p) {
        printf("(");
        printf(p->left);
        printf("%s:%s", p->key.word, p->key.meaning);
        display(p->right);
        printf(")");
    }
}

TreeNode * search(TreeNode *root, element key) {
    TreeNode *p = root;

    while(p != NULL) {
        if (compare(key, p->key) < 0)
            p = p->left;
        else if (compare(key, p->key) > 0)
            p = p->right;
        else 
            return p;
    }
    return p;
}

TreeNode * new_node(element item) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = item;
    node->left = node->right = NULL;
    return node;
}

TreeNode * insert(TreeNode *root, element key) {
    if (root == NULL) return new_node(key);

    if (compare(key, root->key) < 0)
        root->left = insert(root->left, key);
    else if (compare(key, root->key) > 0) 
        root->right = insert(root->right, key);
        
    return root;
}

TreeNode * delete(TreeNode *root, element key) {
    if (root == NULL) return root;
    if (compare(key, root->key) < 0)
        root->left = delete(root->left, key);
    else if (compare(key, root->key) > 0) 
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL) {
            root = root->right;
        }
    }
}


