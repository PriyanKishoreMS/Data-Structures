#include <iostream>
using namespace std;

class tridMatrix
{
private:
    int *A;
    int n;

public:
    tridMatrix(int n)
    {
        this->n = n;
        A = new int[3 * n + 2];
    }
    ~tridMatrix()
    {
        delete[] A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void tridMatrix::set(int i, int j, int x)
{
    if (i - j == 1)
        A[i - 2] = x;
    else if (i - j == 0)
        A[(n - 1) + (i - 1)] = x;
    else if (i - j == -1)
        A[(2 * n - 1) + (i - 1)] = x;
}

int tridMatrix::get(int i, int j)
{
    if (i - j == 1)
        return A[i - 2];
    else if (i - j == 0)
        return A[(n - 1) + (i - 1)];
    else if (i - j == -1)
        return A[(2 * n - 1) + (i - 1)];
    else
        return 0;
}

void tridMatrix::display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i - j == 1)
                cout << A[i - 2] << " ";
            else if (i - j == 0)
                cout << A[(n - 1) + (i - 1)] << " ";
            else if (i - j == -1)
                cout << A[(2 * n - 1) + (i - 1)] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, i, j, x;
    cout << "Enter dimensions: ";
    cin >> n;
    tridMatrix t(n);
    cout << "Enter values: \n";
    for (i = 1; i <= n; i++)
    {
        cout << "Row " << i << "\n";
        for (j = 1; j <= n; j++)
        {
            cin >> x;
            t.set(i, j, x);
        }
        cout << "\n";
    }
    t.display();
}