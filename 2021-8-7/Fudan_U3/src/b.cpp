#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 307;

int n, a[N], b[N], pa[N << 2], sum[N << 2];
bool isleaf[N << 2];

int lowbit(int x) {
    return x & (-x);
}

void add(int x) {
    for (; x <= n; x += lowbit(x))
        b[x] ^= 1;
}

int get(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x))
        ret ^= b[x];
    return ret;
}

int calc(int x, int p) {
    int ls = x << 1, rs = ls | 1;
    if (isleaf[x]) {
        return a[pa[x]] >= a[p] && get(pa[x]) != get(p);
    }
    if (a[pa[ls]] >= a[p]) {
        return calc(ls, p) + sum[x];
    } else {
        return calc(rs, p);
    }
}

void pushup(int x) {
    int ls = x << 1, rs = ls | 1;
    pa[x] = a[pa[ls]] > a[pa[rs]] ? pa[ls] : pa[rs];
    sum[x] = calc(rs, pa[ls]);
}

void build(int x, int l, int r) {
    if (l == r) {
        pa[x] = l;
        isleaf[x] = true;
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    pushup(x);
}

void change(int x, int l, int r, int aim) {
    if (l == r || aim > n)
        return;
    int mid = (l + r) >> 1;
    if (aim <= mid) {
        change(x << 1, l, mid, aim);
    } else {
        change(x << 1 | 1, mid + 1, r, aim);
    }
    pushup(x);
}

int query(int x, int l, int r, int ql, int qr, int& p) {
    if (ql > r || qr < l)
        return 0;
    if (l >= ql && r <= qr) {
        if (a[pa[x]] >= a[p]) {
            int pp = p;
            p = pa[x];
            return calc(x, pp);
        } else {
            return 0;
        }
    }
    int mid = (l + r) >> 1;
    return query(x << 1, l, mid, ql, qr, p) +
           query(x << 1 | 1, mid + 1, r, ql, qr, p);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp)
            add(i), add(i + 1);
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int op, t1, t2;
        cin >> op >> t1 >> t2;
        if (op == 1) {
            a[t1] = t2;
            change(1, 1, n, t1);
        } else if (op == 2) {
            add(t1);
            add(t2 + 1);
            change(1, 1, n, t1);
            change(1, 1, n, t2 + 1);
        } else {
            int p = t1;
            cout << query(1, 1, n, t1 + 1, t2, p) << '\n';
        }
    }
    return 0;
}
