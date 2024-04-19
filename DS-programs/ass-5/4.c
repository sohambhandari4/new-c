#include <stdio.h>
#include <stdlib.h>

// Static Stack Implementation
#define MAX_SIZE 100
struct StaticStack {
    int data[MAX_SIZE];
    int top;
};

void StaticStackInitialize(struct StaticStack* stack) {
    stack->top = -1;
}

int StaticStackIsEmpty(struct StaticStack* stack) {
    return (stack->top == -1);
}

int StaticStackIsFull(struct StaticStack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void StaticStackPush(struct StaticStack* stack, int number) {
    if (StaticStackIsFull(stack)) {
        printf("Static Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++(stack->top)] = number;
}

int StaticStackPop(struct StaticStack* stack) {
    if (StaticStackIsEmpty(stack)) {
        printf("Static Stack is empty. Cannot pop.\n");
        return -1; // Return -1 to indicate an error
    }
    return stack->data[(stack->top)--];
}

// Dynamic Stack Implementation
struct DynamicNode {
    int data;
    struct DynamicNode* next;
};

struct DynamicStack {
    struct DynamicNode* top;
};

void DynamicStackInitialize(struct DynamicStack* stack) {
    stack->top = NULL;
}

int DynamicStackIsEmpty(struct DynamicStack* stack) {
    return (stack->top == NULL);
}

void DynamicStackPush(struct DynamicStack* stack, int number) {
    struct DynamicNode* newNode = (struct DynamicNode*)malloc(sizeof(struct DynamicNode));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push.\n");
        return;
    }
    newNode->data = number;
    newNode->next = stack->top;
    stack->top = newNode;
}

int DynamicStackPop(struct DynamicStack* stack) {
    if (DynamicStackIsEmpty(stack)) {
        printf("Dynamic Stack is empty. Cannot pop.\n");
        return -1; // Return -1 to indicate an error
    }
    struct DynamicNode* poppedNode = stack->top;
    int poppedNumber = poppedNode->data;
    stack->top = poppedNode->next;
    free(poppedNode);
    return poppedNumber;
}

// Function to reverse a number using a static stack
int ReverseNumberStaticStack(int number) {
    struct StaticStack stack;
    StaticStackInitialize(&stack);

    // Push each digit of the number onto the stack
    while (number > 0) {
        StaticStackPush(&stack, number % 10);
        number /= 10;
    }

    // Pop digits from the stack to reverse the number
    int reversedNumber = 0;
    int multiplier = 1;
    while (!StaticStackIsEmpty(&stack)) {
        reversedNumber = reversedNumber * 10 + StaticStackPop(&stack);
    }

    return reversedNumber;
}

// Function to reverse a number using a dynamic stack
int ReverseNumberDynamicStack(int number) {
    struct DynamicStack stack;
    DynamicStackInitialize(&stack);

    // Push each digit of the number onto the stack
    while (number > 0) {
        DynamicStackPush(&stack, number % 10);
        number /= 10;
    }

    // Pop digits from the stack to reverse the number
    int reversedNumber = 0;
    int multiplier = 1;
    while (!DynamicStackIsEmpty(&stack)) {
        reversedNumber = reversedNumber * 10 + DynamicStackPop(&stack);
    }

    return reversedNumber;
}

int main() {
    int inputNumber = 12345;

    // Reverse the number using a static stack
    int reversedStatic = ReverseNumberStaticStack(inputNumber);
    printf("Reversed Number (Static Stack): %d\n", reversedStatic);

    // Reset the number
    inputNumber = 12345;

    // Reverse the number using a dynamic stack
    int reversedDynamic = ReverseNumberDynamicStack(inputNumber);
    printf("Reversed Number (Dynamic Stack): %d\n", reversedDynamic);

    return 0;
}
