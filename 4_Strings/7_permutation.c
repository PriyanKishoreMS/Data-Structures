#include <stdio.h>

void permutation(char s[], int k)
{
    static int a[20] = {0};
    static char res[20];
    int i;
    if (s[k] == '\0')
    {
        res[k] = '\0';
        puts(res);
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (a[i] == 0)
            {
                res[k] = s[i];
                a[i] = 1;
                permutation(s, k + 1);
                a[i] = 0;
            }
        }
    }
}

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void strPerSwap(char *A, int l, int h)
{
    int i;
    if (l == h)
        printf("%s\n", A);
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(&A[l], &A[i]);
            strPerSwap(A, l + 1, h);
            swap(&A[l], &A[i]);
        }
    }
}

void main()
{
    int i = 0;
    char s[] = "priyan";
    // permutation(s, 0);
    for (; s[i] != 0; i++)
        ;
    strPerSwap(s, 0, i - 1);
}