#include <stdio.h>

int main() {
    int n, t, p;
    int ts[6];
    int output = 0;

    scanf("%d ", &n);
    for (int i = 0; i < 6; i++) {
        scanf("%d ", &ts[i]);
    }
    scanf("%d %d", &t, &p);

    for (int i = 0; i < 6; i++) {
        output += ts[i] / t + (ts[i] % t ? 1 : 0);
    }

    printf("%d\n", output);
    printf("%d %d", n / p, n % p);

    return 0;
}