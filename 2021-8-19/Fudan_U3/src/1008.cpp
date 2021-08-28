#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int n, q, T;

const int NMAX = 2e5 + 10;

int ta[NMAX * 2];
void add(int pos, int x) {
    while (pos < NMAX * 2) {
        ta[pos] += x;
        pos += (-pos & pos);
    }
}
int query(int pos) {
    int ret = 0;
    while (pos) {
        ret += ta[pos];
        pos -= (-pos & pos);
    }
    return ret;
}

struct QUE {
    int x, y, ans;
} que[NMAX];

int nxt[NMAX];
void kmp() {
    nxt[0] = -1;
    for (int i = 1; i < s.size(); i++) {
        int j = nxt[i - 1];
        while (s[j + 1] != s[i] && j >= 0)
            j = nxt[j];
        if (s[j + 1] == s[i]) {
            nxt[i] = j + 1;
        } else
            nxt[i] = -1;
    }
}

struct EDGE {
    int u, v, nx;
} e[NMAX * 2];
int ep = 0, h[NMAX];
void build(int x, int y) {
    e[++ep] = {x, y, h[x]};
    h[x] = ep;
}
int dfn[NMAX], out[NMAX], num;
void dfs(int x) {
    dfn[x] = ++num;
    for (int i = h[x]; i; i = e[i].nx) {
        dfs(e[i].v);
    }
    out[x] = num;
}

vector<int> vec[NMAX];
void dfs2(int x) {
    int tg = n - x;
    for (int i : vec[x]) {
        que[i].ans -= query(out[que[i].y]) - query(dfn[que[i].y] - 1);
    }
    add(dfn[tg], 1);
    for (int i = h[x]; i; i = e[i].nx) {
        dfs2(e[i].v);
    }
    for (int i : vec[x]) {
        que[i].ans += query(out[que[i].y]) - query(dfn[que[i].y] - 1);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < NMAX; i++)
            vec[i].clear();
        memset(ta, 0, sizeof(ta));
        memset(h, 0, sizeof(h));
        ep = 0, num = 0;
        scanf("%d%d", &n, &q);
        cin >> s;

        reverse(s.begin(), s.end());
        kmp();

        for (int i = 0; i < n; i++) {
            build(nxt[i] + 1, i + 1);
        }

        dfs(0);
        reverse(s.begin(), s.end());

        kmp();
        ep = 0;
        memset(h, 0, sizeof(h));

        for (int i = 0; i < n; i++) {
            build(nxt[i] + 1, i + 1);
        }

        for (int i = 0; i < q; i++) {
            scanf("%d%d", &que[i].x, &que[i].y);
            que[i].ans = 0;
            vec[que[i].x].push_back(i);
        }

        dfs2(0);
        for (int i = 0; i < q; i++) {
            printf("%d\n", que[i].ans);
        }
    }
    return 0;
}