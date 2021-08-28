#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;
const ll G = 3, P = 998244353;
const int N = 5e5 + 10, K = 1e6 + 1;
int n;
ll a[N], inv[N], fac[N], ifac[N];
int f[K], g[K];

ll POW(ll a, ll x) {
    if (!x)
        return 1 % P;
    ll ret = POW(a, x >> 1ll);
    (ret *= ret) %= P;
    if (x & 1ll)
        (ret *= a) %= P;
    return ret;
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0)
        return x = 1, y = 0, a;
    ll t = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return t;
}

ll INV(ll a, ll n = P) {
    ll x, y;
    if (exgcd(a, n, x, y) == 1)
        return (x % n + n) % n;
    return -1;
}

void ntt(vi& a, int op = 1) {
    int n = a.size();
    for (int i = 1, j = 0; i < n - 1; ++i) {
        for (int s = n; j ^= s >>= 1, ~j & s;) {
        }
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int i = 1; i < n; i *= 2) {
        ll u = POW(G, (P - 1) / (i * 2));
        if (op == -1)
            u = INV(u);
        for (int j = 0; j < n; j += i * 2) {
            ll w = 1;
            for (int k = 0; k < i; ++k, w = w * u % P) {
                int x = a[j + k], y = w * a[j + k + i] % P;
#define modto(x)      \
    ({                \
        if ((x) >= P) \
            (x) -= P; \
    })
                a[j + k] = x + y;
                modto(a[j + k]);
                a[j + k + i] = x - y + P;
                modto(a[j + k + i]);
#undef modto
            }
        }
    }
    if (op == -1) {
        ll inv = INV(n);
        for (int i = 0; i < n; ++i)
            a[i] = a[i] * inv % P;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        inv[i] = P / i * (P - inv[P % i]) % P;
        fac[i] = fac[i - 1] * i % P;
        ifac[i] = ifac[i - 1] * inv[i] % P;
    }
    ll ans = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        (ans *= (a[i] + 1)) %= P;
        (ans *= ifac[i]) %= P;
        f[a[i]]++;
        g[K - 1 - a[i]]++;
    }
    int n = 1;
    while (n < 2 * K)
        n *= 2;
    vi fa(n), fb(n), fc(n);
    copy(f, f + K + 1, fa.begin());
    ntt(fa);
    copy(g, g + K + 1, fb.begin());
    ntt(fb);
    for (int i = 0; i < n; ++i) {
        fc[i] = (ll)fa[i] * fb[i] % P;
    }
    ntt(fc, -1);
    for (ll i = 1; K + i < n; ++i) {
        (ans *= POW(i, fc[K - 1 + i])) %= P;
    }
    cout << ans << '\n';
    return 0;
}
