#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

double stack[MAX_SIZE];
int top = -1;

void push(double num) {
    stack[++top] = num;
}

double pop() {
    return stack[top--];
}

double evaluatePrefix(char prefix[]) {
    int i;
    double num1, num2;
    char c;

    for (i = strlen(prefix) - 1; i >= 0; i--) {
        c = prefix[i];

        if (c >= '0' && c <= '9')
            push(c - '0');
        else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            printf("Enter the value of %c: ", c);
            scanf("%lf", &num1);
            push(num1);
        } else {
            num1 = pop();
            num2 = pop();

            switch (c) {
                case '+':
                    push(num1 + num2);
                    break;
                case '-':
                    push(num1 - num2);
                    break;
                case '*':
                    push(num1 * num2);
                    break;
                case '/':
                    if (num2 != 0)
                        push(num1 / num2);
                    else {
                        printf("Error: Division by zero\n");
                        return 0;
                    }
                    break;
                case '^':
                    push(pow(num1, num2));
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    return 0;
            }
        }
    }

    return stack[0];
}

int main() {
    char prefix[MAX_SIZE];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    printf("Result: %lf\n", evaluatePrefix(prefix));

    return 0;
}
