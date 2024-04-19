#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Static Stack Implementation
#define MAX_SIZE 100
struct StaticStack {
    char data[MAX_SIZE];
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

void StaticStackPush(struct StaticStack* stack, char character) {
    if (StaticStackIsFull(stack)) {
        printf("Static Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++(stack->top)] = character;
}

char StaticStackPop(struct StaticStack* stack) {
    if (StaticStackIsEmpty(stack)) {
        printf("Static Stack is empty. Cannot pop.\n");
        return '\0'; // Return null character to indicate an error
    }
    return stack->data[(stack->top)--];
}

// Dynamic Stack Implementation
struct DynamicNode {
    char data;
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

void DynamicStackPush(struct DynamicStack* stack, char character) {
    struct DynamicNode* newNode = (struct DynamicNode*)malloc(sizeof(struct DynamicNode));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push.\n");
        return;
    }
    newNode->data = character;
    newNode->next = stack->top;
    stack->top = newNode;
}

char DynamicStackPop(struct DynamicStack* stack) {
    if (DynamicStackIsEmpty(stack)) {
        printf("Dynamic Stack is empty. Cannot pop.\n");
        return '\0'; // Return null character to indicate an error
    }
    struct DynamicNode* poppedNode = stack->top;
    char poppedCharacter = poppedNode->data;
    stack->top = poppedNode->next;
    free(poppedNode);
    return poppedCharacter;
}

// Function to reverse a string using a static stack
void ReverseStringStaticStack(char* str) {
    struct StaticStack stack;
    StaticStackInitialize(&stack);

    // Push each character onto the stack
    for (int i = 0; i < strlen(str); i++) {
        StaticStackPush(&stack, str[i]);
    }

    // Pop characters from the stack to reverse the string
    for (int i = 0; i < strlen(str); i++) {
        str[i] = StaticStackPop(&stack);
    }
}

// Function to reverse a string using a dynamic stack
void ReverseStringDynamicStack(char* str) {
    struct DynamicStack stack;
    DynamicStackInitialize(&stack);

    // Push each character onto the stack
    for (int i = 0; i < strlen(str); i++) {
        DynamicStackPush(&stack, str[i]);
    }

    // Pop characters from the stack to reverse the string
    for (int i = 0; i < strlen(str); i++) {
        str[i] = DynamicStackPop(&stack);
    }
}

int main() {
    char inputString[] = "Hello, World!";

    // Reverse the string using a static stack
    ReverseStringStaticStack(inputString);
    printf("Reversed String (Static Stack): %s\n", inputString);

    // Reset the string
    strcpy(inputString, "Hello, World!");

    // Reverse the string using a dynamic stack
    ReverseStringDynamicStack(inputString);
    printf("Reversed String (Dynamic Stack): %s\n", inputString);

    return 0;
}
