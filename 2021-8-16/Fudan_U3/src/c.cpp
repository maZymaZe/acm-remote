#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int NMAX = 3e4 + 10;
vector<int> V[NMAX], G[NMAX], T;
set<int> st;
int n, k, x, cnt[NMAX], match[NMAX], used[NMAX], vis[NMAX], res;
map<pair<int, int>, int> mp;
bool dfs(int y) {
    for (auto t : G[y]) {
        if (!vis[t]) {
            vis[t] = 1;
            if (!match[t] || dfs(match[t])) {
                match[t] = y;
                return true;
            }
        }
    }
    return false;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        V[i].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            V[i][j] = x;
            cnt[x]++;
            mp[{i, x}] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] >= (n - 200)) {
            used[i] = 1;
            T.push_back(i);
        }
    }
    for (auto xx : T) {
        for (int i = 1; i <= n; i++) {
            int flag = 0;
            for (auto j : V[i])
                flag |= (j == xx);
            if (!flag)
                G[xx].push_back(i);
        }
    }

    for (auto xx : T) {
        memset(vis, 0, sizeof(vis));
        if (dfs(xx))
            res++;
    }
    if (res != T.size()) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!match[i])
            st.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            int tt = 0;
            for (auto j : st) {
                if (!mp.count({j, i})) {
                    match[j] = i;
                    tt = j;
                    break;
                }
            }
            if (!tt) {
                printf("-1\n");
                return 0;
            }
            st.erase(tt);
        }
    }
    for (int i = 1; i < n; i++)
        printf("%d ", match[i]);
    printf("%d\n", match[n]);
    return 0;
}