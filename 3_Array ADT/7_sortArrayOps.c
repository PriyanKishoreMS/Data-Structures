#include <stdio.h>

struct Array
{
    int A[20];
    int B[10];
    int length;
};

int display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int displayb(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.B[i]);
    printf("\n");
}

int swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void insert(struct Array *arr, int n)
{
    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > n)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = n;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            printf("Arrar isn't sorted\n");
            return 0;
        }
    }
    printf("Array is sorted\n");
    return 1;
}

void sortNegative(struct Array *arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] <= 0)
            i++;
        while (arr->A[j] >= 0)
            j--;

        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

int compare(struct Array arr)
{
    int i, j;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] == arr.B[i])
            printf("elements are same at position %d \n", i);
        // printf("elements are not same at position %d \n", j);
    }
}

int append(struct Array *arr)
{
    int i;
    while (arr->length != 21)
    {
        arr->A[arr->length] = arr->B[i];
        arr->length++;
        i++;
    }
}

int main()
{
    struct Array arr = {
        {2, 4, 6, 7, 10, 12, 16, 19, 22, 25},
        {2, -3, 4, 7, -7, -8, -9, 8, 12, -10},
        10};
    int n;
    printf("Enter no. to insert: ");
    scanf("%d", &n);
    insert(&arr, n);
    display(arr);
    isSorted(arr);
    compare(arr);
    append(&arr);
    display(arr);
    sortNegative(&arr);
    display(arr);
}