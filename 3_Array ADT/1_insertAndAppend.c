#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void append(struct Array *arr, int x)
{
    if (arr->size > arr->length)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

void insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    append(&arr, 45);
    insert(&arr, 2, 25);
    display(arr);
}
