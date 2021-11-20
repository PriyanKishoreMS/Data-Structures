#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter the size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow");
    else
        x = st->S[st->top--];
    return x;
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Index invalid\n");
    else
        x = st.S[st.top - index + 1];
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}

int main()
{
    struct Stack st;
    create(&st);
    printf("Push: ");
    push(&st, 2);
    push(&st, 4);
    push(&st, 6);
    push(&st, 8);
    push(&st, 10);
    push(&st, 12);
    display(st);
    printf("After pop: ");
    pop(&st);
    pop(&st);
    pop(&st);
    display(st);
    printf("%d is at index 1\n", peek(st, 1));
    printf("is empty?: %d\n", isEmpty(st));
    printf("is Full?: %d\n", isFull(st));
    printf("%d is in the stack top\n", stackTop(st));
}