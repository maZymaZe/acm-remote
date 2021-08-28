#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 5004;
long long x[N], y[N];
int vis[N];
long long dis[N];
int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        long long ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld%lld", &x[i], &y[i]), vis[i] = 0;

        vis[1] = 1;
        for (int i = 1; i <= n; i++) {
            dis[i] =
                (x[i] - x[1]) * (x[i] - x[1]) + (y[i] - y[1]) * (y[i] - y[1]);
        }
        for (int i = 2; i <= n; i++) {
            long long mi = 2e18 + 10;
            int p = -1;
            for (int j = 1; j <= n; j++) {
                if (!vis[j]) {
                    if (dis[j] < mi)
                        mi = dis[j], p = j;
                }
            }
            ans = max(ans, mi);
            vis[p] = 1;
            for (int j = 1; j <= n; j++) {
                dis[j] = min(dis[j], (x[p] - x[j]) * (x[p] - x[j]) +
                                         (y[p] - y[j]) * (y[p] - y[j]));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}