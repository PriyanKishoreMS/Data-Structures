#include <stdio.h>
#define max 10

// char *compare(char a[max], char b[max])
// {
//     int i, j;
//     for (i = 0, j = 0; a[i] != '\0' || b[j] != '\0'; i++, j++)
//     {
//         if (!(a == b))
//             return 0;
//         else
//             return a;
//     }
// }

char *reverse(char a[max])
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
    return a;
}

int palindrome()
{
    // char string[max];
    // printf("Enter string 1: ");
    // fgets(string, max, stdin);
    // char string2[max];
    // int i, j;
    // for (i = 0;string[i])
    //     for (i = 0, j = 0; string2[i] != '\0' || string[j] != '\0'; i++, j++)
    //         string2[j] = string[i];
    // string2[i] = '\0';
    // printf("%s\n", string2);
    // printf("%s\n", string);
    // if (string == reverse(string2))
    //     printf("Palindrome\n");
    // else
    //     printf("No\n");
    // if (compare(string, reverse(string)) == 0)
    //     printf("Not a palindrome\n");
    // else
    //     printf("%s is a palindrome!\n", compare(string, reverse(string)));
}

int main()
{
    int i, j;
    char a[max];
    char b[max];
    printf("Enter string 1: ");
    fgets(a, max, stdin);
    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; j++, i--)
        b[j] = a[i];
    b[j] = '\0';
    printf("%s\n", a);
    printf("%s\n", b);

    if (a != b)
        printf("Not Palindrome\n");
    else
        printf("Palindrome\n");
}
