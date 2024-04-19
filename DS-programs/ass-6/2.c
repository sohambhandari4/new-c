#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Define a structure for the dynamic queue
struct DynamicQueue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Initialize the dynamic queue
void Initialize(struct DynamicQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if the dynamic queue is empty
int IsEmpty(struct DynamicQueue* queue) {
    return (queue->front == NULL);
}

// Insert an element into the dynamic queue
void Insert(struct DynamicQueue* queue, int element) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert.\n");
        return;
    }

    newNode->data = element;
    newNode->next = NULL;

    if (IsEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Delete an element from the dynamic queue
int Delete(struct DynamicQueue* queue) {
    int deletedElement;

    if (IsEmpty(queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return -1; // Return -1 to indicate an error
    }

    struct QueueNode* temp = queue->front;
    deletedElement = temp->data;

    if (queue->front == queue->rear) {
        // Last element in the queue
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    return deletedElement;
}

// Display the elements of the dynamic queue
void Display(struct DynamicQueue* queue) {
    struct QueueNode* current = queue->front;

    if (IsEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Peek at the front element of the dynamic queue
int Peek(struct DynamicQueue* queue) {
    if (IsEmpty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1; // Return -1 to indicate an error
    }

    return queue->front->data;
}

int main() {
    struct DynamicQueue queue;
    Initialize(&queue);

    // Insert some elements into the dynamic queue
    Insert(&queue, 10);
    Insert(&queue, 20);
    Insert(&queue, 30);

    Display(&queue);

    // Delete an element from the dynamic queue
    int deletedElement = Delete(&queue);
    printf("Deleted element: %d\n", deletedElement);

    Display(&queue);

    // Peek at the front element of the dynamic queue
    int frontElement = Peek(&queue);
    printf("Front element: %d\n", frontElement);

    return 0;
}
