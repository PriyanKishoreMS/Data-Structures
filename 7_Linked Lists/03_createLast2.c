#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *last;

void insert(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    last->next = t;
    last = t;
}

void display(struct Node *p)
{
    int c = 0;
    int sum = 0;
    while (p != NULL)
    {
        c++;
        printf("%d ", p->data);
        sum += p->data;
        p = p->next;
    }
    printf("\ncount: %d", c);
    printf("\nSum: %d\n", sum);
}

int max(struct Node *p)
{
    int m = p->data;
    while (p != NULL)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

void rdisplay(struct Node *p)
{
    if (p != NULL)
    {
        rdisplay(p->next);
        printf("%d ", p->data);
    }
}

struct Node *search(struct Node *p, int x)
{
    while (p != NULL)
    {
        if (x == p->data)
        {
            return p;
            p = p->next;
        }
        return 0;
    }
}

int main()
{
    int n, i, x, key = 0;
    head = (struct Node *)malloc(sizeof(struct Node));
    last = head;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &x);
        insert(x);
    }
    display(head);
    printf("Max: %d\n", max(head));
}