#include <stdio.h>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define INF 1e9

int main() {
    int n,k;
    int a[2][210] = {{0,},};
    int dp[3][210][210] = {{{0,},},};
    int output = 0;

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n+1; i++) {
        scanf("%d %d", &a[0][i], &a[1][i]);
        output += a[0][i] + a[1][i];
    }

    for (int j = 1; j <= k; j++) {
        dp[0][0][j] = INF;
        dp[1][0][j] = INF;
        dp[2][0][j] = INF;
    }


    
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            dp[0][i][j] = min(dp[0][i-1][j], min(dp[1][i-1][j], dp[2][i-1][j]));
            dp[1][i][j] = min(dp[1][i-1][j-1], dp[0][i-1][j-1]) + a[0][i];
            dp[2][i][j] = min(dp[2][i-1][j-1], dp[0][i-1][j-1]) + a[1][i];
        }
    }

    output -= min(dp[0][n][k], min(dp[1][n][k], dp[2][n][k]));
    
    printf("%d", output);

    return 0;
}
