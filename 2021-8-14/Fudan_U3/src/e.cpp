#include <bits/stdc++.h>
#define fors(i)         \
    for (auto i : e[x]) \
        if (i != p)
using namespace std;

const int N = 1e5 + 10;

vector<int> seg[N << 2];
int t[N], red[N], n;

void pushup(int x) {
    int ls = x << 1, rs = x << 1 | 1;
    int lp = 0, rp = 0, lsize = seg[ls].size(), rsize = seg[rs].size();
    while (lp < lsize || rp < rsize) {
        if (lp == lsize) {
            seg[x].push_back(seg[rs][rp++]);
        } else if (rp == rsize) {
            seg[x].push_back(seg[ls][lp++]);
        } else {
            if (seg[ls][lp] < seg[rs][rp]) {
                seg[x].push_back(seg[ls][lp++]);
            } else {
                seg[x].push_back(seg[rs][rp++]);
            }
        }
    }
}

void buildtree(int x, int l, int r) {
    if (l == r) {
        seg[x].push_back(t[red[l]]);
        return;
    }
    int mid = (l + r) >> 1;
    buildtree(x << 1, l, mid);
    buildtree(x << 1 | 1, mid + 1, r);
    pushup(x);
}

int query(int x, int l, int r, int ql, int qr, int aim) {
    if (ql > r || qr < l) {
        return 0;
    }
    if (l >= ql && r <= qr) {
        return seg[x].end() - lower_bound(seg[x].begin(), seg[x].end(), aim);
    }
    int mid = (l + r) >> 1;
    return query(x << 1, l, mid, ql, qr, aim) +
           query(x << 1 | 1, mid + 1, r, ql, qr, aim);
}

int cnt;
vector<int> e[N];
int s[N], dfn[N], h[N], top[N], pa[N];

int size(int x, int p) {
    s[x] = 1;
    fors(i) s[x] += size(i, x);
    return s[x];
}

void dfs(int x, int p, int tt) {
    dfn[x] = ++cnt, pa[x] = p, top[x] = tt, h[x] = h[p] + 1;
    red[dfn[x]] = x;
    int y = 0;
    fors(i) if (s[y] < s[i]) y = i;
    if (y)
        dfs(y, x, tt);
    fors(i) if (i != y) dfs(i, x, i);
}

void build() {
    size(1, 0);
    cnt = 0;
    dfs(1, 0, 1);
}

int findtop(int x, int temp) {
    if (t[1] <= temp)
        return 1;
    int tail = x, head = top[x];
    while (t[head] < temp) {
        if (t[pa[head]] == temp) {
            // cout << "f1";
            return pa[head];
        } else if (t[pa[head]] > temp) {
            // cout << "f2";
            return head;
        } else {
            tail = pa[head], head = top[tail];
            // cout << "f";
        }
    }
    int l = dfn[head], r = dfn[tail];
    // cout << l << " " << r << endl;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (t[red[mid]] <= temp) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return red[l];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int _ = 1; _ < n; ++_) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    t[0] = 1e9 + 100;
    build();
    buildtree(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int x, l, r;
        cin >> x >> l >> r;
        if (t[x] > r || t[x] < l) {
            cout << 0 << '\n';
            continue;
        }
        int tops = findtop(x, r);
        // cout << "top: " << tops << '\n';
        cout << query(1, 1, n, dfn[tops], dfn[tops] + s[tops] - 1, l) << '\n';
        // cout << flush;
    }
    return 0;
}