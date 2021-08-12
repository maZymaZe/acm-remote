#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007
#define inv2 500000004
#define inv6 166666668

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n);
        n %= mod;
        ll minc = n * n % mod * (n + 1) % mod * (n + 1) % mod * (2 * n + 1) %
                  mod * inv2 % mod * inv6 % mod;
        minc += (2 + n) * (n - 1) % mod * inv2 % mod *
                (((2 + n) * (n - 1) % mod * inv2 % mod) +
                 (n * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod - 1)) %
                mod;
        printf("%lld\n", minc % mod);

        ll maxc = n * n % mod * n % mod * n % mod * (n + 1) % mod * (n + 1) %
                  mod * (2 * n + 1) % mod * inv2 % mod * inv6 % mod;
        printf("%lld\n", maxc);
    }
    return 0;
}