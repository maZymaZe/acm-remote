#include <bits/stdc++.h>
using namespace std;
const int kMax = 100007;

vector<int> nex[kMax];
int n;
bool vis[kMax], is_vis[kMax], ring[kMax];
int fa[kMax];
vector<int> avail;

void dfs(int node) {
    vis[node] = true, is_vis[node] = true;
    for (auto it : nex[node]) {
        if (it == fa[node])
            continue;
        if (!vis[it]) {
            fa[it] = node;
            dfs(it);
        } else if (is_vis[it]) {
            int t = node;
            while (t != it) {
                ring[t] = true;
                t = fa[t];
            }
            ring[it] = true;
        }
    }
    is_vis[node] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int z;
    cin >> z;
    while (z--) {
        memset(fa, 0, sizeof(fa));
        memset(vis, false, sizeof(vis));
        memset(ring, false, sizeof(ring));
        avail.clear();
        cin >> n;
        for (int i = 1; i <= n; ++i)
            nex[i].clear();
        for (int i = 1; i <= n; ++i) {
            int u, v;
            cin >> u >> v;
            nex[u].push_back(v);
            nex[v].push_back(u);
        }
        dfs(1);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (nex[i].size() == 1)
                ++ans;
            if (ring[i] && nex[i].size() == 2) {
                avail.push_back(i);
            }
        }
        if (avail.size())
            ans += 1;
        for (auto it : avail) {
            if (ring[nex[it][0]] && nex[nex[it][0]].size() == 2) {
                ans += 1;
                break;
            }
            if (ring[nex[it][1]] && nex[nex[it][1]].size() == 2) {
                ans += 1;
                break;
            }
        }
        ans = max(ans, 3);
        cout << ans << "\n";
    }
    return 0;
}