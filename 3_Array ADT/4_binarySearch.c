#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    // int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int binarySearch(struct Array arr, int key)
{
    int l = 0, mid;
    int h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int recursiveBinarySearch(int a[], int l, int h, int key)
{

    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return recursiveBinarySearch(a, l, mid - 1, key);
        else
            return recursiveBinarySearch(a, mid + 1, h, key);
    }
    return -1;
}

int main()
{
    // struct Array arr = {{1, 3, 4, 7, 11, 12, 21, 25, 38, 57, 68}, 11};

    int i, it, rec;
    struct Array arr;
    printf("Enter no. of elements in the array: ");
    scanf("%d", &arr.length);
    printf("Enter %d elements in order: \n", arr.length);
    for (i = 0; i < arr.length; i++)
        scanf("%d", &arr.A[i]);
    printf("Enter the element to be searched through iteration: ");
    scanf("%d", &it);
    printf("Enter the element to be searched through recursion: ");
    scanf("%d", &rec);

    printf("Element is found by iteration at position: %d \n", binarySearch(arr, it));
    printf("Element is found by recursion at position: %d \n", recursiveBinarySearch(arr.A, 0, arr.length, rec));
    display(arr);
}
