#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void create(int a[], int n)
{
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0];
    head->next = NULL;
    last = head;

    int i;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        last->next = t;
        last = t;
    }
}

void reverseElements(struct Node *p)
{
    int *A, i = 0;
    A = (int *)malloc(sizeof(int) * count(p));

    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = head;
    i--;
    while (p != NULL)
    {
        p->data = A[i--];
        p = p->next;
    }
}

void reverseLinks(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void recursiveReverse(struct Node *q, struct Node *p)
{
    if (p)
    {
        recursiveReverse(p, p->next);
        p->next = q;
    }
    else
        head = q;
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
    int size = sizeof a / sizeof a[0];
    create(a, size);
    // reverseElements(head);
    // reverseLinks(head);
    recursiveReverse(NULL, head);
    display(head);
}