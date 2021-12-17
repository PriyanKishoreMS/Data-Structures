#include <iostream>
using namespace std;

// No. of comparisons = O(n log(n))
// No. of swaps = O(n)
// Adaptive = false
// Stable = false
// Intermediate Result = kth largest element

// Time Complexity:
// Best:    O(n log(n))
// Average: O(n log(n))
// Worst:   O(n log(n))

// Space Complexity: O(1)

void insertInPlace(int a[], int n)
{
    int i = n;
    int temp = a[i];
    while (i > 1 && temp > a[i / 2])
    {
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = temp;
}

void createHeap(int a[], int n)
{
    int i;
    for (i = 2; i <= n; i++)
        insertInPlace(a, i);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int deleteHeap(int a[], int n)
{
    int i, j, x, del;
    i = 1;
    j = i * 2;
    del = a[1];
    x = a[n];
    a[1] = a[n];
    a[n] = del; // delete the largest element (in a max heap) and place at last
    while (j <= n - 1)
    {
        if (j < n - 1 && a[j + 1] > a[j])
            j = j + 1;
        if (a[j] > a[i])
        {
            swap(&a[i], &a[j]);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
    return del;
}

void display(int a[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void heapSort(int a[], int n)
{
    int i;
    for (i = n; i > 1; i--)
    {
        deleteHeap(a, i);
    }
}

int main()
{
    int a[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int size = (sizeof a / sizeof a[0]) - 1;
    createHeap(a, size);
    heapSort(a, size);
    display(a, size);
}