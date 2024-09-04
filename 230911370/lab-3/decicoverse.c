#include <stdio.h>
#define max 100

typedef struct
{
    int top;
    char item[max];
}stack;

void initializestack(stack *s)
{
    s->top=-1;
}
void push(stack *s,char x)
{
    if(s->top==max-1)
    {
        printf("stack overflow");
    }
    else {
        s->item[++(s->top)]=x;
    }
}
char pop(stack *s)
{
    if(s->top==-1)
    {
        printf("stack underflow");
        return '\0';
    }
    else{
        return s->item[(s->top)--];
    }
}

void deciconverse(int decimalnumber,int base)
{
    stack s;
    initializestack(&s);

    char digits[]="0123456789ABCDEF";
    while(decimalnumber>0)
    {
        int reminder=decimalnumber%base;
        push(&s, digits[reminder]);
        decimalnumber /=base;
    }
    printf("converted number in base %d: ",base);
    while(s.top!=-1)
    {
        printf("%c",pop(&s));
    }
    printf("\n");
    return 0;
}

int main()
{
    int decimalnumber,base;
    printf("enter the number in decimal form: ");
    scanf("%d", &decimalnumber);
    printf("enter base to covert: ");
    scanf("%d", &base);
    if(base<2||base>16)
    {
        printf("enter a base number from 2 to 16.");
    }
    else{
      deciconverse(decimalnumber,base);
    }
    return 0;
}
