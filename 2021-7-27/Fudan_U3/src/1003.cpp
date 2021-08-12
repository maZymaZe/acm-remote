#include <bits/stdc++.h>

using namespace std;

#define rep(i, x, y) for (auto i = (x); i <= (y); i++)

const int MAXN = 1e7 + 10;
const double Pi = acos(-1.0);
struct Complex {
    double x, y;
    Complex(int _x, int _y) { x = _x, y = _y; }
    Complex(double _x = 0, double _y = 0) { x = _x, y = _y; }
    friend Complex operator+(const Complex &a, const Complex &b) {
        return ((Complex){a.x + b.x, a.y + b.y});
    }
    friend Complex operator-(const Complex &a, const Complex &b) {
        return ((Complex){a.x - b.x, a.y - b.y});
    }
    friend Complex operator*(const Complex &a, const Complex &b) {
        return ((Complex){a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x});
    }
    friend Complex operator*(const Complex &a, const double &val) {
        return ((Complex){a.x * val, a.y * val});
    }
} f[MAXN], g[MAXN], p[MAXN];
int n, m, lim = 1, maxn, rev[MAXN], a[MAXN], b[MAXN];
inline void FFT(Complex *A, int opt) {
    for (int i = 0; i < lim; i++)
        if (i < rev[i]) swap(A[i], A[rev[i]]);
    for (int mid = 1; mid < lim; mid <<= 1) {
        Complex Wn = ((Complex){cos(Pi / (double)mid),
                                (double)opt * sin(Pi / (double)mid)});
        for (int j = 0; j < lim; j += (mid << 1)) {
            Complex W = ((Complex){1, 0});
            for (int k = 0; k < mid; k++, W = W * Wn) {
                Complex x = A[j + k], y = W * A[j + k + mid];
                A[j + k] = x + y;
                A[j + k + mid] = x - y;
            }
        }
    }
}
void init() {
    int l = 0;
    lim = 1;
    while (lim <= n + m) lim <<= 1, l++;
    rep(i, 0, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
}

const int N = 3e5;

char s[N], t[N];
int sum[N], ff[N], ans[N];  // ff[i]: S 第 i 位开始的 m 长子串与 T 的匹配数量

void solve() {
    scanf("%d%d%s%s", &n, &m, s, t);
    n--, m--;

    int num = 0;
    rep(i, 0, n) sum[i] = (i == 0 ? 0 : sum[i - 1]) +
                          (s[i] == '*');  // number of '*' in substrings of S
    rep(i, 0, m) num += t[i] == '*';      // number of '*' in T

    init();

    rep(k, 0, 10) {
        char ch;
        if (k <= 9)
            ch = k + '0';
        else
            ch = '*';
        rep(i, 0, n) f[i].x = s[i] == ch ? 1 : 0;
        rep(i, 0, m) g[m - i].x = t[i] == ch ? 1 : 0;
        FFT(f, 1), FFT(g, 1);
        rep(i, 0, lim - 1) f[i] = f[i] * g[i];
        FFT(f, -1);
        rep(j, m, n + m) ff[j - m] +=
            k == 10 ? -(int)(f[j].x / lim + 0.5) : (int)(f[j].x / lim + 0.5);

        rep(i, 0, lim - 1) f[i].x = f[i].y = g[i].x = g[i].y = 0;
    }

    rep(i, 0, n - m) {
        ff[i] += num + sum[i + m] - (i == 0 ? 0 : sum[i - 1]);
        ans[m + 1 - ff[i]]++;
    }

    rep(i, 0, m + 1) {
        if (i) ans[i] += ans[i - 1];
        printf("%d\n", ans[i]);
    }

    rep(i, 0, n + 1) ff[i] = 0;
    rep(i, 0, m + 1) ans[i] = 0;
}

int main() {
    freopen("c.in", "r", stdin);
     int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
