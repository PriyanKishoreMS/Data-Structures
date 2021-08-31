#include <stdio.h>

double e(int x, int n) {
    double s = 1;
    for(; n>0; n--) {
        s = 1+x*s/n;
    }
    return s;
}

double e2(int x, int n) {
    static double s = 1;
    if(n==0) return s;
    s = 1+x*s/n;
    return e2(x, n-1);
}

int main() {
    printf("%lf ", e(1, 10));
    printf("%lf \n", e2(1, 10));
}