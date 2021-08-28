#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 998244353LL
#define N 110

ll quick(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll C[N][N];
ll inv[N];
ll B[N];
ll A[N][N];
ll dp[N * 2][N][N];
bool vis[N * 2][N][N];

void pre() {
    inv[1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    for (int i = 0; i < N; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    B[0] = 1;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < i; j++) {
            B[i] += mod - C[i][j] * B[j] % mod * inv[i + 1 - j] % mod;
            B[i] %= mod;
        }
    }
    B[1] = inv[2];
    for (int i = 0; i < N - 1; i++)
        for (int j = 1; j <= i + 1; j++)
            A[i][j] = C[i + 1][j] * inv[i + 1] % mod * B[i + 1 - j] % mod;
}

ll sum(ll n, ll p) {
    ll ret = 0;
    for (int i = p + 1; i >= 1; i--)
        ret = (ret * n + A[p][i]) % mod;
    return ret * n % mod;
}

ll cal(ll n, ll a, ll b, ll c, ll p, ll q, ll d = 0) {
    if (n < 0)
        return 0;
    if (vis[d][p][q])
        return dp[d][p][q];
    vis[d][p][q] = 1;
    ll& res = dp[d][p][q] = 0;
    if (!q)
        res = sum(n, p) + (!p);
    else if (!a) {
        res = quick(b / c, q) * (sum(n, p) + (!p)) % mod;
    } else if (a >= c) {
        ll m = a / c, r = a % c, mp = 1;
        for (int j = 0; j <= q; j++, mp = mp * m % mod)
            res +=
                C[q][j] * mp % mod * cal(n, r, b, c, p + j, q - j, d + 1) % mod,
                res %= mod;
    } else if (b >= c) {
        ll m = b / c, r = b % c, mp = 1;
        for (int j = 0; j <= q; j++, mp = mp * m % mod)
            res += C[q][j] * mp % mod * cal(n, a, r, c, p, q - j, d + 1) % mod,
                res %= mod;
    } else {
        ll m = (a * n + b) / c;
        for (int k = 0; k < q; k++) {
            ll s = 0;
            for (int i = 1; i <= p + 1; i++) {
                s += A[p][i] * cal(m - 1, c, c - b - 1, a, k, i, d + 1) % mod,
                    s %= mod;
            }
            res += C[q][k] * s % mod, res %= mod;
        }
        res = (quick(m, q) * sum(n, p) + mod - res) % mod;
    }
    return res;
}

ll a, b, c, p, q, n;

int main() {
    pre();
    scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &p, &q, &n);
    ll ans = 0;
    for (int i = 1; i <= q + 1; i++)
        ans = (ans + A[q][i] * cal(n, a, b, c, p, i)) % mod;
    printf("%lld\n", (ans + mod) % mod);
    return 0;
}