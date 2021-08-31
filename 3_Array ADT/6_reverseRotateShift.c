#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int length;
};

void display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void reverse(struct Array *arr)
{
    int i, j, *B;
    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
    free(B);
}

void reverse2(struct Array *arr)
{
    int i, j, temp;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void leftRotate(struct Array arr)
{
    int i, x;
    x = arr.A[0];
    for (i = 0; i < arr.length - 1; i++)
        arr.A[i] = arr.A[i + 1];
    arr.A[arr.length - 1] = x;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int main()
{
    struct Array arr = {{42, 57, 73, 84, 98, 31, 14, 28, 66, 12}, 10};
    reverse2(&arr);
    display(arr);
    leftRotate(arr);
}