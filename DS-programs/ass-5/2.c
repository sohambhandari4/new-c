#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the stack
struct Stack {
    struct Node* top;
};

// Function to initialize the stack
void Initialize(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int IsEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void Push(struct Stack* stack, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push.\n");
        return;
    }

    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int Pop(struct Stack* stack) {
    if (IsEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    struct Node* poppedNode = stack->top;
    int poppedElement = poppedNode->data;
    stack->top = poppedNode->next;
    free(poppedNode);
    return poppedElement;
}

// Function to display the elements of the stack
void Display(struct Stack* stack) {
    if (IsEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to peek at the top element of the stack
int Peek(struct Stack* stack) {
    if (IsEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    return stack->top->data;
}

// Function to free the memory used by the stack
void FreeStack(struct Stack* stack) {
    while (!IsEmpty(stack)) {
        Pop(stack);
    }
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

    // Free the memory used by the stack
    FreeStack(&stack);

    return 0;
}
