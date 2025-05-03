#include <stdio.h>
#include <string.h>

int main() {
    char c[101] = {0,};

    scanf("%s", c);

    printf("%lu", strlen(c));

    return 0;
}