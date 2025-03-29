#include <stdio.h>
#define MOD 1000000009

int main() {
    int t,n;
    int max = 3;
    long int dp[100001][2] = {{0,},};

    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 2;
    dp[3][1] = 2;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        if (n > max) {
            for (int j = max+1; j <= n; j++) {
                dp[j][0] = (dp[j-1][1] + dp[j-2][1] + dp[j-3][1]) % MOD;
                dp[j][1] = (dp[j-1][0] + dp[j-2][0] + dp[j-3][0]) % MOD;
            }
            max = n;
        }
        printf("%ld %ld\n", dp[n][1], dp[n][0]);
    }
}