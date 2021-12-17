#include <iostream>
using namespace std;

// Time Complexity:
// Best:    O(n+k)
// Average: O(n+k)
// Worst:   O(n+k)

// Space Complexity: O(k)

int findMax(int a[], int n)
{
    int i, max = INT32_MIN;
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void countSort(int a[], int n)
{
    int i, *C;
    int max = findMax(a, n);
    C = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < max + 1; i++)
        C[i] = 0;
    for (i = 0; i < n; i++)
        C[a[i]]++;
    i = 0;
    int j = 0;
    while (i <= max + 1)
    {
        if (C[i] > 0)
        {
            a[j++] = i;
            C[i]--;
        }
        else
            i++;
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
    countSort(a, size);
    print(a, size);
}