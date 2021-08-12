#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int NMAX = 2020;
int n, m, tx, ty, tz;
vector<pair<int, int>> g[NMAX];
int w[NMAX][NMAX], vis[NMAX];
struct PR {
    int dis, id;
    bool operator<(const PR& x) const { return dis > x.dis; }
};
void dij(int x) {
    w[x][x] = 0;
    memset(vis, 0, sizeof(vis));
    priority_queue<PR> q;
    q.push({0, x});
    while (!q.empty()) {
        PR hd = q.top();
        q.pop();
        if (vis[hd.id])
            continue;
        vis[hd.id] = 1;
        for (auto i : g[hd.id]) {
            if (w[x][i.first] > w[x][hd.id] + i.second) {
                w[x][i.first] = w[x][hd.id] + i.second;
                q.push({w[x][i.first], i.first});
            }
        }
    }
}
vector<int> qq[NMAX];
int ok[NMAX][NMAX];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &tx, &ty, &tz);
        g[tx].push_back({ty, tz});
    }
    memset(w, 0x3f, sizeof(w));
    for (int i = 1; i <= n; i++) {
        dij(i);
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : g[i]) {
            if (j.second == w[i][j.first]) {
                qq[i].push_back(j.first);
                ok[i][j.first] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ok[i][j] || i == j || w[i][j] == 0x3f3f3f3f) {
                ans++;
                continue;
            }
            for (auto it : qq[i]) {
                if (ok[it][j] && w[i][j] == w[i][it] + w[it][j]) {
                    ans++;
                    qq[i].push_back(j);
                    ok[i][j] = 1;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}