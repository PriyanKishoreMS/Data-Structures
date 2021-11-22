#include <iostream>
using namespace std;

class DEQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    DEQueue()
    {
        size = 10;
        front = rear = -1;
        Q = new int[size];
    }
    DEQueue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    ~DEQueue()
    {
        delete[] Q;
    }
    bool isFull();
    bool isEmpty();
    void enqueueRear(int);
    void enqueueFront(int);
    int dequeueFront();
    int dequeueRear();
    void display();
};

bool DEQueue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

bool DEQueue::isFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    return false;
}

void DEQueue::enqueueRear(int x)
{
    if (isFull())
        cout << "DEQueue Full\n";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

void DEQueue::enqueueFront(int x)
{
    if (front == -1)
        cout << "DEQueue Full\n";
    else
    {
        Q[front] = x;
        front--;
    }
}

int DEQueue::dequeueFront()
{
    int x = -1;
    if (isEmpty())
        cout << "DEQueue Empty\n";
    else
    {
        x = Q[front];
        front++;
    }
    return x;
}

int DEQueue::dequeueRear()
{
    int x = -1;
    if (rear == -1)
        cout << "DEQueue Empty\n";
    else
    {
        x = Q[rear];
        rear--;
    }
    return x;
}

void DEQueue::display()
{
    int i;
    for (i = front + 1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << "\n";
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};

    DEQueue deq(sizeof(A) / sizeof(A[0]));

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        deq.enqueueRear(A[i]);
    }
    deq.display();
    deq.enqueueRear(11);

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        deq.dequeueFront();
    }
    deq.dequeueFront();

    cout << endl;

    for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++)
    {
        deq.enqueueFront(B[i]);
    }
    deq.display();
    deq.enqueueFront(10);
    deq.enqueueFront(12);

    for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++)
    {
        deq.dequeueRear();
    }
    deq.display();
    deq.dequeueRear();
    deq.dequeueRear();

    return 0;
}