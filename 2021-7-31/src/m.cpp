#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int NMAX = 2e5 + 30;
struct PERSON {
    ll money, id;
    bool operator<(const PERSON& x) const { return money < x.money; }
} ht[NMAX];
ll T, n, p, q, ps[NMAX], jm[NMAX], sv[NMAX], ans[NMAX];
bool ck(int x) {
    for (int i = 0; i + x <= n; i++) {
        if ((ps[i + x] - ps[i]) * p >= ht[i + x].money * q * x) {
            return true;
        }
    }
    return false;
}
int main() {
    // freopen("ip.in", "r", stdin);
    // freopen("dm.out", "w", stdout);
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++) {
            ans[i] = 0;
            sv[i] = 0;
            jm[i] = 0;
            scanf("%lld", &ht[i].money);
            ht[i].id = i;
        }
        scanf("%lld%lld", &p, &q);
        sort(ht + 1, ht + 1 + n);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + ht[i].money;
        }
        int l = 1, r = n, mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (ck(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        int pt = n;
        for (int i = n - r + 1; i >= 0; i--) {
            int flag = 0;
            ll lim = ht[i + r - 1].money * r * q - p * (ps[i + r - 1] - ps[i]);
            pt = min(i, pt);
            while (pt > 0 && ht[pt].money * p >= lim) {
                jm[pt]++, jm[pt + 1]--;
                pt--;
                flag = 1;
            }
            if (i > 0) {
                if ((ps[i + r - 1] - ps[i - 1]) * p >=
                    ht[i + r - 1].money * q * r) {
                    flag = 1;
                }
            }
            if (i + r <= n) {
                if ((ps[i + r] - ps[i]) * p >= ht[i + r].money * q * r) {
                    flag = 1;
                }
            }
            if (flag == 1) {
                jm[i + 1]++, jm[i + r]--;
            }
        }
        for (int i = 0; i + r <= n; i++) {
            if ((ps[i + r] - ps[i]) * p >= ht[i + r].money * q * r) {
                jm[i + 1]++;
                jm[i + r + 1]--;
            }
        }

        int c = 0;
        for (int i = 1; i <= n; i++) {
            c += jm[i];
            if (c > 0)
                sv[i] = 1;
            if (i != 1 && sv[i - 1] == 1 && ht[i - 1].money == ht[i].money)
                sv[i] = 1;
        }
        c = 0;
        for (int i = 1; i <= n; i++) {
            if (sv[i] == 0) {
                ++c;
                ans[ht[i].id] = 1;
            }
        }
        printf("%d\n", c);
        int w = 0;
        for (int i = 1; i <= n; i++) {
            if (ans[i]) {
                w++;
                printf("%d", i);
                // if (w != c)
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}