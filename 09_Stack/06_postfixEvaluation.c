#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack Overflow");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *p;
    int x = -1;
    if (top == NULL)
        printf("Stack Underflow");
    else
    {
        p = top;
        x = top->data;
        top = p->next;
        free(p);
    }
    return x;
}

char stackTop()
{
    if (top)
        return top->data;
    return -1;
}

int isEmpty()
{
    return top == NULL;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int evaluate(char *postfix)
{
    int i = 0, x1, x2, r = 0;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
            push(postfix[i] - '0');
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix = "234*+82/-";
    printf("Result: %d\n", evaluate(postfix));
    return 0;
}