#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue()
    {
        size = 10;
        front = rear = -1;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    ~Queue()
    {
        delete[] Q;
    }
    void enqueue(int);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        cout << "Queue Full\n";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
        cout << "Queue Empty\n";
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    int i;
    for (i = front + 1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << "\n";
}

int main()
{
    Queue q(5);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);
    q.display();
    cout << q.dequeue() << " has been dequeued\n";
    q.display();
}