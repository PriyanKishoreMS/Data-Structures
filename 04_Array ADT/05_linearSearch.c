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
    printf("The elements after transposition: ");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }
    return -1;
}

int main()
{
    int i, n;
    struct Array arr = {{}, 10, 5};
    printf("Enter 5 elements: ");
    for (i = 0; i < 5; i++)
        scanf("%d", &arr.A[i]);
    printf("Enter one element from the list to search: ");
    scanf("%d", &n);
    printf("Element found at position %d \n", linearSearch(&arr, n));
    display(arr);
}