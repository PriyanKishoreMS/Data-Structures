#include <iostream>
using namespace std;

class toeplitz
{
private:
    int *A;
    int n;

public:
    toeplitz(int n)
    {
        this->n = n;
        A = new int[n + n - 1];
    }
    ~toeplitz()
    {
        delete[] A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void toeplitz::set(int i, int j, int x)
{
    if (j >= i)
        A[j - i] = x;
    else
        A[n + j - i - 1] = x;
}

int toeplitz::get(int i, int j)
{
    if (j >= i)
        return A[j - i];
    else
        return A[n + j - i - 1];
}

void toeplitz::display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j >= i)
                cout << A[j - i] << " ";
            else
                cout << A[n + j - i - 1] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, i, j, x;
    cout << "Enter dimensions: ";
    cin >> n;
    toeplitz t(n);
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