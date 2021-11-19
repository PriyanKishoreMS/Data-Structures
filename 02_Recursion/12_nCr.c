#include <stdio.h>

int fact(int n) {
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int ncr(int n, int r) {
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n - r);

    return num / den;
}

int c(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    else
        return c(n-1, r-1) + c(n-1, r);
}

int main() {
    printf("%d \n", c(7, 3));
    printf("%d \n", ncr(7, 3));
}