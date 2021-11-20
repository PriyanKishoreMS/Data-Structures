#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("Stack Overflow");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct Node *p;
    char x = -1;
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

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

char *postfixConvert(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (stackTop() == -1 || pre(infix[i]) > pre(stackTop()))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while (!isEmpty())
        postfix[j++] = pop();
    return postfix;
}

int main()
{
    char *infix = "A+B*C/D-E+F*G*H";
    char *postfix = postfixConvert(infix);
    printf("%s ", postfix);
    printf("\n");
}