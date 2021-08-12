#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int n = 1000;
    for (int i = 1; i <= n; i++) {
        printf("%d:", i);
        for (int j = 1; j <= n; j++) {
            if (__gcd(i, j) == (i ^ j)) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        if (__gcd(2 * i, 3 * i) == ((2 * i) ^ (3 * i))) {
            printf("%d ", i);
        }
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        if (__gcd(4 * i, 5 * i) == ((4 * i) ^ (5 * i))) {
            printf("%d ", i);
        }
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        if (__gcd(13 * i, 12 * i) == ((13 * i) ^ (12 * i))) {
            printf("%d ", i);
        }
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        if (__gcd(17 * i, 16 * i) == ((16 * i) ^ (17 * i))) {
            printf("%d ", i);
        }
    }
    printf("\n");
}