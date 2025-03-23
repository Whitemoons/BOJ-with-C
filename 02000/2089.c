#include <stdio.h>

int main() {
    int n;
    char two[50] = "";

    scanf("%d", &n);

    int i = 0;

    if (n == 0) {
        two[i] = '0';
        i++;
    }

    while (n != 0) {
        if (n % (-2) != 0) {
            two[i] = '1';
            n = (n-1) / (-2);
        } else {
            two[i] = '0';
            n = n / (-2);
        }
        
        i++;
    }

    for (int j = i-1; j >= 0; j--) {
        printf("%c",two[j]);
    }
    
    

    return 0;
}