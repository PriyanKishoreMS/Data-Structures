#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Queue Full\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    struct Node *p;
    int x = -1;
    if (front == NULL)
        printf("Queue Empty\n");
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}