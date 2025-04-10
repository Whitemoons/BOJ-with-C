#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 300001

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int score[MAX] = {0,};
    int n;
    double tot = 0;

    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i]);   
    }

    qsort(score, n, sizeof(int), compare);

    int except = (int)round(n * 0.15);

    for (int i = except; i < n - except; i++) {
        tot += score[i];
    }

    printf("%d", (int)round(tot / (n - 2 * except)));

    return 0;
}