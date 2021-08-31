#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int length;
};

int display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

struct Array *merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr->A[k++] = arr1->A[i++];
        else
            arr->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr->A[k++] = arr2->A[j];

    arr->length = arr1->length + arr2->length;

    return arr;
}

int main()
{
    struct Array arr1 = {{2, 4, 8, 9, 12}, 5};
    struct Array arr2 = {{3, 10, 11, 13, 15}, 5};
    struct Array *arr;
    arr = merge(&arr1, &arr2);

    display(*arr);

    return 0;
}