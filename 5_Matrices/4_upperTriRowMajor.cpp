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
        A = new int[n * (n + 1) / 2];
    }
    ~matrix()
    {
        delete[] A;
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void matrix::set(int i, int j, int x)
{
    if (j >= i)
        A[n * (i - 1) - (j - 2) * (i - 1) / 2 + (j - i)] = x;
}

int matrix::get(int i, int j)
{
    if (j >= i)
        return A[n * (i - 1) - (j - 2) * (i - 1) / 2 + (j - i)];
    else
        return 0;
}

void matrix::display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j >= i)
                cout << A[n * (i - 1) - (j - 2) * (i - 1) / 2 + (j - i)] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int d, i, j, x;
    cout << "Enter dimesions: ";
    cin >> d;
    matrix m(d);

    cout << "Enter Values: \n";
    for (i = 1; i <= d; i++)
    {
        cout << "Row " << i << "\n";
        for (j = 1; j <= d; j++)
        {
            cin >> x;
            m.set(i, j, x);
        }
        cout << "\n";
    }
    cout << "\n";
    m.display();
}