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
        head->prev = last;
    }
    last->next = head;
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

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        if (head == NULL)
        {
            head = t;
            head->next = head;
            head->prev = head;
        }
        else
        {
            t->next = p;
            t->prev = p->prev;
            p->prev->next = t;
            p->prev = t;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }
}

int delete (struct Node *p, int index)
{
    struct Node *t;
    int x = -1, i;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (index == 0)
    {
        x = head->data;
        if (head == p->prev)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->prev->next = head->next;
            p->next->prev = head->prev;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        struct Node *q;
        q = p->next;
        p->next = q->next;
        q->next->prev = p;
        x = q->data;
        free(q);
    }
    return x;
}

void display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

int main()
{
    int a[] = {2, 4, 6, 8, 10};
    int size = sizeof a / sizeof a[0];
    create(a, size);
    printf("%d is deleted\n", delete (head, 0));
    display(head);
}