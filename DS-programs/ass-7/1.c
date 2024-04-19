#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) 
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to display the elements of the binary tree using in-order traversal
void displayInOrder(struct TreeNode* root)
 {
    if (root == NULL) {
        return;
    }
    displayInOrder(root->left);
    printf("%d ", root->data);
    displayInOrder(root->right);
}

int main()
 {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Binary Tree Elements (In-Order Traversal): ");
    displayInOrder(root);
    printf("\n");

    return 0;
}
