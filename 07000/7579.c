#include <stdio.h>
#define max(x,y) (x>y?x:y)

int main() {
    int n,m;

    int mem[101] = {0,}, c[101] = {0,};
    int dp[10001] = {0,};

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) { scanf("%d", &mem[i]); }
    for(int i = 0; i < n; i++) { scanf("%d", &c[i]); }

    for (int i = 0; i < n; i++) {
        for (int j = 100 * 100; j >= c[i]; j--) {
            dp[j] = max(dp[j], dp[j-c[i]]+mem[i]);
        }
    }
    
    for(int j = 0; j <= 100 * 100; j++) {
        if (dp[j] >= m) {
            printf("%d",j);
            break;
        }
    }

    return 0;
}