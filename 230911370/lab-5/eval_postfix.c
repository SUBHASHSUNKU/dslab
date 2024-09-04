#include <stdio.h>
#include <ctype.h>  // for is digit()
#include<math.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    int i;
    for (i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        // If the character is an operand (digit), push it to the stack
        if (isdigit(c)) {
            push(c - '0'); // Convert char digit to integer and push
        }
        // If the character is an operator, pop two elements from stack, apply the operator, and push the result back
        else {
            int operand2 = pop();
            int operand1 = pop();

            switch (c) {
                case '^':
                    push( pow(operand1,operand2));
                    break;
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", c);
                    exit(1);
            }
        }
    }
    return pop(); // The result is the last element in the stack
}

int main() {
    char expression[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
