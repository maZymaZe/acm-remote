#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int T, n, m, t, p;
const int NMAX = 52, MKMAX = 120;
unordered_map<string, int> mp;
vector<int> x[NMAX], y[NMAX];
string s;
int f[NMAX][MKMAX + 1], dp[502][5], mx[52][1010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            mp[s] = i;
        }
        for (int i = 0; i < n; i++) {
            x[i].clear(), y[i].clear();
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> s;
            int id = mp[s], tx, ty;
            cin >> tx >> ty;
            x[id].push_back(tx), y[id].push_back(ty);
        }
        cin >> t >> p;
        memset(f, 0x3f, sizeof(f));
        memset(mx, 0, sizeof(mx));
        memset(dp, -0x3f, sizeof(dp));
        for (int i = 0; i < n; i++) {
            f[i][0] = 0;
            int len = x[i].size();
            for (int j = 0; j < len; j++) {
                for (int k = 120; k >= x[i][j]; k--) {
                    f[i][k] = min(f[i][k], f[i][k - x[i][j]] + y[i][j]);
                    // if(k-1>=0)f[i][k]=min(f[i][k],f[i][k-1]);
                }
            }
            for (int j = 120; j >= 100; j--) {
                f[i][j] = min(f[i][j], f[i][j + 1]);
            }
            for (int k = 1; k <= 100; k++) {
                if (f[i][k] <= 500) {
                    mx[i][f[i][k]] = max(mx[i][f[i][k]], k);
                }
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = t; j >= 1; --j) {
                for (int k = p; k > 0; --k) {
                    dp[j][k] = dp[j][k - 1];
                }
                dp[j][0] = -1e9;
                for (int k = 0; k <= p; k++) {
                    for (int l = 1; l <= f[i][100] && l <= j; l++) {
                        if (mx[i][l] >= 60) {
                            dp[j][k] = max(dp[j - l][k] + mx[i][l], dp[j][k]);
                        } else if (k) {
                            dp[j][k] =
                                max(dp[j - l][k - 1] + mx[i][l], dp[j][k]);
                        }
                    }
                }
            }
            dp[0][0] = -1e9;
        }
        int ans = -1;
        for (int i = 1; i <= t; i++) {
            for (int j = 0; j <= p; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}