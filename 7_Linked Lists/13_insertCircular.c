#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(int a[], int n)
{
    struct Node *t, *last;
    int i;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        // t->next = last->next;
        last->next = t;
        last = t;
        last->next = head;
    }
}

void circularInsert(struct Node *p, int index, int x)
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
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
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
    circularInsert(head, 6, 12);
    display(head);
}