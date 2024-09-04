#include <stdio.h>
#define max 100

typedef struct
{
    int top1, top2;
    int arr[max];
} MultiStack;

void initializeStacks(MultiStack *s)
{
    s->top1 = -1;           // Stack 1 starts from the beginning of the array
    s->top2 = max;          // Stack 2 starts from the end of the array
}

void push1(MultiStack *s, int x)
{
    if (s->top1 < s->top2 - 1)  // Check for space between the two stacks
    {
        s->arr[++(s->top1)] = x;
    }
    else
    {
        printf("Stack 1 Overflow\n");
    }
}

void push2(MultiStack *s, int x)
{
    if (s->top1 < s->top2 - 1)  // Check for space between the two stacks
    {
        s->arr[--(s->top2)] = x;
    }
    else
    {
        printf("Stack 2 Overflow\n");
    }
}

int pop1(MultiStack *s)
{
    if (s->top1 >= 0)
    {
        return s->arr[(s->top1)--];
    }
    else
    {
        printf("Stack 1 Underflow\n");
        return -1;
    }
}

int pop2(MultiStack *s)
{
    if (s->top2 < max)
    {
        return s->arr[(s->top2)++];
    }
    else
    {
        printf("Stack 2 Underflow\n");
        return -1;
    }
}

int main()
{
    MultiStack s;
    initializeStacks(&s);

    // Operations on Stack 1
    push1(&s, 10);
    push1(&s, 20);
    push1(&s, 30);
    printf("Popped from Stack 1: %d\n", pop1(&s));

    // Operations on Stack 2
    push2(&s, 40);
    push2(&s, 50);
    push2(&s, 60);
    printf("Popped from Stack 2: %d\n", pop2(&s));

    return 0;
}
