#include <stdio.h>

void iterate(char a[], char b[])
{
    int i, j;
    for (i = 0; a[i] != '\0'; i++)
    {
        for (j = 0; b[j] != '\0'; j++)
        {
            if (a[i] != b[j])
            {
                break;
            }
        }
    }
    if (b[i] == '\0')
        printf("It is an anagram\n");
    else
        printf("Not an anagram\n");
}

int length(char a[])
{
    int i, count = 0;
    for (i = 0; a[i] != '\0'; i++)
        count++;
    return count;
}

void hash(char a[], char b[])
{
    int i;
    int h[26] = {0};
    for (i = 0; a[i] != '\0'; i++)
        h[a[i] - 97]++;
    for (i = 0; b[i] != '\0'; i++)
    {
        h[b[i] - 97]--;
        if (h[b[i] - 97] < 0)
        {
            break;
        }
    }
    if (b[i] == '\0' && length(a) == length(b))
        printf("It is an anagram\n");
    else
        printf("Not an anagram\n");
}

int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    hash(A, B);
    // iterate(A, B);
}