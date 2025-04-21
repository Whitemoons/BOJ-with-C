#include <stdio.h>

int main() {
    int n, pos = 0;
    int a[1000] = {0,}, b[1000] = {0,};
    a[0] = a[1] = 1;

    scanf("%d", &n);

    for (int j = 2; j <= n; j++) {
        for (int i = 0; i < 1000; i++) b[i] = 0;
        for (int k = 1; 2 * k <= j; k++) {
            int t = 2*a[j-k] -a[j-2*k];
            if (t >= 0) b[t] = 1;
        }
        for (int i = 1; i <= 1000; i++) {
            if (!b[i]) {
                a[j] = i;
                break;
            }
        }
    }
    
    printf("%d", a[n]);

    return 0;
}