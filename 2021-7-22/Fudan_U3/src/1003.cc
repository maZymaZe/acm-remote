#include <bits/stdc++.h>
using namespace std;

const int kMax = 1007;
const int kInf = 0x3f3f3f3f;

int n, m, z;

vector<int> bb[kMax];
int dis[kMax];
int dp[kMax][kMax][2];

struct Re {
    int a, b, c;
};

vector<Re> ve;

int F(int xx, int yy, int turn) {
    if (turn == 0 && (xx == z || yy == z)) {
        if (xx == z && yy == z)
            return 2;
        if (xx == z)
            return 1;
        return 3;
    }
    if (dp[xx][yy][turn])
        return dp[xx][yy][turn];
    int tt = 3;
    if (turn) {
        for (auto it : bb[yy]) {
            if (dis[it] == dis[yy] - 1) {
                if (it != xx || it == z) {
                    tt = min(tt, 4 - F(xx, it, turn ^ 1));
                }
            }
        }
    } else {
        for (auto it : bb[xx]) {
            if (dis[it] == dis[xx] - 1) {
                if (it != yy || it == z) {
                    tt = min(tt, 4 - F(it, yy, turn ^ 1));
                }
            }
        }
    }
    dp[xx][yy][turn] = tt;
    ve.push_back({xx, yy, turn});
    return tt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> n >> m >> x >> y >> z;
        fill(dis, dis + n + 2, kInf);
        for (int i = 1; i <= n; ++i)
            bb[i].clear();
        for (int i = 1; i <= m; ++i) {
            int xx, yy;
            cin >> xx >> yy;
            bb[xx].push_back(yy);
            bb[yy].push_back(xx);
        }
        dis[z] = 0;
        queue<int> q;
        q.push(z);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto it : bb[v]) {
                if (dis[it] > dis[v] + 1) {
                    dis[it] = dis[v] + 1;
                    q.push(it);
                }
            }
        }
        if (dis[x] < dis[y]) {
            cout << 1 << "\n";
            continue;
        }
        if (dis[x] > dis[y]) {
            cout << 3 << "\n";
            continue;
        }
        if (dis[x] == kInf) {
            cout << 2 << "\n";
            continue;
        }
        cout << F(x, y, 0) << "\n";
        for (auto v : ve)
            dp[v.a][v.b][v.c] = 0;
        ve.clear();
    }
    return 0;
}
