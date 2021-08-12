#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int T, n, k;
const int NMAX = 5400;
string s;
int f[NMAX][NMAX], cnt[NMAX][NMAX], pt[NMAX];
long long ANS[NMAX];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        cin >> s;
        for (int st = 2; st <= n; ++st) {
            int dif = 0;
            for (int i = 1, j = st, len = -1; j <= n; i++, j++, len--) {
                while (i + len < n && j + len < n && dif <= k) {
                    len++;
                    dif += (s[i + len - 1] != s[j + len - 1]);
                }
                f[i][j] = len + (dif <= k);
                dif -= (s[i - 1] != s[j - 1]);
            }
        }

        for (int i = 0; i <= n; i++) {
            pt[i] = n / 2 + 1;
            for (int j = 0; j <= n; j++)
                cnt[i][j] = 0;
        }
        long long ans = 0;
        for (int j = n; j > 1; j--) {
            for (int i = 1; i < j; ++i) {
                while (pt[i] > j - i) {
                    ans -= cnt[i][pt[i]];
                    cnt[i][pt[i] - 1] += cnt[i][pt[i]];
                    pt[i]--;
                }
            }
            for (int i = 1; i < j; ++i) {
                int len = min(f[i][j], j - i);
                cnt[i][len]++;
                ans += len;
            }
            ANS[j] = ans;
            while (pt[j - 1] >= 0) {
                ans -= (long long)cnt[j - 1][pt[j - 1]] * pt[j - 1];
                pt[j - 1]--;
            }
        }
        for (int i = 2; i <= n; i++) {
            printf("%lld\n", ANS[i]);
        }
    }

    return 0;
}