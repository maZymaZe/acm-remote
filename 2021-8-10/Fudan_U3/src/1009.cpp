#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int NMAX = 2e5 + 10, MOD = 1e9 + 7;
const long long INF = 1e18 + 2;
struct POINT {
    int x, y;
    POINT(int a = 0, int b = 0) { x = a, y = b; }
    friend POINT operator+(POINT p1, POINT p2) {
        return POINT(p1.x + p2.x, p1.y + p2.y);
    }
    friend POINT operator-(POINT p1, POINT p2) {
        return POINT(p1.x - p2.x, p1.y - p2.y);
    }
    long long mod2() { return (long long)x * x + (long long)y * y; }
    long double mod() { return sqrtl(mod2()); }
} a[NMAX], b[NMAX];
long long mulPoint(POINT p1, POINT p2) {
    return (long long)p1.x * p2.x + (long long)p1.y * p2.y;
}
long long mulCross(POINT p1, POINT p2) {
    return (long long)p1.x * p2.y - (long long)p2.x * p1.y;
}
long double disptos(POINT p, POINT s1, POINT s2) {
    POINT v = p - s1, u = s2 - s1;
    if (mulPoint(u, v) < 0 || mulPoint(u, v) > u.mod2())
        return min((p - s1).mod(), (p - s2).mod());
    return fabsl(mulCross(u, v) / u.mod());
}
long long qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = (long long)ret * a % MOD;
        }
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return ret;
}
int disptos_int(POINT p, POINT s1, POINT s2) {
    POINT v = p - s1, u = s2 - s1;
    if (mulPoint(u, v) < 0 || mulPoint(u, v) > u.mod2())
        return min((p - s1).mod2(), (p - s2).mod2()) % MOD;
    return ((mulCross(v, u) % MOD) * (mulCross(v, u) % MOD)) % MOD *
           qpow(u.mod2() % MOD, MOD - 2) % MOD;
}

int T, m, n, tx, ty;
int nx(int x) {
    return x == n ? 1 : x + 1;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &tx, &ty);
            a[i].x = tx, a[i].y = ty;
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &tx, &ty);
            b[i].x = tx, b[i].y = ty;
        }
        int j = 1;
        long double mi = INF;
        for (int k = 1; k <= n; k++) {
            if (disptos(b[1], a[k], a[nx(k)]) < mi) {
                mi = disptos(b[1], a[k], a[nx(k)]);
                j = k;
            }
        }
        long double ans = 0;
        int Ta = -1;
        for (int i = 1; i <= m; i++) {
            while (disptos(b[i], a[j], a[nx(j)]) >=
                   disptos(b[i], a[nx(j)], a[(nx(nx(j)))]) - 1e-12)
                j = nx(j);
            if (disptos(b[i], a[j], a[nx(j)]) > ans) {
                ans = disptos(b[i], a[j], a[nx(j)]);
                Ta = disptos_int(b[i], a[j], a[nx(j)]);
            }
        }
        printf("%d\n", Ta);
    }
    return 0;
}
