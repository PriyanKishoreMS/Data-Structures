#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int length;
};

int display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr->A[k++] = arr2->A[j++];
        else
        {
            arr->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr->A[k++] = arr->A[j];

    arr->length = k;

    return arr;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            arr->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr->length = k;

    return arr;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr->A[k++] = arr1->A[i];

    arr->length = k;

    return arr;
}

int main()
{
    struct Array arr1 = {{2, 4, 6, 10, 12}, 5};
    struct Array arr2 = {{3, 5, 8, 10, 12}, 5};
    struct Array *arr;

    // arr = Union(&arr1, &arr2);
    // arr = Intersection(&arr1, &arr2);
    arr = Difference(&arr1, &arr2);

    display(*arr);
}