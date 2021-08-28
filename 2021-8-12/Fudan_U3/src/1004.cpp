#include <bits/stdc++.h>
#define N 100004
#define ll long long
#define mod 998244353

#define ls c << 1
#define rs c << 1 | 1

using namespace std;

ll n, a[N], ans[N << 2], tagx[N << 2];

void pushup(ll c) {
    ans[c] = (ans[ls] + ans[rs]) % mod;
}

void build(ll c, ll l, ll r) {
    tagx[c] = 1;
    ll mid = (l + r) >> 1;
    if (l == r) {
        ans[c] = a[mid];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(c);
}

void spread(ll c, ll l, ll r) {
    if (tagx[c] != 1) {
        ans[ls] = ans[ls] * tagx[c] % mod;
        ans[rs] = ans[rs] * tagx[c] % mod;

        tagx[ls] = tagx[ls] * tagx[c] % mod;
        tagx[rs] = tagx[rs] * tagx[c] % mod;
        tagx[c] = 1;
    }
}

ll query(ll qx, ll qy, ll l, ll r, ll c) {
    // printf("%lld %lld %lld %lld %lld\n", qx, qy, l, r, c);
    if (qx <= l && qy >= r)
        return ans[c];
    ll mid = (l + r) >> 1;
    ll res = 0;
    spread(c, l, r);
    if (qx <= mid)
        res += query(qx, qy, l, mid, ls);
    if (qy > mid)
        res += query(qx, qy, mid + 1, r, rs);
    pushup(c);
    return res % mod;
}

void mul(ll nl, ll nr, ll l, ll r, ll c, ll k) {
    if (l >= nl && r <= nr) {
        ans[c] = ans[c] * k % mod;
        tagx[c] = tagx[c] * k % mod;
        return;
    }
    spread(c, l, r);
    ll mid = (l + r) >> 1;
    if (nl <= mid)
        mul(nl, nr, l, mid, ls, k);
    if (nr > mid)
        mul(nl, nr, mid + 1, r, rs, k);
    pushup(c);
}

ll in[N];
ll node[N * 2];

void add(int pos, int val) {
    while (pos < N * 2) {
        node[pos] = node[pos] + val;
        pos += (-pos & pos);
    }
}

ll TA_query(int pos) {
    ll ret = 0;
    while (pos) {
        ret += node[pos];
        pos -= (-pos & pos);
    }
    return ret;
}

set<int> st;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(node, 0, sizeof node);
        st.clear();
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &in[i]);
        for (int i = 1; i <= n; i++) {
            int j = 30;
            while ((in[i] & (1 << j)) == 0)
                j--;
            a[i] = 1 << j;
            in[i] -= 1 << j;
            // printf("a %2d in %2d\n", a[i], in[i]);
        }
        for (int i = 1; i <= n; i++) {
            add(i, in[i]);
            st.insert(i);
        }
        // for (int i = 1; i <= n; i++)
        //     printf("%d ", node[i]);
        // puts("");

        build(1, 1, n);
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            ll opt, l, r;
            scanf("%lld%lld%lld", &opt, &l, &r);
            if (opt == 1) {
                ll ans = query(l, r, 1, n, 1);
                ans = (ans + TA_query(r) - TA_query(l - 1)) % mod;
                printf("%lld\n", ans);
            }
            if (opt == 2) {
                auto it = st.lower_bound(l);
                for (; it != st.end() && *it <= r; ++it) {
                    /*
                    ll last = TA_query(i - 1);
                    ll now = TA_query(i);
                    ll temp = now - last;
                    */
                    int pos = *it;
                    if (in[pos] == 0) {
                        mul(pos, pos, 1, n, 1, 0);
                        it = st.erase(it);
                        it--;
                    } else
                        add(pos, -(in[pos] & (-in[pos]))),
                            in[pos] -= in[pos] & (-in[pos]);
                }
            }
            if (opt == 3) {
                mul(l, r, 1, n, 1, 2);
            }
        }
    }
    return 0;
}