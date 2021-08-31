#include <stdio.h>

int squareRoot(int n, int guess)
{
    if (guess * guess == n)
        return guess;
    guess++;
    squareRoot(n, guess);
}

int power(int m, int n)
{
    if (n == 0)
        return 1;
    return power(m, n - 1) * m;
}

int rootCube(int m)
{
    int x = squareRoot(m, 1);
    return power(x, 3);
}

int juggler(int n)
{
    int x, y;
    x = squareRoot(n, 1);
    y = rootCube(n);
    if (n > 1)
    {
        if (n % 2 == 0)
        {
            printf("%d ", x);
            juggler(x);
        }
        printf("%d \n", y);
        juggler(y);
    }
    return 1;
}

int main()
{
    juggler(9);
}

// int x, y;
//     if (n == 1)
//     {
//         printf("%d", n);
//         return n;
//     }

//     else
//     {
//         if (n % 2 == 0)
//         {
//             x = squareRoot(n, 1);
//             printf("%d", x);
//             return juggler(x);
//         }
//         else
//         {
//             y = rootCube(n);
//             printf("%d", y);
//             return juggler(y);
//         }
//     }