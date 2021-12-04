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

void inOrder(struct Node *t)
{
    if (t)
    {
        inOrder(t->lchild);
        printf("%d ", t->data);
        inOrder(t->rchild);
    }
}

int height(struct Node *p)
{
    int x = 0, y = 0;
    if (p == 0)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *inPre(struct Node *p) // right most node of the left subtree, which can replace the root;
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct Node *inSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct Node *delete (struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
        return NULL;
    if (!p->lchild && !p->rchild && p->data == key)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
        p->lchild = delete (p->lchild, key);
    else if (key > p->data)
        p->rchild = delete (p->rchild, key);
    else if (key == p->data)
    {
        if (height(p->lchild) > height(p->rchild))
        {
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = delete (p->lchild, q->data);
        }
        else
        {
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = delete (p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    insert(20);
    insert(5);
    insert(30);
    insert(15);
    insert(25);
    delete (root, 5);
    inOrder(root);
    printf("\n");
}