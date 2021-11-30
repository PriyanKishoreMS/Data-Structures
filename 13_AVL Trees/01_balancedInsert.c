#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;

    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

int Nodeheight(struct Node *p)
{
    int hl, hr;

    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int bfactor(struct Node *p)
{
    int hl, hr;

    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

struct Node *LLrotation(struct Node *p)
{
    struct Node *tl = p->lchild;
    struct Node *tlr = tl->rchild;

    tl->rchild = p;
    p->lchild = tlr;

    p->height = Nodeheight(p);
    tl->height = Nodeheight(tl);

    if (root == p)
    {
        root = tl;
    }

    return tl;
}

struct Node *RRrotation(struct Node *p)
{
    struct Node *tr = p->rchild;
    struct Node *trl = tr->lchild;

    tr->lchild = p;
    p->rchild = trl;

    p->height = Nodeheight(p);
    tr->height = Nodeheight(tr);

    if (root == p)
    {
        root = tr;
    }

    return tr;
}

struct Node *LRrotation(struct Node *p)
{

    struct Node *tl = p->lchild;
    struct Node *tlr = tl->rchild;

    tl->rchild = tlr->lchild;
    p->lchild = tlr->rchild;

    tlr->lchild = tl;
    tlr->rchild = p;

    tl->height = Nodeheight(tl);
    p->height = Nodeheight(p);
    tlr->height = Nodeheight(tlr);

    if (root == p)
    {
        root = tlr;
    }

    return tlr;
}

struct Node *RLrotation(struct Node *p)
{

    struct Node *tr = p->rchild;
    struct Node *trl = tr->lchild;

    tr->lchild = trl->rchild;
    p->rchild = trl->lchild;

    trl->lchild = p;
    trl->rchild = tr;

    tr->height = Nodeheight(tr);
    p->height = Nodeheight(p);
    trl->height = Nodeheight(trl);

    if (root == p)
    {
        root = trl;
    }

    return trl;
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *newnode = NULL;

    if (p == NULL)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = key;
        newnode->height = 1;
        newnode->lchild = NULL;
        newnode->rchild = NULL;

        return newnode;
    }

    if (p->data < key)
    {
        p->rchild = RInsert(p->rchild, key);
    }
    else if (p->data > key)
    {
        p->lchild = RInsert(p->lchild, key);
    }

    p->height = Nodeheight(p);

    if (bfactor(p) == 2 && bfactor(p->lchild) == 1)
    {
        return LLrotation(p);
    }
    else if (bfactor(p) == -2 && bfactor(p->rchild) == -1)
    {
        return RRrotation(p);
    }
    else if (bfactor(p) == -2 && bfactor(p->rchild) == 1)
    {
        return RLrotation(p);
    }
    else if (bfactor(p) == 2 && bfactor(p->lchild) == -1)
    {
        return LRrotation(p);
    }

    return p;
}

struct Node *predecessor(struct Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }

    return p;
}

struct Node *successor(struct Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }

    return p;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
    {
        return 0;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return 0;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Nodeheight(p->lchild) > Nodeheight(p->lchild))
        {
            q = predecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = successor(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    p->height = Nodeheight(p);

    if (bfactor(p) == 2 && bfactor(p->lchild) == 1)
    {
        return LLrotation(p);
    }
    else if (bfactor(p) == -2 && bfactor(p->rchild) == -1)
    {
        return RRrotation(p);
    }
    else if (bfactor(p) == -2 && bfactor(p->rchild) == 1)
    {
        return RLrotation(p);
    }
    else if (bfactor(p) == 2 && bfactor(p->rchild) == -1)
    {
        return LRrotation(p);
    }
    else if (bfactor(p) == 2 && bfactor(p->lchild) == 0)
    {
        return LLrotation(p);
    }
    else if (bfactor(p) == -2 && bfactor(p->rchild) == 0)
    {
        return RRrotation(p);
    }

    return p;
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    root = RInsert(root, 40);
    RInsert(root, 20);
    RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 30);
    RInsert(root, 5);
    RInsert(root, 60);
    RInsert(root, 25);
    RInsert(root, 36);
    RInsert(root, 27);

    printf("Before deletion: \n");
    preorder(root);

    printf("\n");

    Delete(root, 27);

    printf("After deletion: \n");

    preorder(root);
    printf("\n");

    return 0;
}