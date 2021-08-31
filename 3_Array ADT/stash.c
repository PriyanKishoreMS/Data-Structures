#include <stdio.h>

int main()
{
    int A[] = {2, 4, 6, 8, 8, 10, 12, 15, 15, 15};
    int H[16] = {0};
    int i;

    for (i = 0; i < 10; i++)
        H[A[i]]++;

    for (i = 0; i < 16; i++)
    {
        if (H[i] > 1)
            printf("%d is repeating %d times\n", i, H[i]);
    }
}