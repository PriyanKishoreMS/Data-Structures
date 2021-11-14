#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL, *second = NULL, *third = NULL;

void create(int a[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    int i;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        last->next = t;
        last = t;
    }
}

void create2(int b[], int n)
{
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = b[0];
    second->next = NULL;
    last = second;

    int i;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = b[i];
        last->next = t;
        last = t;
    }
}

void concatenate(struct Node *p, struct Node *q)
{
    while (p->next != NULL)
        p = p->next;
    p->next = q;
    q = NULL;
}

void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60};
    int b[] = {5, 15, 25, 35, 45, 55};
    int size = sizeof a / sizeof a[0];
    int size1 = sizeof b / sizeof b[0];
    create(a, size);
    create2(b, size);
    // concatenate(first, second);
    // printf("Concatenated = ");
    // display(first);
    merge(first, second);
    printf("merged = ");
    display(third);
}