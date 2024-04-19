#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define a structure for the stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void Initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int IsEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int IsFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void Push(struct Stack* stack, int element) {
    if (IsFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    stack->data[++(stack->top)] = element;
}

// Function to pop an element from the stack
int Pop(struct Stack* stack) {
    if (IsEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    return stack->data[(stack->top)--];
}

// Function to display the elements of the stack
void Display(struct Stack* stack) {
    if (IsEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Function to peek at the top element of the stack
int Peek(struct Stack* stack) {
    if (IsEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    return stack->data[stack->top];
}

int main() {
    struct Stack stack;
    Initialize(&stack);

    // Push some elements onto the stack
    Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);

    Display(&stack);

    // Pop an element from the stack
    int poppedElement = Pop(&stack);
    printf("Popped element: %d\n", poppedElement);

    Display(&stack);

    // Peek at the top element of the stack
    int topElement = Peek(&stack);
    printf("Top element: %d\n", topElement);

    return 0;
}
