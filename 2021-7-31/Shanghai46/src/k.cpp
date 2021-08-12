#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int NMAX = 1510;
int T, n, k, dp[NMAX][NMAX], s, v[NMAX], vis[NMAX], t, m, rk[NMAX], ans[NMAX];
bool cmp(const int& x, const int& y) {
    return vis[x - n] > vis[y - n];
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);

        memset(dp, 0x3f, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= k; i++) {
            scanf("%d", &m);
            for (int j = 1; j <= m; j++) {
                scanf("%d", &t);
                dp[i + n][t] = dp[t][i + n] = 1;
            }
        }
        scanf("%d", &s);
        for (int i = 1; i <= s; i++) {
            scanf("%d", &t);
            vis[t] = i;
        }
        for (int i = 1; i <= k; i++) {
            if (vis[i] == 0) {
                vis[i] = k + 1;
            }
        }
        for (int i = 1; i <= k; i++) {
            rk[i] = i + n;
        }
        sort(rk + 1, rk + 1 + k, cmp);
        int maxdis = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n + k; j++) {
                for (int l = j + 1; l <= n + k; l++) {
                    if (j != l) {
                        dp[j][l] = dp[l][j] =
                            min(dp[l][j], dp[l][i] + dp[i][j]);
                    }
                }
            }
        }
        ans[s] = 0;
        for (int i = 1; i <= k; i++) {
            int tmax = -1;
            for (int j = 1; j <= n + k; j++) {
                for (int l = j + 1; l <= n + k; l++) {
                    if (j != l) {
                        dp[j][l] = dp[l][j] =
                            min(dp[l][j], dp[l][rk[i]] + dp[rk[i]][j]);
                        if (dp[l][j] < 0x3f3f3f3f && l <= n && l <= n) {
                            tmax = max(tmax, dp[j][l]);
                        }
                    }
                }
            }
            if (vis[rk[i] - n] <= s) {
                ans[vis[rk[i] - n] - 1] = (tmax > 0) ? tmax / 2 - 1 : 0;
            } else {
                ans[s] = (tmax > 0) ? tmax / 2 - 1 : 0;
            }
        }
        for (int i = 0; i <= s; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
