#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary search tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
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

// Function to insert a new node into the binary search tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to display the elements of the binary search tree using in-order traversal
void displayInOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    displayInOrder(root->left);
    printf("%d ", root->data);
    displayInOrder(root->right);
}

int main() {
    struct TreeNode* root = NULL;

    // Insert elements into the binary search tree
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 2);
    root = insertNode(root, 7);

    printf("Binary Search Tree Elements (In-Order Traversal): ");
    displayInOrder(root);
    printf("\n");

    return 0;
}
