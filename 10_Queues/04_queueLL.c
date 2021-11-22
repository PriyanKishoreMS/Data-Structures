#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Queue full\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        rear->next = t;
        rear = t;
    }
}

int dequeue()
{
    int x = -1;
    struct Node *p;
    if (front == NULL)
        printf("Queue empty");
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display()
{
    struct Node *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(2);
    enqueue(4);
    enqueue(6);
    enqueue(8);
    enqueue(10);
    display();
    printf("%d is dequeued\n", dequeue());
    display();
}