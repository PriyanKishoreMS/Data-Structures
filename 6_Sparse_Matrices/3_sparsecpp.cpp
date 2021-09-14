#include <iostream>
using namespace std;

class element
{
public:
    int i;
    int j;
    int x;
};

class sparse
{
private:
    int m;
    int n;
    int num;
    element *e;

public:
    sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        this->e = new element[this->num];
    }
    ~sparse()
    {
        delete[] e;
    }

    void read()
    {
        int i;
        cout << "Enter all non-zero elements: ";
        for (i = 0; i < num; i++)
        {
            cin >> e[i].i >> e[i].j >> e[i].x;
            cout << "\n";
        }
    }

    void display()
    {
        int i, j, k = 0;
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < num; j++)
            {
                if (e[k].i == i && e[k].j == j)
                    cout << e[k++].x << " ";
                else
                    cout << "0 ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int main()
{
    sparse s1(5, 5, 5);
    s1.read();
    s1.display();
}