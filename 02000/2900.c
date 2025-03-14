#include <stdio.h>

int main() {
    int n,k,q;
    long arr[1000001] = {0, };
    long map[1000001] = {0, };

    scanf("%d %d", &n, &k);
    
    int x;

    for (int _ = 0 ; _ < k ; _++) {
        scanf("%d", &x);
        map[x]++;
    }

    for (int i = 1 ; i <= n ; i++) {
        if (map[i] != 0) {
            int j = 0;
            while (j < n) {
                arr[j] += map[i];
                j += i;
            }
        }
    }

    map[0] = 0;

    for (int i = 1 ; i <= n ; i++) {
        map[i] = map[i-1] + arr[i-1];
    }

    scanf("%d", &q);

    int l,r;

    for (int _ = 0 ; _ < q ; _++) {
        scanf("%d %d", &l, &r);
        printf("%ld\n", map[r+1] - map[l]);
    }

    return 0;
}