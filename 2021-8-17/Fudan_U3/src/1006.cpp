#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N 200010

ll tree[N * 2];
void add(int pos, ll v) {
    while (pos < N * 2) {
        tree[pos] += v;
        pos += (-pos & pos);
    }
}

ll query(int pos) {
    ll ret = 0;
    while (pos) {
        ret += tree[pos];
        pos -= (-pos & pos);
    }
    return ret;
}

int n, q;
ll cnt[N];
ll tot = 0;
ll ans = 0;

ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(cnt, 0, sizeof cnt);
        memset(tree, 0, sizeof tree);
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            cnt[x]++;
        }
        tot = n;
        ans = 0;
        for (int i = 1; i < N; i++) {
            add(i, cnt[i]);
            ans += cnt[i] * cnt[i];
        }
        while (q--) {
            int t;
            scanf("%d", &t);
            if (t == 1) {
                ll x, w;
                scanf("%lld%lld", &x, &w);
                add(w, x);
                ans += (cnt[w] + x) * (cnt[w] + x) - cnt[w] * cnt[w];
                cnt[w] += x;
                tot += x;
            }
            if (t == 2) {
                ll fz = (tot * tot - ans) / 2;
                ll fm = tot * (tot - 1);
                // printf("tot %lld ans %lld\n", tot, ans);
                // printf("%lld/%lld\n", fz, fm);
                int l = 1, r = N;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    ll temp = query(mid - 1);
                    ll others = tot - temp - cnt[mid];
                    if (temp <= others)
                        l = mid;
                    else
                        r = mid - 1;
                }
                ll temp = query(l);
                fz += temp * (tot - temp);
                ll g = gcd(fz, fm);
                printf("%lld/%lld\n", fz / g, fm / g);
            }
        }
    }
    return 0;
}