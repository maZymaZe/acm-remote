#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll P = 998244353;

ll n, w[107], p[107], frac = 0, e[107], ans, sum[107], score[107];
ll inv[107], ee[107];

ll pow_mod(ll a, ll i) {
    if (i == 0)
        return 1ll % P;
    ll tmp = pow_mod(a, i >> 1ll);
    tmp = tmp * tmp % P;
    if (i & 1ll)
        tmp = tmp * a % P;
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> w[i], frac += w[i];
    frac = pow_mod(frac, P - 2);
    for (int i = 1; i <= n; ++i) {
        p[i] = w[i] * frac % P;
        // sum[i] = (sum[i - 1] + p[i]) % P;
    }
    ll sum_e = 0;
    for (int i = n; i >= 1; i--) {
        // calculate e[i]
        // e[i]: the estimated max length start with i
        inv[i] = pow_mod((1 - p[i] + P) % P, P - 2);
        e[i] = (1 + sum_e) % P * inv[i] % P;
        sum_e = (sum_e + p[i] * e[i] % P) % P;
        ee[i] = sum_e;
    }
    ll sum_s = 0;
    for (int i = n; i >= 1; i--) {
        // score[i]: estimated score
        score[i] = (1 + sum_s + 2ll * ee[i]) % P * inv[i] % P;
        sum_s = (sum_s + p[i] * score[i] % P) % P;
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + (score[i] + 2ll * e[i] + 1) * p[i] % P) % P;
    }
    cout << ans << "\n";
    return 0;
}
