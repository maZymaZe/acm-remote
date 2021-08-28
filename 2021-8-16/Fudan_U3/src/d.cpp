#include <cstdio>
typedef long long ll;
const int NMAX = 502;
ll n, MOD;
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
ll c[NMAX][NMAX];
void calC() {
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}
ll g[NMAX][NMAX][NMAX];
void calG() {
    g[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        ll cur = 1;
        for (int k = 0; k + i < n; k++) {
            g[i][0][k] = cur;
            cur = cur * i % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = j; k + i <= n; k++) {
                g[i][j][k] =
                    g[i][j][k - 1] * i % MOD + g[i - 1][j - 1][k - 1] * j % MOD;
                g[i][j][k] %= MOD;
            }
        }
    }
}
ll f[NMAX][NMAX];
void calF() {
    f[1][1] = 1;
    f[2][2] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = j + (i == 1); k + i <= n; k++) {
                f[i + k][k] += f[i][j] * g[i][j][k] % MOD * c[i + k][i] % MOD;
                f[i + k][k] %= MOD;
            }
        }
    }
}
ll h[NMAX][NMAX];
void calH() {
    h[2][2] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = j + (i == 1); k + i <= n; k++) {
                h[i + k][k] += h[i][j] * g[i][j][k] % MOD * c[i + k][i] % MOD;
                h[i + k][k] %= MOD;
                h[i + k][k] +=
                    f[i][j] * 2 % MOD * c[i + k][k] % MOD * g[i][j][k] % MOD;
                h[i + k][k] %= MOD;
            }
        }
    }
}
ll ans = 0;
void calA() {
    for (int i = 1; i <= n; i++) {
        (ans += h[n][i]) %= MOD;
    }
}
int main() {
    scanf("%lld%lld", &n, &MOD);
    if (n == 2) {
        printf("%d\n", 1 % MOD);
        return 0;
    }
    calC();
    calG();
    calF();
    calH();
    calA();
    printf("%lld\n", ans);
    return 0;
}