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

int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

int set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
        return x;
    }
    return -1;
}

void max(struct Array arr)
{
    int max = arr.A[0], i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    printf("\nLargest number in array: %d \n", max);
}

void min(struct Array arr)
{
    int min = arr.A[0], i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    printf("Smallest number in array: %d \n", min);
}

void sum(struct Array arr)
{
    int i, sum = 0;
    for (i = 0; i < arr.length; i++)
        sum = sum + arr.A[i];
    printf("\nSum of the array is: %d", sum);
}

void avg(struct Array arr)
{
    int i, sum = 0, avgg = 0;
    for (i = 0; i < arr.length; i++)
        sum = sum + arr.A[i];
    avgg = sum / arr.length;
    printf("\nAverage of the array is: %d \n", avgg);
}

int main()
{
    struct Array arr = {{42, 57, 73, 84, 98, 31, 14, 28, 66, 12}, 10};
    int in, st;
    printf("\nEnter index to get: ");
    scanf("%d", &in);
    printf("The element at index position %d is %d \n", in, get(arr, in));
    display(arr);
    printf("\nEnter index to set: ");
    scanf("%d", &st);
    printf("The element at index position %d is now changed to %d \n", in, set(&arr, in, st));
    display(arr);
    max(arr);
    min(arr);
    sum(arr);
    avg(arr);
}