#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // Maximum size of the stack

typedef struct {
    char str[MAX]; // Stack array to store expressions
} Stack;

void push(Stack stack[], int *top, char *str) {
    if (*top < MAX - 1) {
        (*top)++;
        strcpy(stack[*top].str, str);
    } else {
        printf("Stack overflow!\n");
    }
}

char* pop(Stack stack[], int *top) {
    if (*top >= 0) {
        return stack[(*top)--].str;
    } else {
        printf("Stack underflow!\n");
        return "";
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/'||c=='^');
}

void convertPostfixToInfix(char* postfix) {
    Stack stack[MAX];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            // Operand: Push it onto the stack
            char operand[2] = { postfix[i], '\0' };
            push(stack, &top, operand);
        } else if (isOperator(postfix[i])) {
            // Operator: Pop two elements, create a string, and push back
            char operand1[MAX], operand2[MAX];
            char newExpression[MAX];

            strcpy(operand2, pop(stack, &top));
            strcpy(operand1, pop(stack, &top));

            snprintf(newExpression, sizeof(newExpression), "(%s%c%s)", operand1, postfix[i], operand2);

            push(stack, &top, newExpression);
        }
    }

    // The remaining element on the stack is the fully parenthesized infix expression
    printf("Fully Parenthesized Infix Expression: %s\n", pop(stack, &top));
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    convertPostfixToInfix(postfix);

    return 0;
}
