#include <stdio.h>

int main() {
    int n, m;
    int x = 1, y = 1;

    scanf("%d %d", &m, &n);

    long cnt_rotate = n > m ? (m - 1) / 2 : (n - 1) / 2;

    x += cnt_rotate;
    y += cnt_rotate;

    n -= 2 * cnt_rotate;
    m -= 2 * cnt_rotate;

    if (m == 1) {
        cnt_rotate = 4 * cnt_rotate;
        x += n - 1;
    }  else if (n == 1) {
        cnt_rotate = 4 * cnt_rotate + 1;
        y += m - 1;
    } else if (m == 2) {
        cnt_rotate = 4 * cnt_rotate + 2;
        y += 1;
    } else if (n == 2) {
        cnt_rotate = 4 * cnt_rotate + 3;
        y += 1;
    } 

    printf("%ld\n", cnt_rotate);
    printf("%d %d", y, x);

    return 0;
}