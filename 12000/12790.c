#include <stdio.h>

int main() {
    int t;
    int a[8] = {0,};

    scanf("%d", &t);

    while (t--) {
        for (int i = 0; i < 8; i++) {
            scanf("%d", &a[i]);
        }
        int f_hp = a[0] + a[4] < 1 ? 1 : a[0] + a[4];
        int f_mp = a[1] + a[5] < 1 ? 1 : a[1] + a[5];
        int f_ap = a[2] + a[6] < 0 ? 0 : a[2] + a[6];
        int f_dp = a[3] + a[7];
        printf("%d\n", f_hp + 5*f_mp + 2*f_ap + 2*f_dp);
    }
    

    return 0;
}