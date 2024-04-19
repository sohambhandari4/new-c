#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the circular queue
struct CircularQueue {
    int data[MAX_SIZE];
    int front;
    int rear;
};

// Initialize the circular queue
void Initialize(struct CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the circular queue is empty
int IsEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

// Check if the circular queue is full
int IsFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Insert an element into the circular queue
void Insert(struct CircularQueue* queue, int element) {
    if (IsFull(queue)) {
        printf("Queue is full. Cannot insert.\n");
        return;
    }

    if (IsEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->data[queue->rear] = element;
}

// Delete an element from the circular queue
int Delete(struct CircularQueue* queue) {
    int deletedElement;

    if (IsEmpty(queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return -1; // Return -1 to indicate an error
    }

    deletedElement = queue->data[queue->front];

    if (queue->front == queue->rear) {
        // Last element in the queue
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return deletedElement;
}

// Display the elements of the circular queue
void Display(struct CircularQueue* queue) {
    int i;

    if (IsEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents: ");
    i = queue->front;
    do {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

// Peek at the front element of the circular queue
int Peek(struct CircularQueue* queue) {
    if (IsEmpty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1; // Return -1 to indicate an error
    }

    return queue->data[queue->front];
}

int main() {
    struct CircularQueue queue;
    Initialize(&queue);

    // Insert some elements into the circular queue
    Insert(&queue, 10);
    Insert(&queue, 20);
    Insert(&queue, 30);

    Display(&queue);

    // Delete an element from the circular queue
    int deletedElement = Delete(&queue);
    printf("Deleted element: %d\n", deletedElement);

    Display(&queue);

    // Peek at the front element of the circular queue
    int frontElement = Peek(&queue);
    printf("Front element: %d\n", frontElement);

    return 0;
}
