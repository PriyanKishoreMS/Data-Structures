#include <stdio.h>

struct Array
{
    int A[10];
    int length;
};

void findDuplicate(struct Array arr)
{
    int i, j;
    for (i = 0; i < arr.length - 1; i++)
    {
        int count = 1;
        if (arr.A[i] != -1)
        {
            for (j = i + 1; j < arr.length; j++)
            {
                if (arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
            if (count > 1)
                printf("%d %d\n", arr.A[i], count);
        }
    }
}

void dupByHash(struct Array arr)
{
    int i;
    int H[10] = {0};
    for (i = 0; i < arr.length; i++)
        H[arr.A[i]]++;

    for (i = 0; i < arr.length; i++)
    {
        if (H[i] > 1)
            printf("%d %d\n", i, H[i]);
    }
}

int main()
{
    struct Array arr = {{8, 3, 6, 4, 6, 5, 6, 8, 2, 7}, 10};
    findDuplicate(arr);
    dupByHash(arr);
}