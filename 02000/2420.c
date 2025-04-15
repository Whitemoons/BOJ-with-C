#include <stdio.h>

int main() {
    long int n, m;
    scanf("%ld %ld", &n, &m);

    printf("%ld", n - m > 0 ? n - m : m - n);

    return 0;
}