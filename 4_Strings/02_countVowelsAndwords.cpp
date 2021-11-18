#include <iostream>
using namespace std;

void Count()
{
    char a[] = "Hello how are   you";
    int i, count = 0, letters = 0, words = 1;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != ' ')
            letters++;
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' ||
            a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
            count++;
        if (a[i] == ' ' && a[i - 1] != ' ')
            words++;
    }
    cout << "No. of Vowels = " << count << "\n"
         << "No. of Consonants = " << letters - count << "\n"
         << "No. of Words = " << words << endl;
}

int main()
{
    Count();
}