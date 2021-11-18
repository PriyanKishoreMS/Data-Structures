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

int deleteCircular(struct Node *p, int index)
{
    struct Node *t;
    int x = -1, i;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (index == 0)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
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
    display(head);
    printf("%d is deleted\n", deleteCircular(head, 2));
    printf("%d is deleted\n", deleteCircular(head, 1));
    display(head);
}