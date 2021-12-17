#include <iostream>
using namespace std;

// Time Complexity:
// Best:    O(n(log n))
// Average: depends on gap
// Worst:   depends on gap

// Space Complexity: O(1)

void shellSort(int a[], int n)
{
    int i, j, gap, x;
    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            x = a[i];
            j = i - gap;
            while (j >= 0 && a[j] > x)
            {
                a[j + gap] = a[j];
                j = j - gap;
            }
            a[j + gap] = x;
        }
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
    shellSort(a, size);
    print(a, size);
}