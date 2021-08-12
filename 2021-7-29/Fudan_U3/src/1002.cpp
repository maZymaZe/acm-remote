#include <cstdio>
#include <cstring>
const int NMAX = 2014;
int h[NMAX];
struct EDGE {
    int x, y, nx;
} e[NMAX << 1];
int ep = 0, n, v[NMAX], c[NMAX], ct, a[NMAX][NMAX], nw;
long long x1[NMAX], x2[NMAX], M1 = 1e9 + 7, M2 = 1e9 + 9;
void add(int a, int b) {
    e[++ep] = {a, b, h[a]};
    h[a] = ep;
    e[++ep] = {b, a, h[b]};
    h[b] = ep;
}
void dp(int x) {
    c[v[x]]--;
    if (c[v[x]] == 0)
        ct--;
}
void ap(int x) {
    c[v[x]]++;
    if (c[v[x]] == 1)
        ct++;
}
void dfs(int p, int fa) {
    for (int i = h[p]; i; i = e[i].nx) {
        int q = e[i].y;
        if (q != fa) {
            ap(q);
            a[nw][q] = ct;
            dfs(q, p);
            dp(q);
        }
    }
}
int main() {
    int T, t;
    x1[0] = 1, x2[0] = 1;
    x1[1] = x2[1] = 19560929;
    for (int i = 2; i <= 2000; i++) {
        x1[i] = x1[i - 1] * x1[1] % M1;
        x2[i] = x2[i - 1] * x2[1] % M2;
    }
    scanf("%d", &T);
    while (T--) {
        /* code */
        memset(h, 0, sizeof(h));
        ep = 0;
        ct = 0;

        scanf("%d", &n);
        for (int i = 2; i <= n; i++) {
            scanf("%d", &t);
            add(i, t);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
        }
        for (int i = 1; i <= n; i++) {
            nw = i;
            a[i][i] = 1;
            ap(i);
            dfs(i, -1);
            dp(i);
        }

        for (int i = 1; i <= n; i++) {
            long long tot1 = 0, tot2 = 0;
            for (int j = 1; j <= n; j++) {
                tot1 += x1[j - 1] * a[i][j];
                tot2 += x2[j - 1] * a[i][j];
                tot1 %= M1;
                tot2 %= M2;
            }
            printf("%lld %lld\n", tot1, tot2);
        }
    }
    return 0;
}