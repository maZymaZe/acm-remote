#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int NMAX = 5e5 + 10;
int T, n, tx, ty, dfn, cnt, ans, frnt[NMAX], bck[NMAX], tp[NMAX], h[NMAX];
vector<int> f[NMAX], g[NMAX];
void dfsg(int x, int fa) {
    frnt[x] = ++dfn;
    for (auto i : g[x]) {
        if (i != fa) {
            dfsg(i, x);
        }
    }
    bck[x] = dfn;
}
struct TA {
    int c[NMAX];
    void add(int x, int v) {
        while (x < NMAX) {
            c[x] += v;
            x += (-x & x);
        }
    }
    int query(int x) {
        int ret = 0;
        while (x) {
            ret += c[x];
            x -= (-x & x);
        }
        return ret;
    }
} c, d;
void dfsf(int x, int fa) {
    // tp-upper_bound,min depth
    tp[x] = tp[fa];
    while (c.query(frnt[x]) > 0 || d.query(bck[x]) - d.query(frnt[x] - 1) > 0) {
        c.add(frnt[h[tp[x]]], -1);
        c.add(bck[h[tp[x]]] + 1, 1);
        d.add(frnt[h[tp[x]]], -1);
        tp[x]++;
    }
    h[++cnt] = x;
    c.add(frnt[x], 1);
    c.add(bck[x] + 1, -1);
    d.add(frnt[x], 1);
    ans = max(ans, cnt - tp[x] + 1);
    for (auto i : f[x]) {
        if (i != fa) {
            dfsf(i, x);
        }
    }
    for (int i = tp[fa]; i < tp[x]; i++) {
        c.add(frnt[h[i]], 1);
        c.add(bck[h[i]] + 1, -1);
        d.add(frnt[h[i]], 1);
    }
    cnt--;
    c.add(frnt[x], -1);
    c.add(bck[x] + 1, 1);
    d.add(frnt[x], -1);
}
int main() {
    scanf("%d", &T);
    while (T--) {
        dfn = cnt = ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            f[i].clear(), g[i].clear();
            tp[i] = 0;
            h[i] = 0;
            c.c[i] = d.c[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &tx, &ty);
            f[tx].push_back(ty);
            f[ty].push_back(tx);
        }
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &tx, &ty);
            g[tx].push_back(ty);
            g[ty].push_back(tx);
        }
        dfsg(1, 0);
        tp[0] = 1;
        dfsf(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}