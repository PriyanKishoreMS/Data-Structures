#include <iostream>
#include <cmath>

// Time Complexity:
// Best:    O(nk)
// Average: O(nk)
// Worst:   O(nk)

// Space Complexity: O(n+k)

using namespace std;

class Node
{
public:
    int value;
    Node *next;
};

int Max(int A[], int n)
{
    int max = -32768;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

int countDigits(int x)
{
    int count = 0;
    while (x != 0)
    {
        x = x / 10;
        count++;
    }
    return count;
}

void initializeBins(Node **p, int n)
{
}

void Insert(Node **t, int value, int n)
{
    Node *temp = new Node;
    temp->value = value;
    temp->next = nullptr;

    if (t[n] == nullptr)
    {
        t[n] = temp; // t[n] is head ptr
    }
    else
    {
        Node *p = t[n];
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node **t, int n)
{
    Node *p = t[n]; // t[n] is head ptr
    t[n] = t[n]->next;
    int x = p->value;
    delete p;
    return x;
}

int getBinIndex(int x, int n)
{
    return (int)(x / pow(10, n)) % 10;
}

void RadixSort(int A[], int n)
{
    int max = Max(A, n);
    int nPass = countDigits(max);

    Node **bins = new Node *[n];

    // Initialize bins array with nullptr
    initializeBins(bins, n);

    // Update bins and A for nPass times
    for (int pass = 0; pass < nPass; pass++)
    {

        // Update bins based on A values
        for (int i = 0; i < n; i++)
        {
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }

        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10)
        {
            while (bins[i] != nullptr)
            {
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }

    // Delete heap memory
    delete[] bins;
}

void Print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{

    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = sizeof(A) / sizeof(A[0]);
    RadixSort(A, n);
    Print(A, n);

    return 0;
}