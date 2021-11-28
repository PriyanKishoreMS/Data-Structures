#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class BST
{
public:
    Node *root;
    BST() { root = NULL; }
    void inOrder(Node *p);
    void createPre(int pre[], int n);
};

void BST::createPre(int pre[], int n)
{
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;

    stack<Node *> stk;
    Node *t, *p;
    p = root;
    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            if (pre[i] > p->data && pre[i] < (stk.empty() ? 32767 : stk.top()->data))
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

void BST::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

int main()
{
    BST s;
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int size = sizeof pre / sizeof pre[0];
    s.createPre(pre, size);
    s.inOrder(s.root);
    cout << "\n";
}