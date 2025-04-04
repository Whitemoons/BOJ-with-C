#include <stdio.h>

int cal_num(int n) {
    int ans = 10;
    while (n >= 10) {
        n /= 10;
        ans *= 10;
    }
    return ans;
}

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", a+b-c);
    printf("%d", a*cal_num(b) + b - c);
    return 0;
}