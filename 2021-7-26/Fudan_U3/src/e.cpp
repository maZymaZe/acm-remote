#include <cstdio>
const int NMAX = (2e5 + 10) * 31;
int ch[NMAX][2], sum[NMAX];
bool tag[NMAX];
int cnt = 1, root = 1, n, ll[800002], rr[800002];
struct EDGE {
    /* data */
    int u, v, w, nx;
} e[800002];
int h[NMAX], ep = 0;
void add(int a, int b, int c) {
    e[++ep] = {a, b, c, h[a]};
    h[a] = ep;
    e[++ep] = {b, a, c, h[b]};
    h[b] = ep;
}
void work(int& p, int l, int r, int x, int y, int v) {
    int len = r - l;
    int nl = l ^ (v & ~(len - 1));
    int nr = nl + len;
    if (nl >= x && nr <= y)
        return;
    if (!p)
        p = ++cnt;
    if (nl >= y || nr <= x) {
        tag[p] = 1;
        sum[p] = len;
        return;
    }
    int mid = (l + r) / 2;
    work(ch[p][0], l, mid, x, y, v);
    work(ch[p][1], mid, r, x, y, v);
    sum[p] = tag[p] ? len : sum[ch[p][0]] + sum[ch[p][1]];
}
void dfs(int rt, int fa, int w) {
    work(root, 0, 1 << 30, ll[rt], rr[rt] + 1, w);
    for (int i = h[rt]; i; i = e[i].nx) {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v, rt, w ^ e[i].w);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ll[i], &rr[i]);
    }
    for (int i = 1; i < n; i++) {
        int t1, t2, t3;
        scanf("%d%d%d", &t1, &t2, &t3);
        t1--, t2--;
        add(t1, t2, t3);
    }
    dfs(0, -1, 0);
    printf("%d\n", (1 << 30) - sum[1]);
    return 0;
}
