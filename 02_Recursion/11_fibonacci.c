#include <stdio.h>

int fib1(int n)
{
    int t0 = 0, t1 = 1, s, i;
    if (n <= 1)
        return 1;
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 2) + fib(n - 1);
}

int f[10];

int fib3(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 2] == -1)
            f[n - 2] = fib3(n - 2);

        if (f[n - 1] == -1)
            f[n - 1] = fib3(n - 1);

        return f[n - 2] + f[n - 1];
    }
}

int main()
{
    int i;
    for (i = 0; i < 100; i++)
        f[i] = -1;
    printf("%d \n", fib(12));
    printf("%d \n", fib1(12));
    printf("%d \n", fib3(12));
}
