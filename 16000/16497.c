#include <stdio.h>

int main() {
    int n, date[32] = {0,};
    int a, b, k, max = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        for (int j = a; j < b; j++) {
            date[j]++;
        }
    }

    for(int i = 1; i <= 31; i++) {
        if (max < date[i]) {
            max = date[i];
        }
    }

    scanf("%d", &k);

    if (max <= k) {
        printf("1");
    } else {
        printf("0");
    }

    return 0;
}