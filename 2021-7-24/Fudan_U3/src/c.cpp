#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int NMAX = 10004, MMAX = 1e6 + 10;
int n, m, k, tx, ty;
vector<int> G1[MMAX], G2[MMAX], G[NMAX];
int mp[NMAX][NMAX], st[NMAX], match[NMAX];
bool dfs(int u) {
    for (auto j : G[u]) {
        if (st[j])
            continue;
        st[j] = 1;
        if (match[j] == -1 || dfs(match[j])) {
            match[j] = u;
            return 1;
        }
    }
    return 0;
}
int cal() {
    memset(match, -1, sizeof(match));
    int res = 0;
    for (int i = 1; i <= n + n; i++) {
        memset(st, 0, sizeof(st));
        if (dfs(i))
            res++;
    }
    return res;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &tx), G1[tx].push_back(i);
    for (int i = 1; i <= n; i++)
        scanf("%d", &tx), G2[tx].push_back(i + n);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &tx, &ty);
        mp[tx][ty] = 1;
    }
    long long ans = 0;
    for (int tg = k; tg > 0; --tg) {
        if (G1[tg].size() == 0 && G2[tg].size() == 0)
            continue;
        for (int i = 1; i <= n + n; i++)
            G[i].clear();
        for (auto i : G1[tg]) {
            for (auto j : G2[tg]) {
                if (mp[i][j - n])
                    G[i].push_back(j), G[j].push_back(i);
            }
        }
        long long mpp = cal() / 2;
        long long maxm = (G1[tg].size() + G2[tg].size() - mpp);
        ans += maxm * tg;
    }
    printf("%lld\n", ans);
    return 0;
}