#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE][MAX_SIZE];
int top = -1;

void push(char str[]) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

void prefixToInfix(char prefix[], char infix[]) {
    int i;
    char c, operand1[MAX_SIZE], operand2[MAX_SIZE], temp[MAX_SIZE];

    for (i = strlen(prefix) - 1; i >= 0; i--) {
        c = prefix[i];

        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
            sprintf(temp, "%c", c);
            push(temp);
        } else {
            strcpy(operand1, pop());
            strcpy(operand2, pop());

            sprintf(temp, "(%s %c %s)", operand1, c, operand2);
            push(temp);
        }
    }

    strcpy(infix, stack[0]);
}

int main() {
    char prefix[MAX_SIZE], infix[MAX_SIZE];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToInfix(prefix, infix);

    printf("Fully parenthesized infix expression: %s\n", infix);

    return 0;
}
