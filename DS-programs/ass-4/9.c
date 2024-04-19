#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the elements of a linked list in reverse order
void displayReverse(struct Node* head) {
    if (head == NULL) {
        return; // Base case: End of the list
    }
    
    displayReverse(head->next); // Recursively display the rest of the list
    printf("%d -> ", head->data);
}

int main() {
    // Initialize a linked list
    struct Node* head = NULL;

    // Create nodes and add them to the linked list
    struct Node* node1 = createNode(10);
    struct Node* node2 = createNode(20);
    struct Node* node3 = createNode(30);

    head = node1;
    node1->next = node2;
    node2->next = node3;

    printf("Original Linked List: ");
    displayReverse(head);
    printf("NULL\n");

    // Free allocated memory (you should traverse and free memory properly in a real application)
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
