#include <iostream>
using namespace std;

int valid_string(char S[])
{
    for (int i = 0; S[i] != '\0'; i++)
    {
        if (!(S[i] >= 'a' && S[i] <= 'z') &&
            !(S[i] >= 'A' && S[i] <= 'Z') &&
            !(S[i] >= '0' && S[i] <= '9'))
            return 0;
    }
    return 1;
}

int main()
{
    char S[] = "PriyanKishore";
    if (valid_string(S) == 0)
        cout << "Invalid String\n";
    else
        cout << "String Valid\n";
}