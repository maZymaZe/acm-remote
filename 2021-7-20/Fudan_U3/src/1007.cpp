#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll P = 998244353;

ll bsgs(ll S, ll T, ll A, ll m) {
    ll len = llround(sqrt(m));
    unordered_map<ll, ll> H;
    ll B = 1 % m;
    for (ll i = 1; i <= len; ++i) {
        B = B * A % m, H[T * B % m] = -i;
    }
    ll C = B;
    ll ret = 1e12;
    for (ll i = len; i - len < m; i += len, C = C * B % m) {
        if (H.count(S * C % m))
            ret = min(ret, i + H[S * C % m]);
    }
    if (ret < 1e10)
        return ret;
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n, x;
        scanf("%lld%lld", &n, &x);
        if (x == 0) {
            printf("1\n");
            continue;
        }
        if (x == 1) {
            printf("0\n");
            continue;
        }
        ll even = bsgs(1 % P, (n * x - n + 1) % P, n - 1, P);
        if (even != -1 && ((even & 1) == 1))
            even = -1;
        ll odd = bsgs(1 % P, (n * x + n - 1) % P, n - 1, P);
        if (odd != -1 && ((odd & 1) == 0))
            odd = -1;
        if (even == -1 && odd == -1) {
            printf("-1\n");
        } else if (even == -1) {
            printf("%lld\n", odd);
        } else if (odd == -1) {
            printf("%lld\n", even);
        } else {
            printf("%lld\n", min(odd, even));
        }
    }
    return 0;
}