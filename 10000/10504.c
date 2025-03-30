#include <stdio.h>

int main() {
    int t,n,a, tmp_i;

    scanf("%d" ,&t);

    for (int _ = 0; _ < t; _++) {
        scanf("%d", &n);
        a = 0;
        for (int i = 2; i * i <= 2 * n; i++) {
            if ((2 * n) % i == 0) {
                a = (2 * n) / i - i + 1;
                if (a % 2 != 0) {
                    a = 0;
                } else {
                    a /= 2;
                    tmp_i = i;
                    break;
                }
            }
        }
        if (a) {
            printf("%d = ", n);
            for (int j = a; j < a+tmp_i; j++) {
                printf("%d ", j);
                if (j != a+tmp_i-1) {
                    printf("+ ");
                } else {
                    printf("\n");
                }
            }
            
        } else {
            printf("IMPOSSIBLE\n");
        }
    }

    return 0;
}