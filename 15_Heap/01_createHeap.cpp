#include <iostream>
using namespace std;

void InsertInplace(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2])
    {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

void createHeap(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertInplace(A, i);
    }
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    int a[] = {10, 20, 30, 25, 5, 40, 35};
    int size = sizeof a / sizeof a[0];
    createHeap(a, size);
    display(a, size - 1);
}