#include <stdio.h>
#include <stdbool.h>

bool check(int cnt[10]) {
    int c = 0;
    for (int i = 0; i < 10; i++) {
        if(cnt[i] != 0) {
            c++;
        }
    }
    if(c >2) return false;
    else return true;
}

int main() {
    int l = 0, r = 0;
    int cnt[10] = {0,};
    int n;
    int res = 0;

    scanf("%d", &n);

    short int tang[n];

    for (int i = 0; i < n; i++) {
        scanf("%hd", &tang[i]);
    }
    
    while (l < n) {
        while (r < n) {
            cnt[tang[r++]]++;
            if(!check(cnt)) {
                r--;
                cnt[tang[r]]--;
                break;
            }
        }
        res = res < r - l ? r - l : res;
        cnt[tang[l++]]--;
    }
    
    printf("%d", res);

    return 0;
}