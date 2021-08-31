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

int delete (struct Array *arr, int index)
{
    int x, i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;

        return x;
    }

    return 0;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};

    printf("%d is deleted from the array \n", delete (&arr, 2));
    display(arr);
}
