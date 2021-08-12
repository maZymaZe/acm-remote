#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007

ll t, v, r;

ll quick(ll a, ll b) {
    ll res = 1, temp = a;
    while (b) {
        if (b & 1)
            res = res * temp % mod;
        temp = temp * temp % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &t, &v, &r);
        ll a = t * t * v * v + 25 * t * t * t * t;
        ll b = 10 * t * t * t * v;
        // printf("%d %d\n", a, b);
        if (a + b <= r * r)
            puts("0");
        else if (a - b >= r * r)
            puts("1");
        else {
            printf("%lld\n",
                   (a + b - r * r) % mod * quick(2 * b, mod - 2) % mod);
        }
    }
    return 0;
}