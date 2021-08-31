#include <iostream>
#include <cstdlib>

using namespace std;

class Array
{
public:
    int *A;
    int size;
    int length;

public:
    Array(int);
    void ReadData();
    void fillvalues(int);
    void display();
};

Array::Array(int s)
{
    size = s;
    A = new int[size];
    length = 0;
}

void Array::ReadData()
{
    cout << "Enter the number of elements....";
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> A[i];
}

void Array::fillvalues(int x)
{
    cout << "Enter all values";
    for (int i = 0; i < x; i++)
    {
        cin >> A[i];
    }
    length = x;
}

void Array::display()
{
    cout << "\nElements are\n";
    A[length] = 7;
    length++;
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter the size: ";
    int s;
    cin >> s;
    Array arr(s);
    arr.ReadData();
    arr.display();
    return 0;
}