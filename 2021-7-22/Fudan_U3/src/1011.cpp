#include <cstring>
#include <iostream>

using namespace std;
#define N 2 << 19
#define mod 998244353
#define ll long long

int n;
ll a[N];
ll b[N];
ll dpa[N][2];
ll dpb[N][2];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%lld", &b[i]);
        int k = 0;
        int nn = 1;
        while (nn < n)
            nn *= 2, k++;
        ll ans = 0;
        ll last = -0x3f3f3f3f3f3f3f3f;
        for (int i = n - 1; i >= 0; i--) {
            dpa[i][0] = dpa[i][1] = a[i];
            dpb[i][0] = dpb[i][1] = b[i];
            for (int j = 0; j < k; j++) {
                if ((1 << j) & i)
                    continue;
                if (((1 << j) | i) >= n)
                    continue;
                dpa[i][0] = max(dpa[i][0], dpa[(1 << j) | i][0]);
                dpb[i][0] = max(dpb[i][0], dpb[(1 << j) | i][0]);
                dpa[i][1] = min(dpa[i][1], dpa[(1 << j) | i][1]);
                dpb[i][1] = min(dpb[i][1], dpb[(1 << j) | i][1]);
            }
            ll now = max(max(dpa[i][0] * dpb[i][0], dpa[i][1] * dpb[i][1]),
                         max(dpa[i][0] * dpb[i][1], dpa[i][1] * dpb[i][0]));
            if (now > last)
                last = now;
            ans += last;
            ans %= mod;
            ans += mod;
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}