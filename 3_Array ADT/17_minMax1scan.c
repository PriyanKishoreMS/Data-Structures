#include <stdio.h>

int main()
{
    int i, l = 10;
    int A[] = {4, 6, 7, 8, 2, 10, 16, 18, 22, 1};
    int min = A[0];
    int max = A[0];

    for (i = 1; i < l; i++)
    {
        if (A[i] < min)
            min = A[i];
        else if (A[i] > max)
            max = A[i];
    }

    printf("max: %d\nmin: %d\n", max, min);
}