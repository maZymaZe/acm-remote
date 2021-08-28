#include <cstdio>

typedef long long ll;
const ll MOD = 998244353;
ll qpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
int main() {
    ll a, b, x, y;
    scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
    printf("%lld", a * x % MOD * qpow(y, MOD - 2) % MOD);
    return 0;
}