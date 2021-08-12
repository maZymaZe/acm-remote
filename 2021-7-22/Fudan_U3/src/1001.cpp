#include <cstring>
#include <iostream>

using namespace std;

#define mod 1000000007
#define inv3 333333336

long long n;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        n--;
        n %= mod;
        long long ans =
            n % mod * (n + 1) % mod * (n + 1) % mod * n % mod * 2 % mod;
        printf("%lld\n", ans);
    }
    return 0;
}