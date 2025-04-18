#include <stdio.h>

int main() {
    int n;
    int dp[1000001] = {0,};

    dp[1] = 1;
    dp[2] = 2;

    scanf("%d", &n);

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }

    printf("%d", dp[n]);

    return 0;
}