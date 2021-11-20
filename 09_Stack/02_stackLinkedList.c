#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack overflow");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x = -1;

    if (top == NULL)
        printf("Stack Underflow\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int peek(int index)
{
    struct Node *p = top;
    int x = -1, i;
    for (i = 0; p != NULL && i < index - 1; i++)
        p = p->next;
    if (p)
        x = p->data;
    return x;
}

int stackTop()
{
    if (top)
        return top->data;
    return -1;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

void display()
{
    struct Node *p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(2);
    push(4);
    push(6);
    push(8);
    printf("%d is popped\n", pop());
    printf("%d is popped\n", pop());
    printf("%d is popped\n", pop());
    printf("%d is popped\n", pop());
    printf("%d is at index 1\n", peek(1));
    display();
    printf("Stack top is %d\n", stackTop());
    printf("is empty?: %d\n", isEmpty());
}