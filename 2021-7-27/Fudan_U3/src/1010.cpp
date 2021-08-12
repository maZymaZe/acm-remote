#include <algorithm>
#include <cstdio>
using namespace std;
int T;
const int NMAX = 1005, MMAX = 2e5 + 10, V = 1000;
struct EDGE {
    int x, y, w;
} a[MMAX], b[MMAX];
bool cmp(const EDGE& a, const EDGE& b) {
    return a.w < b.w;
}
int n, m, f[NMAX];
int ff(int x) {
    if (f[x] == x)
        return x;
    return f[x] = ff(f[x]);
}
pair<int, int> fl[2 * V + 10];
void reduce(EDGE* e) {
    sort(e + 1, e + 1 + m, cmp);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    int c = 0;
    for (int i = 1; i <= m; i++) {
        if (ff(e[i].x) != ff(e[i].y)) {
            f[ff(e[i].x)] = ff(e[i].y);
            e[++c] = e[i];
        }
        if (c == n - 1)
            break;
    }
}
pair<int, int> cal(int k) {
    for (int i = 1; i <= n; i++)
        f[i] = i;
    int A = 1, B = 1, sum = 0, cnt = 0;
    while (A < n && B < n) {
        if (a[A].w <= b[B].w + k) {
            if (ff(a[A].x) != ff(a[A].y)) {
                sum += a[A].w;
                f[ff(a[A].x)] = ff(a[A].y);
            }
            A++;
        } else {
            if (ff(b[B].x) != ff(b[B].y)) {
                sum += b[B].w + k;
                cnt++;
                f[ff(b[B].x)] = ff(b[B].y);
            }
            B++;
        }
    }
    while (A < n) {
        if (ff(a[A].x) != ff(a[A].y)) {
            sum += a[A].w;
            f[ff(a[A].x)] = ff(a[A].y);
        }
        A++;
    }
    while (B < n) {
        if (ff(b[B].x) != ff(b[B].y)) {
            sum += b[B].w + k;
            cnt++;
            f[ff(b[B].x)] = ff(b[B].y);
        }
        B++;
    }
    return {sum, cnt};
}
int ask(int k) {
    for (int i = -V; i <= V; i++) {
        if (fl[i + V].second <= k) {
            return fl[i + V].first - k * i;
        }
    }
    return -1;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].w, &b[i].w);
            b[i].x = a[i].x, b[i].y = a[i].y;
        }
        reduce(a), reduce(b);
        for (int i = -V; i <= V; i++) {
            fl[i + V] = cal(i);
        }
        for (int i = 0; i < n; i++) {
            printf("%d\n", ask(i));
        }
    }
    return 0;
}
