#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    char *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (char *)malloc(size * sizeof(char));
}

int isFull(struct Queue *q)
{
    return q->rear == q->size - 1;
}

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

void enqueue(struct Queue *q, char x)
{
    if (q->rear == q->size - 1)
        printf("Priority Queue Overflow\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

char dequeue(struct Queue *q)
{
    char x = -1;
    if (q->front == q->rear)
        printf("Priority Queue Underflow\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void insert(struct Queue *q1, struct Queue *q2, struct Queue *q3, char x, int pr)
{
    if (pr == 1)
        enqueue(q1, x);
    else if (pr == 2)
        enqueue(q2, x);
    else if (pr == 3)
        enqueue(q3, x);
}

int delete (struct Queue *q1, struct Queue *q2, struct Queue *q3)
{
    int x = -1;
    if (!isEmpty(q1))
        x = dequeue(q1);
    else if (!isEmpty(q2))
        x = dequeue(q2);
    else
        x = dequeue(q3);
    return x;
}

void display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
        printf("%c ", q.Q[i]);
    printf("\n");
}

int main()

{
    struct Queue q1, q2, q3;
    create(&q1, 10);
    create(&q2, 10);
    create(&q3, 10);

    int i;
    insert(&q1, &q2, &q3, 'a', 1);
    insert(&q1, &q2, &q3, 'b', 1);
    insert(&q1, &q2, &q3, 'c', 2);
    insert(&q1, &q2, &q3, 'd', 3);
    insert(&q1, &q2, &q3, 'e', 2);
    insert(&q1, &q2, &q3, 'f', 1);
    insert(&q1, &q2, &q3, 'g', 2);
    insert(&q1, &q2, &q3, 'h', 3);
    insert(&q1, &q2, &q3, 'i', 2);
    insert(&q1, &q2, &q3, 'j', 2);

    display(q1);
    display(q2);
    display(q3);

    delete (&q1, &q2, &q3);
    delete (&q1, &q2, &q3);
    delete (&q1, &q2, &q3);
    delete (&q1, &q2, &q3);

    printf("\n\n");

    display(q1);
    display(q2);
    display(q3);

    printf("\n\n");

    insert(&q1, &q2, &q3, 'z', 2);
    insert(&q1, &q2, &q3, 'w', 1);

    display(q1);
    display(q2);
    display(q3);

    return 0;
}