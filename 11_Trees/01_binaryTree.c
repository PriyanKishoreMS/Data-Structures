#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void createQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
        printf("Queue Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

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

    while (!isEmpty(q))
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

void levelOrder(struct Node *p)
{
    struct Queue q;
    createQueue(&q, 50);

    printf("%d ", p->data);
    enqueue(&q, p);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}

void preOrder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void inOrder(struct Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

void postOrder(struct Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}

int count(struct Node *p)
{
    if (p)
        return count(p->lchild) + count(p->rchild) + 1;
    return 0;
}

int height(struct Node *p)
{
    int x = 0, y = 0;
    if (p == 0)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int countLeaf(struct Node *p)
{
    if (p)
    {
        if (!p->lchild && !p->rchild)
            return count(p->lchild) + count(p->rchild) + 1;

        else
            return count(p->lchild) + count(p->rchild);
    }
    return 0;
}

int main()
{
    createTree();
    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");
    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");
    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");
    printf("Level order Traversal: ");
    levelOrder(root);
    printf("\n");
    printf("No. of Nodes: %d\n", count(root));
    printf("Height of tree: %d\n", height(root) - 1);
}