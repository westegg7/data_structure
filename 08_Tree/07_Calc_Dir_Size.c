#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a > b) ? a : b)

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int total_size = 0;

int calc_dir_size(TreeNode *root) {
    int left_size, right_size;
    if (root == NULL) 
        return 0;
    left_size = calc_dir_size(root->left);
    right_size = calc_dir_size(root->right);
    return (root->data + left_size + right_size);
}

//             root
//  music(50kb)   pics(100kb)
//            gif(500kb)  jpg(200kb)
int main(void) {
    TreeNode n4 = {500, NULL, NULL};
    TreeNode n5 = {200, NULL, NULL};
    TreeNode n3 = {100, &n4, &n5};
    TreeNode n2 = {50, NULL, NULL};
    TreeNode n1 = {0, &n2, &n3};

    printf("디렉토리의 크기 = %d\n", calc_dir_size(&n1));

    return 0;
}