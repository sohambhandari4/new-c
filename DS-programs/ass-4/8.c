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

// Function to display the elements of a linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to reverse a singly linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the link

        // Move to the next pair of nodes
        prev = current;
        current = next;
    }

    // The new head of the reversed list is the previous tail node
    head = prev;
    return head;
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
    displayList(head);

    // Reverse the linked list
    head = reverseList(head);

    printf("Reversed Linked List: ");
    displayList(head);

    // Free allocated memory (you should traverse and free memory properly in a real application)
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
