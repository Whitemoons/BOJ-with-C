#include <stdio.h>

int main() {
    int n;
    int t = 5;
    int ans = 0;
    while (t--) {
        scanf("%d", &n);
        ans += n;
    }
    printf("%d", ans);
    return 0;
}