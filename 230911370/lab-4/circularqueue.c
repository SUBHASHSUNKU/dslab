#include <stdio.h>
#define N 50

int front=-1,rear=-1;
int queue[N];

void enque()
{
    int x;
    if((rear+1)%N==front)
    {
        printf("the queue is full.");
    }
    else if(front==-1&&rear==-1)
    {
        printf("enter value to insert: ");
        scanf("%d", &x);
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else
    {
        printf("enter value to insert: ");
        scanf("%d", &x);
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void deque()
{
    if(rear==-1&&front==-1)
    {
        printf("the queue is empty.");
    }
    else if(rear==front)
    {
        printf("%d is dequeued from the circular queue.",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("%d is dequeued from the circular queue.",queue[front]);
        front=(front+1)%N;
    }
}
void display()
{
    int i=front;
    if(rear==-1&&front==-1)
    {
        printf("the queue is empty.");
    }
    else
    {
        printf("Queue:");
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d ",queue[rear]);
    }
}
int main()
{
    char repeat;
    int choice;
    printf("****QUEUE MENU****\n");
    printf("   1.enqueue\n");
    printf("   2.dequeue\n");
    printf("   3.display\n");
    do{
    printf("enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        enque();
        break;
    case 2:
        deque();
        break;
    case 3:
        display();
        break;
    default:
        printf("invalid input of choice.");
    }
    printf("\n enter C to continue or press Q to quit.\n");
    scanf(" %c", &repeat);
    }while(repeat=='C'||repeat=='c');

    return 0;
}
