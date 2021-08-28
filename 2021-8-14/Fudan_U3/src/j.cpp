#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int NMAX = 20;
const int MMAX = 40;
int head[NMAX], nx[MMAX], ver[MMAX], tot = 1;
ll edge[MMAX], maxflow, level[NMAX];
int now[MMAX], n, m, s, t;
queue<int> q;
inline void add(int u, int v, ll w) {
    ver[++tot] = v, edge[tot] = w, nx[tot] = head[u], head[u] = tot;
    ver[++tot] = u, edge[tot] = 0, nx[tot] = head[v], head[v] = tot;
}
bool bfs() {
    for (int i = 1; i <= n; i++)
        level[i] = INF;
    while (!q.empty())
        q.pop();
    q.push(s);
    level[s] = 0;
    now[s] = head[s];
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nx[i]) {
            int y = ver[i];
            if (edge[i] > 0 && level[y] == INF) {
                q.push(y);
                now[y] = head[y];
                level[y] = level[x] + 1;
                if (y == t)
                    return 1;
            }
        }
    }
    return 0;
}
ll dfs(int x, ll flow) {
    if (x == t)
        return flow;
    ll ans = 0, k, i;
    for (i = now[x]; i && flow; i = nx[i]) {
        now[x] = i;
        int y = ver[i];
        if (edge[i] > 0 && level[y] == level[x] + 1) {
            k = dfs(y, min(edge[i], flow));
            if (!k)
                level[y] = INF;
            edge[i] -= k;
            edge[i ^ 1] += k;
            ans += k;
            flow -= k;
        }
    }
    return ans;
}
void dinic() {
    while (bfs())
        maxflow += dfs(s, INF);
}
int main() {
    int T, a[5][5] = {0};
    scanf("%d", &T);
    while (T--) {
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                scanf("%d", &a[i][j]);
        int ans1 = 0;
        for (int i = 1; i <= 4; i++)
            ans1 = max(ans1, a[i][(i + 2) % 4 + 1]);
        int ans2 = 0x3f3f3f3f;
        int l1 = min(a[1][3], a[2][3]), l2 = min(a[3][1], a[4][1]);
        for (int i = 0; i <= l1; i++) {
            for (int j = 0; j <= l2; j++) {
                a[1][3] -= i, a[2][3] -= i;
                a[3][1] -= j, a[4][1] -= j;

                n = 10, m = 18, s = 9, t = 10;
                maxflow = 0;
                tot = 1;
                memset(head, 0, sizeof(head));
                add(9, 1, a[1][2]);
                add(9, 5, a[3][1]);
                add(9, 7, a[4][1]);
                add(9, 4, a[2][4]);
                add(1, 2, INF);
                add(1, 6, INF);
                add(1, 8, INF);
                add(5, 2, INF);
                add(5, 6, INF);
                add(7, 3, INF);
                add(7, 8, INF);
                add(4, 3, INF);
                add(4, 8, INF);
                add(4, 6, INF);
                add(2, 10, a[1][3]);
                add(3, 10, a[2][3]);
                add(6, 10, a[3][4]);
                add(8, 10, a[4][2]);

                dinic();

                ans2 = min(ans2, a[1][2] + a[1][3] + a[2][3] + a[2][4] +
                                     a[3][4] + a[3][1] + a[4][1] + a[4][2] -
                                     (int)maxflow + i + j);

                a[1][3] += i, a[2][3] += i;
                a[3][1] += j, a[4][1] += j;
            }
        }
        printf("%d\n", max(ans2, ans1));
    }
    return 0;
}