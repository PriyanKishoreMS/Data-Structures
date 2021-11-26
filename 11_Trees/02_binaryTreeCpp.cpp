#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;

public:
    Queue()
    {
        size = 10;
        front = rear = 0;
        Q = new Node *[size];
    };
    Queue(int size)
    {
        this->size = size;
        front = rear = 0;
        Q = new Node *[size];
    }
    ~Queue()
    {
        delete[] Q;
    }
    void enqueue(Node *);
    Node *dequeue();
    void display();
    int isEmpty();
};

class Tree
{
private:
    Node *root;

public:
    Tree() { root = NULL; }
    void createTree();
    void preOrder() { preOrder(root); }
    void preOrder(Node *);
    void inOrder() { inOrder(root); }
    void inOrder(Node *);
    void postOrder() { postOrder(root); }
    void postOrder(Node *);
    void levelOrder() { levelOrder(root); }
    void levelOrder(Node *);
    int height() { return height(root); }
    int height(Node *);
};

void Queue::enqueue(Node *x)
{
    if ((rear + 1) % size == front)
        cout << "Queue Full\n";
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = NULL;
    if (front == rear)
        cout << "Queue Empty\n";
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

int Queue::isEmpty()
{
    return front == rear;
}

void Tree::createTree()
{
    Node *t, *p;
    Queue q(100);
    int x;
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter the left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter the right child of " << p->data << ": ";
        cin >> x;
        cout << "\n";
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

void Tree::postOrder(Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::levelOrder(Node *p)
{
    Queue q(100);

    cout << p->data << " ";
    q.enqueue(p);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        }
    }
}

int Tree::height(Node *p)
{
    int x = 0, y = 0;
    if (p == 0)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    Tree t;
    t.createTree();
    cout << "Pre-order Traversal: ";
    t.preOrder();
    cout << "\n\n";
    cout << "In-order Traversal: ";
    t.inOrder();
    cout << "\n\n";
    cout << "Post-order Traversal: ";
    t.postOrder();
    cout << "\n\n";
    cout << "Level order Traversal: ";
    t.levelOrder();
    cout << "\n\n";
    cout << "Height of tree: " << t.height() - 1 << "\n";
}
