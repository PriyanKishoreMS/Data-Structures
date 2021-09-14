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

    friend istream &operator>>(istream &is, sparse &s);
    friend ostream &operator<<(ostream &os, sparse &s);
};

istream &operator>>(istream &is, sparse &s)
{
    int i;
    cout << "Enter all non-zero elements: ";
    for (i = 0; i < s.num; i++)
    {
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
        cout << "\n";
    }
    return is;
}

ostream &operator<<(ostream &os, sparse &s)
{
    int i, j, k = 0;
    for (i = 0; i < s.num; i++)
    {
        for (j = 0; j < s.num; j++)
        {
            if (s.e[k].i == i && s.e[k].j == j)
                cout << s.e[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
    cout << "\n";
    return os;
}

int main()
{
    sparse s1(5, 5, 5);
    cin >> s1;
    cout << s1;

    return 0;
}