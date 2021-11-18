#include <stdio.h>

int sum(int n) {
    if(n==0)
    return 0;
    else {
        return sum(n-1)+n;
    }
}

int main() {
    int x;
    printf("Enter the value: ");
    scanf("%d", &x);
    printf("%d", sum(x));
}