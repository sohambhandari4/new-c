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

// Function to find the intersection point of two linked lists
struct Node* findIntersection(struct Node* list1, struct Node* list2) {
    int len1 = 0;
    int len2 = 0;
    struct Node* current1 = list1;
    struct Node* current2 = list2;

    // Calculate the lengths of the two lists
    while (current1 != NULL) {
        len1++;
        current1 = current1->next;
    }

    while (current2 != NULL) {
        len2++;
        current2 = current2->next;
    }

    // Reset the pointers to the beginning of the lists
    current1 = list1;
    current2 = list2;

    // Move the pointer of the longer list by the difference in lengths
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            current1 = current1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            current2 = current2->next;
        }
    }

    // Traverse both lists until an intersection point is found
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2) {
            return current1; // Intersection found
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return NULL; // No intersection found
}

int main() {
    // Initialize two linked lists
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Create nodes and add them to the linked lists
    struct Node* node1 = createNode(10);
    struct Node* node2 = createNode(20);
    struct Node* node3 = createNode(30);

    list1 = node1;
    node1->next = node2;
    node2->next = node3;

    struct Node* node4 = createNode(40);
    struct Node* node5 = createNode(50);

    list2 = node4;
    node4->next = node5;
    node5->next = node2; // Intersection point with list1

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    struct Node* intersection = findIntersection(list1, list2);

    if (intersection != NULL) {
        printf("Intersection point data: %d\n", intersection->data);
    } else {
        printf("No intersection found.\n");
    }

    // Free allocated memory (you should traverse and free memory properly in a real application)
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    return 0;
}
