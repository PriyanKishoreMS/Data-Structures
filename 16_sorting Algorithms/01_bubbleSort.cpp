#include <iostream>
using namespace std;

// No. of comparisons = n(n-1)/2 => O(n^2)
// No. of swaps = n(n-1)/2 => O(n^2)
// Adaptive = true
// Stable = true
// Intermediate Result = kth largest element

// Time Complexity:
// Best:    O(n)
// Average: O(n^2)
// Worst:   O(n^2)

// Space Complexity: O(1)

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int a[], int n)
{
    int i, j, flag;
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
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
    bubbleSort(a, size);
    print(a, size);
}