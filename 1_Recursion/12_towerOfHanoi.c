#include <stdio.h>
#include <string.h>

void toh(int n, char *a, char *b, char *c) {
    if(n>0) {
        toh(n-1, a, c, b);
        printf("%s to %s  \n", a, c);
        toh(n-1, b, a, c);
    }
}

int main() {
    int m;
    printf("Enter the no. of disks: ");
    scanf("%d", &m);
    toh(m, "A", "B", "C");
}

