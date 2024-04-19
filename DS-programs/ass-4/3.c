#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
    newNode->prev = NULL;
    return newNode;
}

// Function to display the elements of the doubly linked list (forward)
void displayListForward(struct Node* head) {
    struct Node* current = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }

    printf("NULL (End of List)\n");
}

int main() {
    // Initialize an empty doubly linked list
    struct Node* head = NULL;

    // Create nodes and add them to the doubly linked list
    struct Node* node1 = createNode(10);
    struct Node* node2 = createNode(20);
    struct Node* node3 = createNode(30);

    // Link the nodes to form a doubly linked list
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node2->prev = node1;
    node3->prev = node2;

    // Display the doubly linked list (forward)
    printf("Doubly Linked List (Forward): ");
    displayListForward(head);

    // Free allocated memory (you should traverse and free memory properly in a real application)
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
