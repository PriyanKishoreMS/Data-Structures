#include <stdio.h>

struct Array
{
    int A[10];
    int length;
};

void unsort(struct Array arr)
{
    int i, j;
    for (i = 0; i < arr.length - 1; i++)
    {
        for (j = i + 1; j < arr.length; j++)
        {
            if (arr.A[i] + arr.A[j] == 10)
                printf("%d + %d = %d\n", arr.A[i], arr.A[j], 10);
        }
    }
}

void unsortHash(struct Array arr)
{
    int i;
    int H[20] = {0};
    for (i = 0; i < arr.length; i++)
    {
        if (H[10 - arr.A[i]] != 0 && 10 - arr.A[i] > 0)
            printf("%d + %d = %d\n", arr.A[i], 10 - arr.A[i], 10);
        H[arr.A[i]]++;
    }
}

int sorted(struct Array arr)
{
    int i = 0;
    int j = arr.length - 1;
    while (i < j)
    {
        if (arr.A[i] + arr.A[j] == 10)
        {
            printf("%d + %d = %d\n", arr.A[i], arr.A[j], 10);
            i++;
            j--;
        }
        else if (arr.A[i] + arr.A[j] < 10)
            i++;
        else
            j--;
    }
}

int main()
{
    struct Array unsortedArray = {{6, 4, 8, 10, 16, 7, 5, 2, 9, 14}, 10};
    struct Array sortedArray = {{1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, 10};
    sorted(sortedArray);
    unsort(unsortedArray);
    unsortHash(unsortedArray);
}