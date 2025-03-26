#include <stdio.h>
#define MOD 1000000009

int main() {
    int t,n;
    int max = 3;
    long int dp[100001] = {0,};

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        if (n > max) {
            for (int j = max+1; j <= n; j++) {
                if (j >= 2) { dp[j] = (dp[j] + dp[j-2]) % MOD; }
                if (j >= 4) { dp[j] = (dp[j] + dp[j-4]) % MOD; }
                if (j >= 6) { dp[j] = (dp[j] + dp[j-6]) % MOD; }
            }
            max = n;
        }
        printf("%ld\n", dp[n]);
    }
}