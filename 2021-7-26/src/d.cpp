#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const ll NMAX = 6e4, MOD = 998244353;
int n, k, tx, ty;
struct EDGE {
    int u, v, nx;
} e[NMAX << 1];
int h[NMAX], ep = 0;
void add(int x, int y) {
    e[++ep] = {x, y, h[x]};
    h[x] = ep;
    e[++ep] = {y, x, h[y]};
    h[y] = ep;
}
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            (res *= a) %= MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
vector<int> f[2][NMAX];
int s[NMAX];

void dfs(int u, int fa) {
    f[0][u] = vector<int>(1, 1);
    f[1][u] = vector<int>(1, 1);
    s[u] = 1;
    for (int i = h[u]; i; i = e[i].nx) {
        int v = e[i].v;
        if (v != fa) {
            dfs(v, u);
            int lc = min(k + 1, s[u] + s[v]);
            vector<int> c(lc), d(lc);
            int l1 = f[0][u].size();
            for (int a = 0; a < l1; a++) {
                int l2 = f[0][v].size();
                for (int b = 0; b < l2 && a + b < lc; b++) {
                    c[a + b] =
                        (c[a + b] + 1ll * f[0][u][a] * f[0][v][b] % MOD) % MOD;
                    d[a + b] =
                        (1ll * d[a + b] + 1ll * f[0][u][a] * f[1][v][b] % MOD +
                         1ll * f[1][u][a] * f[0][v][b] % MOD) %
                        MOD;
                    if (a + b + 1 < lc) {
                        c[a + b + 1] = (c[a + b + 1] +
                                        1ll * f[0][u][a] * f[1][v][b] % MOD) %
                                       MOD;
                        d[a + b + 1] = (d[a + b + 1] +
                                        1ll * f[1][u][a] * f[1][v][b] % MOD) %
                                       MOD;
                    }
                }
            }
            s[u] += s[v];
            c.swap(f[0][u]);
            d.swap(f[1][u]);
        }
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &tx, &ty);
        add(tx, ty);
    }
    dfs(1, 0);
    printf("%lld\n", qpow(n, k - 1) * f[1][1][k] % MOD);
    return 0;
}
