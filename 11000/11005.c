#include <stdio.h>

char int_to_char(int n) {
    if (0 <= n && n < 10) {
        return '0' + n;
    } else {
        return n - 10 + 'A';
    }
}

int main() {
    int n, b;

    int ans[32] = {0,}, size = 0;

    scanf("%d %d", &n, &b);

    while (n) {
        ans[size++] = int_to_char(n % b);
        n /= b;
    }

    for (int i = --size; i >= 0; i--) {
        printf("%c", ans[i]);
    }

    return 0;
}