#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int length;
};

void sumOfN(struct Array arr)
{
    int sum = 0, i, s;
    for (i = 0; i < arr.length; i++)
        sum = sum + arr.A[i];
    int n = 11;
    s = n * (n + 1) / 2;
    printf("The missing element in arr is: %d\n", s - sum);
}

void indexDiff(struct Array arr)
{
    int i, h = 19, l = 4, diff = l - 0;
    for (i = 0; i <= arr.length; i++)
    {
        if (arr.A[i] - i != diff)
        {
            while (diff < arr.A[i] - i)
            {
                printf("The missing element in arr1 is: %d\n", diff + i);
                diff++;
            }
        }
    }
}

void findUnsortHash(struct Array arr)
{
    int i;
    struct Array *hash = (struct Array *)malloc(sizeof(struct Array));
    for (i = 0; i < hash->length; i++)
        hash->A[arr.A[i]]++;
    for (i = 1; i <= 14; i++)
    {
        if (hash->A[i] == 0)
            printf("Missing number from hash is %d\n", i);
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 6, 7, 8, 9, 10, 11}, 10};
    sumOfN(arr);
    struct Array arr1 = {{4, 5, 7, 8, 9, 13, 14, 15, 16, 19}, 10};
    indexDiff(arr1);
    struct Array arr2 = {{7, 4, 8, 2, 9, 10, 3, 12, 14, 5}, 10};
    findUnsortHash(arr2);
}