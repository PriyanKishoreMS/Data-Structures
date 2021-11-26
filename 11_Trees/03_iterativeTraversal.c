#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;

void createTree()
{
    struct Node *p, *t;
    struct Queue q;
    int x = 0;
    root = (struct Node *)malloc(sizeof(struct Node));
    createQueue(&q, 50);

    printf("Enter root value: ");
    scanf("%d", &x);
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isQueueEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        printf("\n");
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void iPreOrder(struct Node *t)
{
    struct Stack stk;
    createStack(&stk, 100);
    while (t || !isStackEmpty(stk))
    {
        if (t)
        {
            printf("%d ", t->data);
            push(&stk, t);
            t = t->lchild;
        }
        else
        {
            t = pop(&stk);
            t = t->rchild;
        }
    }
}

void iInOrder(struct Node *t)
{
    struct Stack stk;
    createStack(&stk, 100);
    while (t || !isStackEmpty(stk))
    {
        if (t)
        {
            push(&stk, t);
            t = t->lchild;
        }
        else
        {
            t = pop(&stk);
            printf("%d ", t->data);
            t = t->rchild;
        }
    }
}

int main()
{
    createTree();
    printf("Pre-order Traversal: ");
    iPreOrder(root);
    printf("\n");
    printf("In-order Traversal: ");
    iInOrder(root);
    printf("\n");
}