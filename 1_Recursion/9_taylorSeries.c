#include <stdio.h>
    
//     double p=1, f=1;

// double e(int x, int n) {

//     double r;
//     if(n==0) {
//       return (1);
//     } else {
//         r=e(x, n-1);
//         p=p*x;
//         f=f*n;
//         return r+p/f;
//     }
// }

double p(int x, int n) {
    if(n==0) return 1;
    return p(x, n-1)*x;
}

double f(int n) {
    if(n==0) return 1;
    return f(n-1)*n;
}

double e(int x, int n) {
    if(n==0) return 0;
    double r = p(x, n-1)/f(n-1);
    return r + e(x, n-1);
}

int main() {
    printf("%lf", e(1, 10));
    return 0;
}