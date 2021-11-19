#include <stdio.h>
#define MAX 20

void reverse1(char a[MAX])
{
    int i, j;
    char b[MAX];
    // printf("%s\n", a);
    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; j++, i--)
        b[j] = a[i];
    b[j] = '\0';
    printf("%s\n", b);
}

void reverse2(char a[MAX])
{
    int i, j;
    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i > j; i--, j++)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    printf("%s\n", a);
}

int main()
{
    char string[MAX];
    printf("Enter a string: ");
    fgets(string, MAX, stdin);
    reverse1(string);
    reverse2(string);
}