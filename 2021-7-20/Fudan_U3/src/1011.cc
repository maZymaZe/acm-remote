#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll P = 998244353;
const int kMax = 1000007;

ll fac[kMax], invfac[kMax], inv[kMax], phi[kMax], p[kMax], f[kMax];

ll vis[kMax], prime[kMax], cnt;

void Pre() {
    phi[1] = p[0] = fac[0] = invfac[0] = inv[1] = fac[1] = invfac[1] = 1;
    p[1] = 2;
    for (ll i = 2; i < kMax; ++i) {
        if (!vis[i])
            prime[++cnt] = i, phi[i] = i - 1;
        for (ll j = 1; j <= cnt && i * prime[j] < kMax; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
        p[i] = p[i - 1] * 2ll % P;
        inv[i] = P / i * (P - inv[P % i]) % P;
        fac[i] = fac[i - 1] * i % P;
        invfac[i] = invfac[i - 1] * inv[i] % P;
    }
}

ll C(ll n, ll m) {
    if (n < 0 || m < 0 || m > n)
        return 0;
    return fac[n] * invfac[m] % P * invfac[n - m] % P;
}

ll G(ll n, ll k) {
    f[0] = n & 1 ? 0 : 2;
    for (ll m = 1; m <= n; ++m) {
        f[m] = (p[m] * (C(n - m, m) + C(n - m - 1, m - 1)) + f[m - 1]) % P;
    }
    return f[min(n, k)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    Pre();
    while (t--) {
        ll ans = 0;
        ll n, k;
        cin >> n >> k;
        for (ll d = 1; d <= n; ++d) {
            if (n % d == 0) {
                ans = (ans + phi[n / d] * G(d, k * d / n)) % P;
            }
        }
        cout << ans * inv[n] % P << "\n";
    }
    return 0;
}
