#include <stdio.h>

int gcd(int a, int b);

int main() {
    int n;
    int output = 0;

    scanf("%d", &n);

    for (int g = 1 ; g <= n ; g++) {
        if (n % g == 0) {
            int m = n / g;
            for(int i = 1 ; 2 * i <= m + 1 ; i++) {
                if (gcd(i, m + 1 - i) == 1) {
                    output++;
                }
            }
        }
    }

    printf("%d", output);
    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}