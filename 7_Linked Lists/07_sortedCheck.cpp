#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;

void create(int a[], int n)
{
    struct Node *t, *last;
    head = new Node;
    head->data = a[0];
    head->next = NULL;
    last = head;

    int i;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int sortedCheck(Node *p)
{
    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof arr / sizeof arr[0];
    create(arr, size);
    display(head);
    if (sortedCheck(head))
        cout << "Sorted\n";
    else
        cout << "Not sorted\n";
}