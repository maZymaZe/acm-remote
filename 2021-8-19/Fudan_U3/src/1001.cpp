#include <cstdio>
#include <cstring>
typedef long long ll;
int T, n, MOD;
const int NMAX = 3004;
int c[NMAX][NMAX];
ll ak[NMAX], bk[NMAX];
ll ans[NMAX], ans0 = 0;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &MOD);
        memset(ans, 0, sizeof(ans));
        ans0 = 0;
        for (int i = 0; i <= n; i++) {
            c[i][0] = 1 % MOD;
            for (int j = 1; j <= i; j++) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
            }
        }
        for (int k = 1; k <= n; k++) {
            ak[0] = bk[0] = 1;
            for (int i = 1; i <= n - k; i++) {
                ak[i] = ak[i - 1] * k % MOD;
                bk[i] = bk[i - 1] * (k - 1) % MOD;
            }
            ll sum = 0;
            for (int i = 1; i <= n - k; i++) {
                ll v = ak[i - 1] * bk[n - k - i] % MOD * c[n - i - 1][k - 1];
                sum = (sum + v) % MOD;
                ans0 = (ans0 + v % MOD * k) % MOD;
            }
            ans0 = (ans0 + bk[n - k] * c[n - 1][k - 1]) % MOD;
            ans[k] = (sum * n + bk[n - k] * c[n][k]) % MOD;
        }
        for (int i = n; i > 0; i--)
            ans[i] = (ans[i] + ans[i + 1]) % MOD;
        printf("%lld\n", ans0);
        for (int i = 1; i < n; i++)
            printf("%lld ", ans[i]);
        printf("%lld\n", ans[n]);
    }
    return 0;
}