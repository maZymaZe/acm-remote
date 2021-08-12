#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int NMAX = 1e5 + 10;
struct QUE {
    /* data */
    int l, r, a, b, id;
} q[NMAX];
int k, a[NMAX], ans[NMAX];
bool cmp(const QUE& a, const QUE& b) {
    if (a.l / k == b.l / k) {
        if ((a.l / k) & 1) {
            return a.r < b.r;
        }
        return a.r > b.r;
    }
    return a.l / k < b.l / k;
}
int n, m;
const int NODEMAX = 1e6 + 1000, TRIEDEP = 16;
int TRIE[NODEMAX][2], cnt[NODEMAX], tpy[NODEMAX], tot = 0;
inline void add(int x) {
    int p = 0;
    cnt[p]++;
    for (int i = TRIEDEP; i >= 0; i--) {
        if (TRIE[p][((x >> i) & 1)] == 0) {
            TRIE[p][(x >> i) & 1] = ++tot;
        }
        p = TRIE[p][(x >> i) & 1];
        cnt[p]++;
    }
    if (cnt[p] == 1) {
        p = 0;
        tpy[p]++;
        for (int i = TRIEDEP; i >= 0; i--) {
            if (TRIE[p][((x >> i) & 1)] == 0) {
                TRIE[p][(x >> i) & 1] = ++tot;
            }
            p = TRIE[p][(x >> i) & 1];
            tpy[p]++;
        }
    }
}
inline void del(int x) {
    int p = 0;
    cnt[p]--;
    for (int i = TRIEDEP; i >= 0; i--) {
        if (TRIE[p][((x >> i) & 1)] == 0) {
            TRIE[p][(x >> i) & 1] = ++tot;
        }
        p = TRIE[p][(x >> i) & 1];
        cnt[p]--;
    }
    if (cnt[p] == 0) {
        p = 0;
        tpy[p]--;
        for (int i = TRIEDEP; i >= 0; i--) {
            if (TRIE[p][((x >> i) & 1)] == 0) {
                TRIE[p][(x >> i) & 1] = ++tot;
            }
            p = TRIE[p][(x >> i) & 1];
            tpy[p]--;
        }
    }
}
int bita[18], bitb[18];
inline int cal(int a, int b) {
    int ret = 0;
    for (int i = 0; i < 17; i++) {
        bita[i] = (a >> i) & 1;
        bitb[i] = (b >> i) & 1;
    }
    int p = 0;
    for (int i = TRIEDEP; i >= 0; i--) {
        if (bitb[i] == 1) {
            if (TRIE[p][bita[i]]) {
                ret += tpy[TRIE[p][bita[i]]];
            }
        }
        p = TRIE[p][bita[i] ^ bitb[i]];
        if (p == 0)
            break;
    }
    if (p)
        ret += tpy[p];
    return ret;
}
int main() {
    scanf("%d", &n);
    k = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &q[i].l, &q[i].r, &q[i].a, &q[i].b);
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m, cmp);
    int ql = q[1].l, qr = q[1].r;
    for (int i = ql; i <= qr; i++) {
        add(a[i]);
    }
    ans[q[1].id] = cal(q[1].a, q[1].b);
    for (int i = 2; i <= m; i++) {
        while (ql < q[i].l) {
            del(a[ql]), ql++;
        }
        while (ql > q[i].l) {
            ql--, add(a[ql]);
        }
        while (qr > q[i].r) {
            del(a[qr]), qr--;
        }
        while (qr < q[i].r) {
            ++qr, add(a[qr]);
        }
        ans[q[i].id] = cal(q[i].a, q[i].b);
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}