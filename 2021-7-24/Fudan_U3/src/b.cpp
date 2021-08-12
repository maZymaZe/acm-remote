#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll NMAX = 5007;
ll n, m, a, b, c, d, p;
ll f[NMAX * 3], tot = 0, pe = 0;
ll ff(ll x) {
    if (f[x] == x)
        return x;
    return f[x] = ff(f[x]);
}
struct EDGE {
    int a, b, c;
    bool operator<(const EDGE& x) const { return c < x.c; }
} e[NMAX * NMAX];
ll aa[NMAX * NMAX];
int main() {
    scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &m, &a, &b, &c, &d, &p);
    int sz = n * m;
    aa[0] = a;
    for (int i = 0; i <= sz; i++) {
        aa[i + 1] = (aa[i] * aa[i] * b + aa[i] * c + d) % p;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            e[++pe] = {i, (int)n + j, (int)aa[m * (i - 1) + j]};
        }
    }
    for (int i = 1; i <= n + m; i++)
        f[i] = i;
    sort(e + 1, e + 1 + pe);
    int cnt = 1, p = 1;
    while (cnt < n + m) {
        if (ff(e[p].a) != ff(e[p].b)) {
            f[ff(e[p].a)] = ff(e[p].b);
            tot += e[p].c;
            cnt++;
        }
        p++;
    }
    printf("%lld\n", tot);
    return 0;
}