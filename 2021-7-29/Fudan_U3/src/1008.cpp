#include <bits/stdc++.h>

using namespace std;
#define N 100010
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

int n, m, k;

vector<int> dots[N];
vector<pii> segments[2];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
            dots[i].clear();
        segments[0].clear();
        for (int i = 0; i < k; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            dots[x].pb(y);
        }

        for (int i = 1; i <= n; i++) {
            dots[i].push_back(0);
            sort(dots[i].begin(), dots[i].end());
        }
        segments[0].pb(mp(2, m));
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += m + 1;
            segments[i & 1].clear();
            int sz1 = dots[i].size();
            int sz2 = segments[(i - 1) & 1].size();
            // printf("%d %d %d\n", (i - 1) & 1, sz1, sz2);
            int p = 0, q = 0;
            while (p < sz1) {
                int y = dots[i][p];
                if (q == sz2) {
                    segments[i & 1].pb(mp(y, y));
                    ans -= 1;
                    p++;
                    continue;
                }
                int l = segments[(i - 1) & 1][q].first;
                int r = segments[(i - 1) & 1][q].second;
                if (y < l - 1) {
                    segments[i & 1].pb(mp(y, y));
                    ans -= 1;
                    p++;
                } else if (y > r)
                    q++;
                else {
                    segments[i & 1].pb(mp(y, r));
                    ans -= r - y + 1;
                    while (p < sz1 && dots[i][p] <= r)
                        p++;
                    q++;
                }
            }

            vector<pii> temp;
            int sz = segments[i & 1].size();
            for (int j = 0; j < sz;) {
                int l = j, r = j;
                while (r < sz - 1 && segments[i & 1][r].second + 1 >=
                                         segments[i & 1][r + 1].first)
                    r++;
                temp.pb(
                    mp(segments[i & 1][l].first, segments[i & 1][r].second));
                j = r + 1;
            }
            segments[i & 1] = temp;

            // printf("i : %d\n", i);
            // for (int j = 0; j < segments[i & 1].size(); j++)
            //     printf("%d %d\n", segments[i & 1][j].first, segments[i &
            //     1][j].second);
            // puts("");
        }
        printf("%lld\n", ans);
    }
    return 0;
}