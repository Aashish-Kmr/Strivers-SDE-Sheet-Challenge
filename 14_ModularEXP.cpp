#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
    long long int result = 1;
    long long int base = x % m;

    while (n > 0) {
        if (n & 1) {  // check if n is odd
            result = (result * base) % m;
        }
        base = (base * base) % m;
        n >>= 1;  // divide n by 2
    }

    return (int)result;
}
