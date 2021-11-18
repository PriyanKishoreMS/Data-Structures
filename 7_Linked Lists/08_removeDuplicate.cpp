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
    Node *t, *last;
    head = new Node;
    head->data = a[0];
    head->next = NULL;
    last = head;

    int i;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
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

void removeDuplicates(Node *p)
{
    Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main()
{
    int a[] = {10, 20, 20, 20, 30, 30, 50, 60};
    int size = sizeof a / sizeof a[0];
    create(a, size);
    display(head);
    removeDuplicates(head);
    display(head);
}