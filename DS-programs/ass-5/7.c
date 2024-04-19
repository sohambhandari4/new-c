#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Push an integer onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++(stack->top)] = value;
}

// Pop an integer from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return -1 to indicate an error
    }
    return stack->data[(stack->top)--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(const char* postfix) {
    struct Stack stack;
    initialize(&stack);

    int i = 0;

    while (postfix[i] != '\0') {
        char current = postfix[i];

        if (isdigit(current)) {
            // Operand, push to the stack
            push(&stack, current - '0');
        } else {
            // Operator, pop the top two operands, perform the operation, and push the result back to the stack
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (current) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero is not allowed.\n");
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", current);
                    exit(1);
            }

            push(&stack, result);
        }

        i++;
    }

    if (isEmpty(&stack)) {
        printf("Expression is empty or invalid.\n");
        exit(1);
    }

    return pop(&stack);
}

int main() {
    const char* postfixExpression = "53*7-";

    int result = evaluatePostfix(postfixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);
    printf("Result: %d\n", result);

    return 0;
}
