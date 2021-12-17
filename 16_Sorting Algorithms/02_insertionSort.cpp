#include <iostream>
using namespace std;

// No. of comparisons = n(n-1)/2 => O(n^2)
// No. of swaps = n(n-1)/2 => O(n^2)
// Adaptive = true
// Stable = true
// Intermediate Result = false

// Time Complexity:
// Best:    O(n)
// Average: O(n^2)
// Worst:   O(n^2)

// Space Complexity: O(1)

void insertionSort(int a[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
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
    insertionSort(a, size);
    print(a, size);
}