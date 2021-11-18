#include <stdio.h>

struct Array
{
    int A[10];
    int length;
};

void countDuplicates(struct Array arr)
{
    int i, j, n;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] == arr.A[i + 1])
        {
            j = i + 1;
            while (arr.A[j] == arr.A[i])
                j++;
            printf("%d is repeating %d times\n", arr.A[i], j - i);
            i = j - 1;
        }
    }
}

void countUsingHash(struct Array arr)
{
    int H[16] = {0};
    int i, max = 16;

    for (i = 0; i < arr.length; i++)
        H[arr.A[i]]++;

    for (i = 0; i < max; i++)
    {
        if (H[i] > 1)
            printf("%d is repeating %d times\n", i, H[i]);
    }
}

int main()
{
    struct Array arr = {{2, 4, 6, 8, 8, 10, 12, 15, 15, 15}, 10};
    countDuplicates(arr);
    countUsingHash(arr);
}