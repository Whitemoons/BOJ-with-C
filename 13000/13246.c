#include <stdio.h>
#define MOD 1000

void mul_mat(int a[5][5], int b[5][5], int res[5][5], int n);

int main() {
    int n;
    long b;
    int a[5][5] = {{0,},};
    int sum_a[5][5] = {{0,},};

    int mul_factor[5][5] = {{0,},};

    int output[5][5] = {{0,},};

    scanf("%d %ld", &n, &b);

    for (int i = 0; i < n; i++) {
        sum_a[i][i] = 1;
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            mul_factor[i][j] = a[i][j];
        }
    }

    while (b) {
        if (b & 1) {
            int partial_sum[5][5];
            mul_mat(mul_factor, sum_a, partial_sum, n);
            mul_mat(mul_factor, a, mul_factor, n);
            for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { output[i][j] = (output[i][j] + partial_sum[i][j]) % MOD; } }
        }
        
        b >>= 1;
        for (int i = 0; i < n; i++) a[i][i]++;
        mul_mat(sum_a, a, sum_a, n);
        for (int i = 0; i < n; i++) a[i][i]--;
        
        mul_mat(a, a, a, n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}

void mul_mat(int a[5][5], int b[5][5], int res[5][5], int n) {
    int c[5][5] = {{0,},};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0; 
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];  
            }
            c[i][j] %= MOD;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = c[i][j];
        }
    }

    return;
}