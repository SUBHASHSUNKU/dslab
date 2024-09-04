#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initializeStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

// Pop an element from the stack
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack underflow!\n");
        return -1;
    }
}

// Implement the queue using two stacks
typedef struct {
    Stack s1;
    Stack s2;
} Queue;

// Initialize the queue
void initializeQueue(Queue *q) {
    initializeStack(&(q->s1));
    initializeStack(&(q->s2));
}

// Enqueue operation
void enqueue(Queue *q, int value) {
    push(&(q->s1), value);
}

// Dequeue operation
int dequeue(Queue *q) {
    // If both stacks are empty, the queue is empty
    if (isEmpty(&(q->s1)) && isEmpty(&(q->s2))) {
        printf("Queue underflow!\n");
        return -1;
    }

    // If stack s2 is empty, transfer all elements from s1 to s2
    if (isEmpty(&(q->s2))) {
        while (!isEmpty(&(q->s1))) {
            push(&(q->s2), pop(&(q->s1)));
        }
    }

    // Pop from stack s2
    return pop(&(q->s2));
}

// Display the queue contents
void displayQueue(Queue *q) {
    if (isEmpty(&(q->s1)) && isEmpty(&(q->s2))) {
        printf("Queue is empty\n");
        return;
    }

    // Transfer all elements from s1 to s2 to maintain the correct order
    while (!isEmpty(&(q->s1))) {
        push(&(q->s2), pop(&(q->s1)));
    }

    // Print elements from s2
    for (int i = q->s2.top; i >= 0; i--) {
        printf("%d ", q->s2.items[i]);
    }

    // Restore elements to s1
    while (!isEmpty(&(q->s2))) {
        push(&(q->s1), pop(&(q->s2)));
    }

    printf("\n");
}

// Menu for queue operations
void menu() {
    Queue q;
    initializeQueue(&q);
    int choice, value;
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;

            case 3:
                printf("Queue contents: ");
                displayQueue(&q);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}

