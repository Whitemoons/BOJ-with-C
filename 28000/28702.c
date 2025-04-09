#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char c[10] = "";
    int n = 0;

    for (int i = 3; i >= 1; i--) {
        scanf("%s", c);
        if(isdigit(c[0])) {
            n = atoi(c) + i;
        }
    }

    if (n % 3 == 0) {
        printf("Fizz");
    }
    if (n % 5 == 0) {
        printf("Buzz");
    }
    if ((n % 3 != 0) & (n % 5 != 0)) {
        printf("%d", n);
    }

    return 0;
}