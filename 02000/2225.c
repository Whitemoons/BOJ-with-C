#include <stdio.h>
#define MOD 1000000000

int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    int dp[n+1][k+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            for (int k = 0; k <= i; k++) {
                dp[i][j] = (dp[i][j] + dp[i-k][j-1]) % MOD;
            }
        }
    }

    printf("%d", dp[n][k]);

    return 0;
}