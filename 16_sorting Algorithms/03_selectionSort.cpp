#include <iostream>
using namespace std;

// No. of comparisons = n(n-1)/2 => O(n^2)
// No. of swaps = 1(in each iteration)=> O(n)
// Adaptive = false
// Stable = false
// Intermediate Result = kth smallest element

// Time Complexity:
// Best:    O(n^2)
// Average: O(n^2)
// Worst:   O(n^2)

// Space Complexity: O(1)

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int k = i;
        for (j = i; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
        }
        swap(&a[i], &a[k]);
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
    selectionSort(a, size);
    print(a, size);
}