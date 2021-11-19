#include <iostream>
// #include <cstdlib>

using namespace std;

class Array
{
public:
    int A[20];
    int length;

    Array(int);
    int binarySearch(int);
    int recursiveBinarySearch(int a[], int l, int h, int key);
    void display(int it, int rec);
    void swap(int *x, int *y);
};

Array::Array(int l)
{
    length = l;
}

void Array::display(int it, int rec)
{
    int i;
    cout << "\nList after transposition of " << it << " and move to head of " << rec << ":\n";
    for (i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Array::binarySearch(int key)
{
    int l = 0, mid, h;
    h = length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
        {
            swap(&A[mid], &A[mid - 1]); //Transposition
            return mid;
        }
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int Array::recursiveBinarySearch(int a[], int l, int h, int key)
{
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
        {
            swap(&a[mid], &a[0]); //move to head
            return mid;
        }
        else if (key < a[mid])
            return recursiveBinarySearch(a, l, mid - 1, key);
        else
            return recursiveBinarySearch(a, mid + 1, h, key);
    }
    return -1;
}

int main()
{
    int l, i, it, rec;
    cout << "Enter length of the array: ";
    cin >> l;
    Array arr(l);
    cout << "Enter the elements in order: \n";
    for (i = 0; i < l; i++)
        cin >> arr.A[i];
    cout << "Enter the element to find using iteration: ";
    cin >> it;
    cout << "Enter the element to find using recursion: ";
    cin >> rec;

    cout << "\n"
         << it << " is found at position " << arr.binarySearch(it) << endl;
    cout << rec << " is found at position " << arr.recursiveBinarySearch(arr.A, 0, arr.length - 1, rec) << endl;
    arr.display(it, rec);
}