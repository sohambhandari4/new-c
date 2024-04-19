#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular singly linked list
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

// Function to display the elements of the circular linked list
void displayList(struct Node* head) {
    struct Node* current = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("NULL (End of List)\n");
}

int main() {
    // Initialize an empty circular linked list
    struct Node* head = NULL;

    // Create nodes and add them to the circular linked list
    struct Node* node1 = createNode(10);
    struct Node* node2 = createNode(20);
    struct Node* node3 = createNode(30);

    // Link the nodes to form a circular list
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = head; // Point the last node back to the first node

    // Display the circular linked list
    printf("Circular Linked List: ");
    displayList(head);

    // Free allocated memory (you should traverse and free memory properly in a real application)
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
