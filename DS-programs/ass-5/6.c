#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack {
    char data[MAX_SIZE];
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

// Push a character onto the stack
void push(struct Stack* stack, char character) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++(stack->top)] = character;
}

// Pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0'; // Return null character to indicate an error
    }
    return stack->data[(stack->top)--];
}

// Function to determine the precedence of operators
int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0; // Default precedence for other characters
}

// Function to convert an infix expression to a postfix expression
void infixToPostfix(const char* infix, char* postfix) {
    struct Stack stack;
    initialize(&stack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char current = infix[i];

        if (isalnum(current)) {
            // Operand, add to the postfix expression
            postfix[j++] = current;
        } else if (current == '(') {
            // Left parenthesis, push to the stack
            push(&stack, current);
        } else if (current == ')') {
            // Right parenthesis, pop and append operators to the postfix expression until a matching '(' is found
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            // Pop the '(' from the stack
            pop(&stack);
        } else {
            // Operator, pop and append operators to the postfix expression with higher precedence
            while (!isEmpty(&stack) && precedence(current) <= precedence(stack.data[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            // Push the current operator to the stack
            push(&stack, current);
        }

        i++;
    }

    // Pop and append any remaining operators to the postfix expression
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

int main() {
    const char* infixExpression = "3 + (5 * 2) - 7";
    char postfixExpression[MAX_SIZE];

    infixToPostfix(infixExpression, postfixExpression);
    printf("Infix Expression: %s\n", infixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);

    return 0;
}
