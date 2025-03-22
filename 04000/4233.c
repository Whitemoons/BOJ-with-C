#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n);
int square_a(int p, int a);

int main() {
    int p,a;

    while (1) {
        scanf("%d %d", &p, &a);
        if( p == 0 && a == 0) {
            break;
        }

        if (is_prime(p)) {
            printf("no\n");
        } else {
            if(a == square_a(p,a)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }

    }
    

    return 0;
}

bool is_prime(int n) {
    if (n == 1) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    } else {
        for (int i = 3; i*i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int square_a(int p, int a) {
    long long int output = 1;
    int mod = p;
    long long int m = a;
    while (p > 0) {
        if((p & 1) == 1) {
            output = (output * m) % mod;
        }
        p >>= 1;
        m = (m*m) % mod;
    }
    
    return output;
}