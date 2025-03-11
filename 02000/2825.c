#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;
    long pair[1024] = {0,};
    char friends[20] = "";
    long output = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", friends);
        int t = 0;
        for (int j = 0; j < (int)strlen(friends); j++) {
            int num = friends[j] - '0';
            t = t | 1 << num;
        }
        pair[t]++;
    }

    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) {
            if (i & j) {
                output += pair[i] * pair[j];
            }
        }
    }
    
    
    printf("%ld", (output - n)/2);

    return 0;
}