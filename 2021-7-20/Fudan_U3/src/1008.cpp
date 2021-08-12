#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int NMAX = 2008;
int T, mp[NMAX][NMAX], n, m, dp[NMAX][NMAX];
int val[NMAX], pos[NMAX], pv = 0, pp = 0, l[NMAX], r[NMAX];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &mp[i][j]);
            }
        }
        for (int i = 1; i <= m; i++) {
            dp[n][i] = 1;
        }
        for (int i = n - 1; i > 0; i--) {
            for (int j = 1; j <= m; j++) {
                if (mp[i][j] <= mp[i + 1][j]) {
                    dp[i][j] = dp[i + 1][j] + 1;
                } else
                    dp[i][j] = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            pp = 0, pv = 0;
            val[++pv] = dp[i][1];
            pos[++pp] = 1;
            l[1] = 0;
            for (int j = 2; j <= m; j++) {
                while (pv && dp[i][j] < val[pv]) {
                    pv--;
                    pp--;
                }
                if (pv && val[pv] == dp[i][j]) {
                    int t = pp;
                    while (t >= 1) {
                        if (val[t] == dp[i][j])
                            t--;
                        else
                            break;
                    }
                    if (t)
                        l[j] = j - pos[t] - 1;
                    else {
                        l[j] = j - 1;
                    }
                    if (pv - 1 >= 1 && val[pv - 1] == val[pv]) {
                        pos[pp] = j;
                    } else {
                        pos[++pp] = j;
                        val[++pv] = dp[i][j];
                    }
                } else {
                    val[++pv] = dp[i][j];
                    pos[++pp] = j;
                    if (pp == 1)
                        l[j] = j - 1;
                    else
                        l[j] = (j - pos[pp - 1] - 1);
                }
            }

            pp = 0, pv = 0;
            val[++pv] = dp[i][m];
            pos[++pp] = m;
            r[m] = 0;
            for (int j = m - 1; j > 0; j--) {
                while (pv && dp[i][j] < val[pv]) {
                    pv--;
                    pp--;
                }
                if (pv && val[pv] == dp[i][j]) {
                    int t = pp;
                    while (t >= 1) {
                        if (val[t] == dp[i][j])
                            t--;
                        else
                            break;
                    }
                    if (t)
                        r[j] = pos[t] - j - 1;
                    else {
                        r[j] = m - j;
                    }
                    if (pv - 1 >= 1 && val[pv - 1] == val[pv]) {
                        pos[pp] = j;
                    } else {
                        pos[++pp] = j;
                        val[++pv] = dp[i][j];
                    }
                } else {
                    val[++pv] = dp[i][j];
                    pos[++pp] = j;
                    if (pp == 1)
                        r[j] = m - j;
                    else
                        r[j] = (pos[pp - 1] - j - 1);
                }
            }

            for (int j = 1; j <= m; j++) {
                ans = max(ans, (l[j] + r[j] + 1) * dp[i][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}