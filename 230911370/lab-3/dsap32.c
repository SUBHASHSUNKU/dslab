#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define max 100

// Stack structure
typedef struct {
    int top;
    char items[max];
} stack;

// Initialize the stack
void initializeStack(stack *s) {
    s->top = -1;
}

// Push an element onto the stack
void push(stack *s, char c) {
    if (s->top == max - 1) {
        printf("Stack overflow\n");
    } else {
        s->items[++(s->top)] = c;
    }
}

// Pop an element from the stack
char pop(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return s->items[(s->top)--];
    }
}

// Check if the stack is empty
bool isEmpty(stack *s) {
    return s->top == -1;
}

// Function to check if a character is an opening parenthesis
bool isOpeningParenthesis(char c) {
    return c == '(' || c == '{' || c == '[';
}

// Function to check if a character is a closing parenthesis
bool isClosingParenthesis(char c) {
    return c == ')' || c == '}' || c == ']';
}

// Function to check if two parentheses are matching
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if the parentheses are balanced
bool areParenthesesBalanced(char expr[]) {
    stack s;
    initializeStack(&s);

    for (int i = 0; i < strlen(expr); i++) {
        if (isOpeningParenthesis(expr[i])) {
            push(&s, expr[i]);
        } else if (isClosingParenthesis(expr[i])) {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), expr[i])) {
                return false;
            }
        }
    }

    return isEmpty(&s);
}

int main() {
    char expr[max];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (areParenthesesBalanced(expr)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
