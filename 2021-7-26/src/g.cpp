#include <cstdio>
typedef long long ll;
const ll MOD = 998244353, KMAX = 60;
ll n, k, d;
ll inva[KMAX], dp[KMAX][KMAX * KMAX], c[210][210], ans;
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
ll inv(ll x) {
    return qpow(x, MOD - 2);
}
ll ch(int tot, int x) {
    ll ret = 1;
    for (int i = 1; i <= x; i++) {
        ret = ret * (tot - i + 1) % MOD * inva[i] % MOD;
    }
    return ret;
}

int main() {
    scanf("%lld%lld%lld", &n, &k, &d);
    for (int i = 1; i <= k; i++)
        inva[i] = inv(i);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= (i - 1) * (k - 1); j++) {
            for (int l = 0; l < k; l++) {
                dp[i][j + l] =
                    (dp[i][j + l] + dp[i - 1][j] * ch(d + n * k - j, l)) % MOD;
            }
        }
    }
    c[0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    // c为选出n中l位<k,dp为分法，qpow为计算另一边
    for (int l = 0; l <= n; l++) {
        for (int t = 0; t <= (k - 1) * l; t++) {
            ans = (ans + qpow(-1, l) * c[n][l] * dp[l][t] % MOD *
                             qpow(n - l, d + n * k - t)) %
                  MOD;
        }
    }
    for (int i = 1; i <= n * k; i++) {
        ans = ans * inv(d + i) % MOD;
    }
    ans = (ans + MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}