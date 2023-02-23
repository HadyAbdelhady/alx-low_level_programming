#include <stdio.h>
#include <stdbool.h>

bool is_prime(long long n) {
    if (n < 2) {
        return false;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long n = 612852475143;
    long long largest_prime_factor = 1;

    // Try dividing n by all possible factors up to its square root
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // Check if i is prime and greater than previous largest prime factor
            if (is_prime(i) && i > largest_prime_factor) {
                largest_prime_factor = i;
            }

            // Check if n/i is prime and greater than previous largest prime factor
            if (is_prime(n/i) && (n/i) > largest_prime_factor) {
                largest_prime_factor = n/i;
            }
        }
    }

    printf("%lld\n", largest_prime_factor);
    return 0;
}
