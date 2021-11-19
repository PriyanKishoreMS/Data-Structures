#include <iostream>
using namespace std;

class matrix
{
private:
    int *A;
    int n;

public:
    matrix(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~matrix()
    {
        delete[] A;
    }
    void set(int, int, int);
    int get(int, int);
    void display();
    void put(int);
};

void matrix::set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

int matrix::get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    else
        return 0;
}

void matrix::display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

void matrix::put(int d)
{
    int x;
    cout << "Enter All Elements: ";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            set(i, j, x);
        }
    }
}

int main()
{
    int d;
    cout << "Enter dimesions: ";
    cin >> d;
    matrix m(d);
    m.put(d);
    m.display();
}