
// C++ progrma to sort an array
#include <algorithm>
#include <iostream>


using namespace std;


void show(int a[], int array_size)
{

    for (int i = 0; i < array_size; ++i)

        cout << a[i] << " ";
}

// Driver code

int main()
{

    int a[] = { 2, 7, 10, 9, 6, 5, 3, 4, 1, 0 };



    // size of the array

    int asize = sizeof(a) / sizeof(a[0]);

    cout << "The array before sorting is : \n";



    // print the array

    show(a, asize);


      // sort the array

    sort(a, a + asize);


    cout << "\n\nThe array after sorting is :\n";



    // print the array after sorting

    show(a, asize);


    return 0;
}
