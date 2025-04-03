#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if (n == 1) {
        printf("1");
    } else if(n == 2) {
        printf("4");
    } else if (n % 2 == 1) {
        printf("%d", n+1);
    } else if (n % 2 == 0) {
        printf("%d", n);
    }

    return 0;
}