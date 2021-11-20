#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack overflow");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    char x = -1;

    if (top == NULL)
        printf("Stack Underflow\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int peek(int index)
{
    struct Node *p = top;
    int x = -1, i;
    for (i = 0; p != NULL && i < index - 1; i++)
        p = p->next;
    if (p)
        x = p->data;
    return x;
}

int stackTop()
{
    if (top)
        return top->data;
    return -1;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

void display()
{
    struct Node *p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty())
                return 0;
            int a = 0;
            if (exp[i] == ')')
                a = stackTop() + 1;
            if (exp[i] == ']' || exp[i] == '}')
                a = stackTop() + 2;
            if (exp[i] == a)
                pop();
        }
    }
    if (isEmpty())
        return 1;
    return 0;
}

int main()
{
    char *exp = "{[(a+b)*(a-b)]}";
    isBalanced(exp) ? printf("Balanced\n") : printf("Not Balanced\n");
}