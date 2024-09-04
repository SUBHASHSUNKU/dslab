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

void prefixToPostfix(char prefix[], char postfix[]) {
    int i;
    char c, temp[MAX_SIZE];
    int tempIndex = 0;

    for (i = strlen(prefix) - 1; i >= 0; i--) {
        c = prefix[i];

        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
            temp[tempIndex++] = c;
            temp[tempIndex] = '\0';
            push(temp);
            tempIndex = 0;
        } else {
            strcpy(temp, pop());
            char operand2[MAX_SIZE];
            strcpy(operand2, pop());
            sprintf(postfix + strlen(postfix), "%s %c %s", operand2, c, temp);
            strcat(postfix, " ");
        }
    }

    postfix[strlen(postfix) - 1] = '\0'; // Remove the trailing space
}

int main() {
    char prefix[MAX_SIZE], postfix[MAX_SIZE] = "";

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
