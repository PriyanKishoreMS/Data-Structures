#include <iostream>
using namespace std;

// Time Complexity:
// Best:    O(n+k)
// Average: O(n+k)
// Worst:   O(n^2)

// Space Complexity: O(n)

class Node
{
public:
    int data;
    Node *next;
};

void insert(Node **t, int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = nullptr;

    if (t[n] == nullptr)
        t[n] = temp;
    else
    {
        Node *p = t[n];
        while (p)
            p = p->next;
        p->next = temp;
    }
}

int Delete(Node **t, int i)
{
    Node *p = t[i];
    t[i] = t[i]->next;
    int x = p->data;
    delete p;
    return x;
}

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

void binSort(int a[], int n)
{
    int i, j;
    int max = findMax(a, n);
    Node **bins = new Node *[max + 1];

    for (i = 0; i < max + 1; i++)
        bins[i] = nullptr;

    for (i = 0; i < n; i++)
        insert(bins, a[i]);

    i = 0, j = 0;
    while (i < max + 1)
    {
        while (bins[i] != nullptr)
        {
            a[j++] = Delete(bins, i);
        }
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
    binSort(a, size);
    print(a, size);
}