#include <stdio.h>
#include <stdbool.h>

int count_digits(int n);
int next_palindrome(int n);
bool is_prime(int n);
bool is_palindrome(int n);

int main(void) {
    int n;
    int palindrome;

    scanf("%d", &n);

    if (is_palindrome(n)) {
        palindrome = n;
    } else {
        palindrome = next_palindrome(n);
    }

    if (n > palindrome) {
        palindrome = next_palindrome(palindrome);
    }

    while (!is_prime(palindrome)) {
        palindrome = next_palindrome(palindrome);
    }

    printf("%d", palindrome);

    return 0;
}

int count_digits(int n) {
    int digit = 0;

    while (n != 0) {
        n /= 10;
        digit++;
    }

    return digit;
}

int next_palindrome(int n) {
    int n_digit = count_digits(n);

    int tmp = 0;
    
    for (int i = 0; i < n_digit/2; i++) { 
        tmp = tmp * 10 + n % 10;
        n /= 10;
    }

    if ((n_digit % 2 == 1 && tmp >= n / 10) || (n_digit % 2 == 0 && tmp >= n)) {
        n++;
    }

    int rev_n = n;

    if (n_digit % 2 == 1 || n_digit - n_digit/2 < count_digits(n)) { rev_n /= 10; }
    if (n_digit % 2 == 1 && n_digit - n_digit/2 < count_digits(n)) { n /= 10; }

    while (rev_n != 0) {
        n = n * 10 + rev_n % 10;
        rev_n /= 10;
    }
    
    return n;
}

bool is_prime(int n) {
    if (n == 1) { return false; }
    if (n == 2) { return true; }
    if (n % 2 == 0) { return false; }

    bool is_p = true;

    for (int i = 3; i * i <= n; i++) {
        if ( n % i == 0 ) {
            is_p =  false; 
            break;
        }
    }
    
    return is_p;
}

bool is_palindrome(int n) {
    int n_digit = count_digits(n);
    int rev_n = 0;
    for (int i = 0; i < n_digit/2; i++) { 
        rev_n = rev_n * 10 + n % 10;
        n /= 10; 
    }

    if (n_digit % 2 == 1) {
        n /= 10;
    }

    if(rev_n == n) {
        return true;
    } else {
        return false;
    }
}