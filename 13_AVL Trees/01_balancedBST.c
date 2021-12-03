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
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild; // the node that has to be replaced (not the node that directly gets involved in the rotation);

    pl->rchild = p;
    p->lchild = plr;

    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);

    if (root == p)
        root = pl;

    return pl;
}

struct Node *RRrotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = Nodeheight(p);
    pr->height = Nodeheight(pr);

    if (root == p)
        root = pr;

    return pr;
}

struct Node *LRrotation(struct Node *p)
{

    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = Nodeheight(pl);
    p->height = Nodeheight(p);
    plr->height = Nodeheight(plr);

    if (root == p)
        root = plr;

    return plr;
}

struct Node *RLrotation(struct Node *p)
{

    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->lchild = p;
    prl->rchild = pr;

    pr->height = Nodeheight(pr);
    p->height = Nodeheight(p);
    prl->height = Nodeheight(prl);

    if (root == p)
        root = prl;

    return prl;
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;

    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = NULL;
        t->rchild = NULL;

        return t;
    }

    if (p->data < key)
        p->rchild = RInsert(p->rchild, key);
    else if (p->data > key)
        p->lchild = RInsert(p->lchild, key);

    p->height = Nodeheight(p);

    if (bfactor(p) == 2 && bfactor(p->lchild) == 1)
        return LLrotation(p);
    else if (bfactor(p) == -2 && bfactor(p->rchild) == -1)
        return RRrotation(p);
    else if (bfactor(p) == -2 && bfactor(p->rchild) == 1)
        return RLrotation(p);
    else if (bfactor(p) == 2 && bfactor(p->lchild) == -1)
        return LRrotation(p);

    return p;
}

struct Node *predecessor(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;

    return p;
}

struct Node *successor(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;

    return p;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
        return 0;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return 0;
    }

    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
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
        return LLrotation(p);
    else if (bfactor(p) == -2 && bfactor(p->rchild) == -1)
        return RRrotation(p);
    else if (bfactor(p) == -2 && bfactor(p->rchild) == 1)
        return RLrotation(p);
    else if (bfactor(p) == 2 && bfactor(p->rchild) == -1)
        return LRrotation(p);
    else if (bfactor(p) == 2 && bfactor(p->lchild) == 0) // either LL or LR rotation can be done;
        return LLrotation(p);
    else if (bfactor(p) == -2 && bfactor(p->rchild) == 0)
        return RRrotation(p);

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