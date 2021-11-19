#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class doublyLinkedList
{
private:
    Node *head;

public:
    doublyLinkedList()
    {
        head = NULL;
    }
    doublyLinkedList(int a[], int n);
    ~doublyLinkedList();

    void display();
    int count();
    void insert(int index, int x);
};

doublyLinkedList::doublyLinkedList(int a[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = a[0];
    head->prev = head->next = NULL;
    last = head;

    int i;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

doublyLinkedList::~doublyLinkedList()
{
    Node *p = head;
    while (p)
    {
        delete p;
        p = p->next;
        head = p;
    }
}

void doublyLinkedList::insert(int index, int x)
{
    Node *t;
    t = new Node;
    t->data = x;
    if (index < 0 || index > count())
        return;

    if (index == 0)
    {
        t->prev = NULL;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else
    {
        Node *p = head;
        int i;
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int doublyLinkedList::count()
{
    int c;
    Node *p = head;
    while (p)
    {
        c++;
        p = p->next;
    }
    return (c);
}

void doublyLinkedList::display()
{
    Node *p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int main()
{
    int a[] = {2, 4, 6, 8, 10};
    int size = sizeof a / sizeof a[0];
    doublyLinkedList dll(a, size);
    dll.insert(0, 45);
    dll.insert(2, 89);
    dll.display();
}
