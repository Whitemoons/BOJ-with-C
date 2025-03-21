#include <stdio.h>

int main() {
    int n;
    char like[50] = "";

    scanf("%d", &n);
    n+=1;

    int i = 0;

    do {
        if ((n & 1) == 0) {
            like[i] = '4';
        } else {
            like[i] = '7';
        }

        n >>= 1;
        i++;
    } while (n > 1);
    
    for (int j = i-1; j >= 0; j--) {
        printf("%c",like[j]);
    }

}