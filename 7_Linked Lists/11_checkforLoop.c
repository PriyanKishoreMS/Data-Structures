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

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : NULL;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
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
    struct Node *t1, *t2;
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof arr / sizeof arr[0];
    create(arr, size);
    t1 = head->next->next;
    t2 = head->next->next->next->next;
    t2->next = t1;
    if (isLoop(head))
        printf("Is Loop\n");
    else
        printf("Not Loop\n");
}