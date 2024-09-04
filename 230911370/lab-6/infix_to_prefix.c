#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void push(Stack *s, char value) {
    s->items[++(s->top)] = value;
}

char pop(Stack *s) {
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    return s->items[s->top];
}

int precedence(char c) {
    return (c == '+' || c == '-') ? 1 : (c == '*' || c == '/') ? 2 : (c == '^') ? 3 : 0;
}

void reverse(char str[]) {
    for (int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    Stack s;
    s.top=-1;
    reverse(infix);
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
                infix[i] = '(';
        }
    }

    int j = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum(c)) {
        prefix[j++] = c;
        }
        else if (c == '(') {
            push(&s, c);
        }
        else if (c == ')') {
            while (peek(&s) != '(') prefix[j++] = pop(&s); pop(&s);
        }
        else {
            while (s.top != -1 && precedence(peek(&s)) > precedence(c))
                prefix[j++] = pop(&s);
            push(&s, c);
        }
    }

    while (s.top != -1) prefix[j++] = pop(&s);
    prefix[j] = '\0';
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
