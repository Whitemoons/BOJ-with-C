#include <stdio.h>

int main() {
    int l;
    int score = 0;
    char c;

    scanf("%d ", &l);

    for (int i = 0; i < l; i++) {
        scanf("%c", &c);
        score += c - 'A' + 1;
    }

    printf("%d", score);

    return 0;
}