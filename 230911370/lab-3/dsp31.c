#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define max 100

typedef struct{
int top;
char item[max];
}stack;

void initializestack(stack *s){
s->top=-1;
}

void push(stack *s,char x)
{
    if(s->top==max-1)
    {
        printf("stack overflow");
    }
    else{
        s->item[++(s->top)]=x;
    }
}
char pop(stack *s)
{
    int y;
    if(s->top==-1)
    {
        printf("stack underflow");
        return '\0';
    }
    else{
        return s->item[(s->top)--];
    }
}
bool ispalindrome(char str[])
{
    stack s;
    initializestack(&s);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        push(&s,str[i]);
    }
    for(int i=0;i<len;i++)
    {
        if(str[i]!=pop(&s))
            {
                return false;
            }
    }
        return true;
}
    int main()
    {
    char str[max];
    printf("enter the string: ");
    scanf("%s",str);
    if(ispalindrome(str))
    {
        printf("the input string is a palindrome.");
    }
    else{
        printf("the input string is not a palindrome.");
    }
    return 0;
    }
