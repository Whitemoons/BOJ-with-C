#include <stdio.h>

#define MOD 1000000000;

int main() {
    int n;
    int dp[2][10] = {{0, }, };
    int output = 0;
    
    scanf("%d", &n);

    for (int i = 1; i < 10; i++) {
        dp[0][i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i%2][j] = ((j >= 1 ? dp[(i-1)%2][j-1] : 0) + (j <= 8 ? dp[(i-1)%2][j+1] : 0)) % MOD
        }
    }

    for (int i = 0; i < 10; i++) {
        output = (output + dp[(n-1)%2][i]) % MOD;
    }

    printf("%d", output);

    return 0;
}