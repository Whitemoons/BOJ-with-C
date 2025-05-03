#include <stdio.h>

int main() {
    char c[101] = {0,};

    scanf("%s",c);

    int i = 0;
    while (c[i]) {
        if ('A' <= c[i] && c[i] <= 'Z') {
            printf("%c", c[i] - 'A' + 'a');
        } else {
            printf("%c", c[i] - 'a' + 'A');
        }
        i++;
    }
}