#include <stdio.h>
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)

int main() {
    int n;
    int dp_max[2][3] = {{0,},};
    int dp_min[2][3] = {{0,},};
    int a[3] = {0,};
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[j]);
        }
        dp_max[i%2][0] = max(dp_max[(i-1)%2][0], dp_max[(i-1)%2][1]) + a[0];
        dp_max[i%2][1] = max(max(dp_max[(i-1)%2][0], dp_max[(i-1)%2][1]), dp_max[(i-1)%2][2]) + a[1];
        dp_max[i%2][2] = max(dp_max[(i-1)%2][1], dp_max[(i-1)%2][2]) + a[2];

        dp_min[i%2][0] = min(dp_min[(i-1)%2][0], dp_min[(i-1)%2][1]) + a[0];
        dp_min[i%2][1] = min(min(dp_min[(i-1)%2][0], dp_min[(i-1)%2][1]), dp_min[(i-1)%2][2]) + a[1];
        dp_min[i%2][2] = min(dp_min[(i-1)%2][1], dp_min[(i-1)%2][2]) + a[2];
    }

    int max_v = max(max(dp_max[n%2][0], dp_max[n%2][1]), dp_max[n%2][2]);
    int min_v = min(min(dp_min[n%2][0], dp_min[n%2][1]), dp_min[n%2][2]);

    printf("%d %d", max_v, min_v);

    return 0;
}