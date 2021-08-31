#include <iostream>
using namespace std;

void length()
{
    char s[] = "Welcome";
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
    }
    cout << "Length is " << i << endl;
}

void toggleCase()
{
    char s[] = "wELCOME";
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
        else if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
    }
    cout << s << endl;
}

int main()
{
    length();
    toggleCase();
    return 0;
}