#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the linked list

// Define a structure for a node in the static linked list
struct Node {
    int data;
    int next; // Index of the next node in the array
};

// Initialize the array for the linked list
struct Node staticLinkedList[MAX_SIZE];

int listSize = 0; // Current size of the linked list
int freeList = 0; // Index of the first free node in the array

// Function to initialize the static linked list
void initializeList() {
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        staticLinkedList[i].next = i + 1;
    }
    staticLinkedList[MAX_SIZE - 1].next = -1; // Mark the end of the list
    freeList = 0; // Initialize the free list
}

// Function to append a new node with the given data
void append(int data) {
    if (listSize >= MAX_SIZE) {
        printf("Static linked list is full. Cannot append.\n");
        return;
    }

    int newNodeIndex = freeList;
    freeList = staticLinkedList[freeList].next; // Update the free list

    staticLinkedList[newNodeIndex].data = data;
    staticLinkedList[newNodeIndex].next = -1; // Mark the new node as the end of the list

    if (listSize == 0) {
        // If the list is empty, set the new node as the head of the list
        freeList = newNodeIndex;
    } else {
        // Find the last node and update its next pointer
        int current = freeList;
        while (staticLinkedList[current].next != -1) {
            current = staticLinkedList[current].next;
        }
        staticLinkedList[current].next = newNodeIndex;
    }

    listSize++;
}

// Function to insert a new node with the given data at a specific position
void insert(int data, int position) {
    if (position < 0 || position > listSize) {
        printf("Invalid position for insertion.\n");
        return;
    }

    if (listSize >= MAX_SIZE) {
        printf("Static linked list is full. Cannot insert.\n");
        return;
    }

    int newNodeIndex = freeList;
    freeList = staticLinkedList[freeList].next; // Update the free list

    staticLinkedList[newNodeIndex].data = data;

    if (position == 0) {
        // Insert at the beginning
        staticLinkedList[newNodeIndex].next = freeList;
        freeList = newNodeIndex; // Update the head
    } else {
        // Insert at a specific position
        int current = freeList;
        for (int i = 0; i < position - 1; i++) {
            current = staticLinkedList[current].next;
        }
        staticLinkedList[newNodeIndex].next = staticLinkedList[current].next;
        staticLinkedList[current].next = newNodeIndex;
    }

    listSize++;
}

// Function to display the elements of the linked list
void display() {
    if (listSize == 0) {
        printf("Static linked list is empty.\n");
        return;
    }

    int current = freeList;
    while (current != -1) {
        printf("%d -> ", staticLinkedList[current].data);
        current = staticLinkedList[current].next;
    }
    printf("NULL\n");
}

int main() {
    initializeList();

    // Append some nodes
    append(10);
    append(20);
    append(30);

    // Display the linked list
    printf("Linked List after Append: ");
    display();

    // Insert a node at a specific position
    insert(15, 1);

    // Display the linked list after insertion
    printf("Linked List after Insertion: ");
    display();

    return 0;
}
