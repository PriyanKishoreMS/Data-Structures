#include <iostream>
using namespace std;

// No. of comparisons = O(n log(n))
// Adaptive = false
// Stable = false
// Intermediate Result = none

// Time Complexity:
// Best:    O(n log(n))
// Average: O(n log(n))
// Worst:   O(n log(n))

// Space Complexity: O(n)
// in recursive function O(n+log n) as it uses stack

void merge(int a[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int b[h];
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    for (; i <= mid; i++)
        b[k++] = a[i];
    for (; j <= h; j++)
        b[k++] = a[j];

    for (i = l; i <= h; i++)
        a[i] = b[i];
}

void iMergeSort(int a[], int n)
{
    int p, i, l, h, mid;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 <= n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(a, l, mid, h);
        }
        // if (n - i > p / 2)
        // {
        //     l = i;
        //     h = i + p - 1;
        //     mid = (l + h) / 2;
        //     merge(a, l, mid, n - 1);
        // }
    }
    if (p / 2 < n)
        merge(a, 0, p / 2 - 1, n - 1);
}

void rMergeSort(int a[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        rMergeSort(a, l, mid);
        rMergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

void print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    int a[] = {8, 5, 7, 3, 2, 12, 10, 45, 78, 65, 32};
    int size = sizeof a / sizeof a[0];
    // iMergeSort(a, size);
    rMergeSort(a, 0, size);
    print(a, size);
}