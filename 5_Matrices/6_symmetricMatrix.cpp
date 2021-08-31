#include <iostream>
using namespace std;

class sMatrix
{
private:
    int *A;
    int n;

public:
    sMatrix(int n)
    {
        this->n = n;
        A = new int[n * n + 1 / 2];
    }
    ~sMatrix()
    {
        delete[] A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void sMatrix::set(int i, int j, int x)
{
    if (i >= j)
        A[i * (i - 1) / 2 + j - 1] = x;
    else
        A[j * (j - 1) / 2 + i - 1] = x;
}

int sMatrix::get(int i, int j)
{
    if (i >= j)
        return A[i * (i - 1) / 2 + j - 1];
    else
        return A[j * (j - 1) / 2 + i - 1];
}

void sMatrix::display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            else
                cout << A[j * (j - 1) / 2 + i - 1] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, i, j, x;
    cout << "Enter Dimensions: ";
    cin >> n;
    sMatrix s(n);
    cout << "Enter values: \n";
    for (i = 1; i <= n; i++)
    {
        cout << "Row " << i << "\n";
        for (j = 1; j <= n; j++)
        {
            cin >> x;
            s.set(i, j, x);
        }
        cout << "\n";
    }
    cout << "\n";
    s.display();
}
