#include <stdio.h>

int main() {
    int a, b, d, N;
    int arr[1000001] = {0, };

    scanf("%d %d %d %d", &a, &b, &d, &N);

    arr[0] = 1;

    for (int i = 1; i <= N; i++) {
        arr[i] = arr[i-1];
        if (i - a >= 0) { 
            arr[i] += arr[i-a];
        }
        if (i - b >= 0) {
            arr[i] -= arr[i-b]; 
        }

        arr[i] %= 1000;
    }

    int output = arr[N] - (N >= d ? arr[N-d] : 0);

    printf("%d", (output % 1000 + 1000) % 1000);

    return 0;
}