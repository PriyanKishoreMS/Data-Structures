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
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0];
    head->next = NULL;
    last = head;

    int i;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
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

void insert(struct Node *p, int pos, int x)
{
    int i;
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (pos == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        for (i = 0; i < pos - 1 && p; i++)
            p = p->next;
    }
    if (p)
    {
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof arr / sizeof arr[0];
    create(arr, size);
    display(head);
    insert(head, 0, 45);
    display(head);
    insert(head, 3, 45);
    display(head);
    insert(head, 6, 12);
    display(head);
}