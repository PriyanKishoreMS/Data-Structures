#include <stdio.h>

int hash(char A[])
{
    int i;
    int H[25] = {0};
    for (i = 0; A[i] != '\0'; i++)
        H[A[i] - 97]++;
    for (i = 0; i < 25; i++)
    {
        if (H[i] > 1)
            printf("%c is present %d times\n", i + 97, H[i]);
    }
    printf("\n");
}

int bitwise(char A[])
{
    int i, j, h = 0, x = 0;
    for (i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << A[i] - 97;
        if ((x & h) > 0)
            printf("%c is repeating\n", A[i]);
        else
            h = x | h;
    }
    printf("\n");
}

int iterate(char A[])
{
    int i, j;
    for (i = 0; A[i] != '\0'; i++)
    {
        int count = 1;
        if (A[i] != -1)
        {
            for (j = i + 1; A[j] != '\0'; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
            if (count > 1)
                printf("%c is present %d times\n", A[i], count);
        }
    }
    printf("\n");
}

int main()
{
    char A[] = "naan thaan da paal kaaran";
    bitwise(A);
    hash(A);
    iterate(A);
}