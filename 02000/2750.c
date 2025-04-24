#include <stdio.h>

int main() {
    int n;
    int arr[1000] = {0,};
    int tmp, j;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 1; i < n; i++) {
        tmp = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > tmp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n",arr[i]);
    }

    return 0;
}