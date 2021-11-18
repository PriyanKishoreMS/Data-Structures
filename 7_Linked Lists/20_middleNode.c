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

int findMiddle(struct Node *p)
{
    struct Node *q;
    q = p;
    while (q)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
            p = p->next;
        }
    }
    printf("%d is in the middle\n", p->data);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof arr / sizeof arr[0];
    create(arr, size);
    display(head);
    findMiddle(head);
}