#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = new Node;
Node *second = new Node;

void create(int a[], int n)
{
    Node *temp;
    Node *last;

    head->data = a[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void createSecond(int a[], int n, Node *p)
{
    Node *temp;
    Node *last;

    second->data = a[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    last->next = p;
}

void Intersection(Node *p, Node *q)
{
    stack<Node *> stk1;
    while (p != NULL)
    {
        stk1.push(p);
        p = p->next;
    }

    stack<Node *> stk2;
    while (q != NULL)
    {
        stk2.push(q);
        q = q->next;
    }

    Node *r;
    while (stk1.top() == stk2.top())
    {
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    cout << "Intersecting Node: " << r->data << endl;
}

int main()
{

    int a[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof a / sizeof a[0];
    create(a, size);

    Node *temp = head;
    int i = 5;
    while (i > 0)
    {
        temp = temp->next;
        i--;
    }
    int b[] = {2, 4, 6, 8, 10};
    createSecond(b, sizeof(b) / sizeof(b[0]), temp);
    Intersection(head, second);

    return 0;
}