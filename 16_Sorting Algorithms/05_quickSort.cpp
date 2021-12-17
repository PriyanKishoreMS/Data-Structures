#include <iostream>
using namespace std;

// No. of comparisons = n(log n) => O(n log n)(in best and avg cases)
// No. of swaps = n(log n) in best and avg cases
// Adaptive = false
// Stable = false
// Intermediate Result = none

// Time Complexity:
// Best:    O(n(log n))
// Average: O(n(log n))
// Worst:   O(n^2) (When pivot is set as the 1st element,
// worst case is seen in a sorted list, but if the pivot
// is set as the middle element, sorted list tends to
// be the best case.
// Hence, Worst case is decided by the position of pivot)

// Space Complexity: O(log n)

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);
    swap(&a[l], &a[j]);
    return j;
}

void quickSort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        quickSort(a, l, j);
        quickSort(a, j + 1, h);
    }
}

void print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {8, 5, 7, 3, 2, 12, 10, 45, 78, 65, 32};
    int size = sizeof a / sizeof a[0];
    quickSort(a, 0, size);
    print(a, size);
}