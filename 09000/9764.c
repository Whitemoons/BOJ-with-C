#include <stdio.h>
#define MOD 100999


int dp[2001][2001] = {0,};

int main () {
    int t,n;

    scanf("%d", &t);

    dp[0][0] = 1;

    for (int i = 1; i <= 2000; i++) {
        for (int j = 1 ; j < i; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-j][j-1]) % MOD;
        }
        dp[i][i] = (dp[i][i-1] + 1) % MOD;
        for (int j = i+1; j <= 2000; j++) {
            dp[i][j] = dp[i][i];
        }
    }

    while (t--) {
        scanf("%d", &n);
        printf("%d\n", dp[n][n]);
    }

    return 0;
}