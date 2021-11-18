#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} * head;

void create(int a[], int n)
{
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0];
    head->prev = head->next = NULL;
    last = head;

    int i;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

void reverse(struct Node *p)
{
    struct Node *temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p && p->next == NULL)
            head = p;
    }
}

void reverse2(struct Node *p)
{
    while (p->next != NULL)
        p = p->next;
    while (p->prev != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("%d ", p->data);
    printf("\n");
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
    int a[] = {2, 4, 6, 8, 10};
    int size = sizeof a / sizeof a[0];
    create(a, size);
    // reverse(head);
    // display(head);
    reverse2(head);
}