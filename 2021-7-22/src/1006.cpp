#include <cstdio>
const int NMAX = 610000;
const long long MOD = 1e9 + 7;
long long m, a[NMAX], b[NMAX], c[NMAX], a1[NMAX], a2[NMAX], n;
void g1(long long& xa, long long& xb, long long& xc) {
    long long aa = xa, bb = xb, cc = xc;
    xa = aa, xb = (aa + bb + cc) % MOD, xc = (aa + cc) % MOD;
}
void g2(long long& xa, long long& xb, long long& xc) {
    long long aa = xa, bb = xb, cc = xc;
    xa = aa, xb = (bb - cc) % MOD, xc = (cc - aa) % MOD;
}
void fwt(long long* a, int o) {
    for (int i = 1; i < m; i *= 3) {
        for (int j = 0; j < m; j += (i * 3)) {
            for (int k = 0; k < i; k++) {
                if (o == 0) {
                    g1(a[j + k], a[j + k + i], a[j + k + 2 * i]);
                } else {
                    g2(a[j + k], a[j + k + i], a[j + k + 2 * i]);
                }
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &b[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &c[i]);
    long long ans = 0, ans2 = 0;
    for (int j = n; j > 0; j--) {
        int k = n / j;
        for (int i = 1; i <= k; i++)
            a1[i] = a[i], a2[i] = b[i];
        m = 1;
        while (m <= k)
            m *= 3;
        ans2 += m;
        fwt(a1, 0), fwt(a2, 0);
        for (int i = 0; i < m; i++)
            a1[i] = a1[i] * a2[i] % MOD;

        fwt(a1, 1);
        long long p = 1;
        for (int i = 1; i <= m; i++) {
            p = p * c[j] % MOD;
            ans = (ans + a1[i] * p) % MOD;
        }
        for (int i = 1; i <= m; i++)
            a1[i] = a2[i] = 0;
    }
    printf("%lld\n", (ans + MOD) % MOD);
    return 0;
}