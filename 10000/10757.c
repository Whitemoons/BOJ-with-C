#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* add_big_numbers(const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxlen = (len1 > len2 ? len1 : len2) + 1; // 최대 자리수 + carry

    char* result = (char*)malloc(maxlen + 2); // +1 for null-terminator
    if (!result) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    result[maxlen] = '\0';

    int carry = 0, sum, i = len1 - 1, j = len2 - 1, k = maxlen - 1;
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        sum = digit1 + digit2 + carry;
        result[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (result[0] == 0) {
        memmove(result, result + 1, maxlen);
    }

    return result;
}


int main() {
    char a[10001],b[10001];

    scanf("%s\n%s", a, b);

    char* sum = add_big_numbers(a, b);
    printf("%s\n", sum);
    free(sum);

    return 0;
}