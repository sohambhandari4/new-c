#include <stdio.h>
#include <stdlib.h>

// Define a structure for the circular queue node
struct CircularQueueNode {
    int data;
    struct CircularQueueNode* next;
};

// Define a structure for the dynamic circular queue
struct DynamicCircularQueue {
    struct CircularQueueNode* front;
    struct CircularQueueNode* rear;
};

// Initialize the dynamic circular queue
void Initialize(struct DynamicCircularQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if the dynamic circular queue is empty
int IsEmpty(struct DynamicCircularQueue* queue) {
    return (queue->front == NULL);
}

// Insert an element into the dynamic circular queue
void Insert(struct DynamicCircularQueue* queue, int element) {
    struct CircularQueueNode* newNode = (struct CircularQueueNode*)malloc(sizeof(struct CircularQueueNode));
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

// Delete an element from the dynamic circular queue
int Delete(struct DynamicCircularQueue* queue) {
    int deletedElement;

    if (IsEmpty(queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return -1; // Return -1 to indicate an error
    }

    struct CircularQueueNode* temp = queue->front;
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

// Display the elements of the dynamic circular queue
void Display(struct DynamicCircularQueue* queue) {
    struct CircularQueueNode* current = queue->front;

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

// Peek at the front element of the dynamic circular queue
int Peek(struct DynamicCircularQueue* queue) {
    if (IsEmpty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1; // Return -1 to indicate an error
    }

    return queue->front->data;
}

int main() {
    struct DynamicCircularQueue queue;
    Initialize(&queue);

    // Insert some elements into the dynamic circular queue
    Insert(&queue, 10);
    Insert(&queue, 20);
    Insert(&queue, 30);

    Display(&queue);

    // Delete an element from the dynamic circular queue
    int deletedElement = Delete(&queue);
    printf("Deleted element: %d\n", deletedElement);

    Display(&queue);

    // Peek at the front element of the dynamic circular queue
    int frontElement = Peek(&queue);
    printf("Front element: %d\n", frontElement);

    return 0;
}
