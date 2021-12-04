#include <iostream>
using namespace std;

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Heapify(int A[], int n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i = (n / 2) - 1; i >= 0; i--)
    {

        int j = 2 * i + 1; // Left child for current i

        while (j < n - 1)
        {
            // Compare left and right children of current i
            if (A[j] < A[j + 1])
            {
                j = j + 1;
            }

            // Compare parent and largest child
            if (A[i] < A[j])
            {
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            }
            else
            {
                break;
            }
        }
    }
}

int Delete(int A[], int n)
{
    int x = A[0];
    A[0] = A[n - 1];

    int i = 0;
    int j = 2 * i + 1;

    while (j < n - 1)
    {
        if (A[j] < A[j + 1])
        {
            j = j + 1;
        }

        if (A[i] < A[j])
        {
            swap(A, i, j);
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            break;
        }
    }
    return x;
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{

    int A[] = {5, 10, 30, 20, 35, 40, 15};
    int size = sizeof A / sizeof A[0];
    Heapify(A, size);
    display(A, size);
    cout << endl;

    return 0;
}