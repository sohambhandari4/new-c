#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the queue
struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
};

// Initialize the queue
void Initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
int IsEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Check if the queue is full
int IsFull(struct Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Insert an element into the queue
void Insert(struct Queue* queue, int element) {
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

// Delete an element from the queue
int Delete(struct Queue* queue) {
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

// Display the elements of the queue
void Display(struct Queue* queue) {
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

// Peek at the front element of the queue
int Peek(struct Queue* queue) {
    if (IsEmpty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1; // Return -1 to indicate an error
    }

    return queue->data[queue->front];
}

int main() {
    struct Queue queue;
    Initialize(&queue);

    // Insert some elements into the queue
    Insert(&queue, 10);
    Insert(&queue, 20);
    Insert(&queue, 30);

    Display(&queue);

    // Delete an element from the queue
    int deletedElement = Delete(&queue);
    printf("Deleted element: %d\n", deletedElement);

    Display(&queue);

    // Peek at the front element of the queue
    int frontElement = Peek(&queue);
    printf("Front element: %d\n", frontElement);

    return 0;
}
