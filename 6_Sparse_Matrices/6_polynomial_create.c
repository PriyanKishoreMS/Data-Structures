#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff;
    int exp;
};

struct poly
{
    int n;
    struct term *term;
};

void create(struct poly *p)
{
    int i;
    p->term = (struct term *)malloc(p->n * sizeof(struct term));
    printf("Enter no. of terms: ");
    scanf("%d", &p->n);
    printf("Enter all the terms: ");
    for (i = 0; i < p->n; i++)
    {
        scanf("%d%d", &p->term[i].coeff, &p->term[i].exp);
        printf("\n");
    }
}

void display(struct poly p)
{
    int i;
    for (i = 0; i < p.n; i++)
        printf("%dx%d + ", p.term[i].coeff, p.term[i].exp);
    printf("\n");
}

int main()
{
    struct poly p1;
    create(&p1);
    display(p1);
}