#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void insert(int key)
{
    struct Node *t, *p, *r = NULL;
    t = root;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

struct Node *rinsert(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < t->data)
        p->lchild = rinsert(p->lchild, key);
    else if (key > t->data)
        p->rchild = rinsert(p->rchild, key);
    return p;
}

struct Node *search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

void inOrder(struct Node *t)
{
    if (t)
    {
        inOrder(t->lchild);
        printf("%d ", t->data);
        inOrder(t->rchild);
    }
}

int main()
{
    struct Node *root = NULL;
    root = rinsert(root, 20);
    rinsert(root, 15);
    rinsert(root, 25);
    rinsert(root, 10);
    rinsert(root, 30);
    rinsert(root, 5);
    inOrder(root);
    printf("\n");
}