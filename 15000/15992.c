#include <stdio.h>
#define MOD 1000000009

int main() {
    int t,n,m;
    int max = 3;
    long int dp[1001][1001] = {{0,},};

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);

        if (n > max) {
            for (int j = max+1; j <= n; j++) {
                for (int k = 1; k <= j; k++) {
                    dp[j][k] = (dp[j-1][k-1] + dp[j-2][k-1] + dp[j-3][k-1]) % MOD;
                }
            }
            max = n;
        }
        printf("%ld\n", dp[n][m]);
    }
}