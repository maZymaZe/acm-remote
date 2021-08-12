#include <cstdio>
#define re register int
#define in inline
#define maxn 2003
#define inf 1000000009

int T;
int n, k, s;
struct node {
    int to, next;
} bian[3000006];
int head[maxn];
int cnt = 0;

int f[maxn];
int line[maxn][maxn];
int ban[maxn];
int ans[maxn];
int as;
int ds[maxn][maxn];
int dis[maxn];

int dui[maxn];
int front, rear;

in int read() {
    int ans = 0;
    char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        ;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        ans = ans * 10 + ch - '0';
    return ans;
}
in void add(int u, int v) {
    cnt++;
    bian[cnt].to = v;
    bian[cnt].next = head[u];
    head[u] = cnt;
}
in void ADD(int u, int v) {
    add(u, v);
    add(v, u);
}
in int min(int a, int b) {
    return a < b ? a : b;
}
in int max(int a, int b) {
    return a > b ? a : b;
}
in void bfs(int x) {
    re i, j;
    for (i = 1; i <= n + k; i++)
        dis[i] = inf;
    dis[x] = 0;
    dui[1] = x, front = 1, rear = 1;
    int u, v;
    while (front <= rear) {
        u = dui[front];
        for (i = head[u]; i; i = bian[i].next) {
            v = bian[i].to;
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                rear++, dui[rear] = v;
            }
        }
        front++;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            ds[i][j] = min(ds[i][j], dis[i] + dis[j]);
        }
    }
}
int main() {
    T = read();
    re i, j, p;
    int r;
    while (T--) {
        n = read(), k = read();
        cnt = 0;
        for (i = 1; i <= n + k; i++)
            head[i] = 0;
        for (i = 1; i <= k; i++)
            f[i] = 0;
        for (i = 1; i <= k; i++) {
            r = read(), line[i][0] = r;
            for (j = 1; j <= line[i][0]; j++)
                line[i][j] = read();
        }
        s = read();
        for (i = 1; i <= n + k; i++) {
            for (j = 1; j <= n + k; j++) {
                if (i == j)
                    ds[i][i] = 0;
                else
                    ds[i][j] = inf;
            }
        }
        for (i = 1; i <= s; i++)
            ban[i] = read(), f[ban[i]] = 1;
        for (i = 1; i <= k; i++) {
            if (!f[i]) {
                for (j = 1; j <= line[i][0]; j++) {
                    ADD(n + i, line[i][j]);
                    ds[n + i][line[i][j]] = ds[line[i][j]][n + i] = 1;
                }
            }
        }

        /*for(p=1;p<=n+k;p++){
         for(i=1;i<=n+k;i++){
          for(j=1;j<=n+k;j++){
           if(i==j) continue;
           ds[i][j]=min(ds[i][j],ds[i][p]+ds[p][j]);
          }
         }
        }*/
        for (i = 1; i <= n; i++)
            bfs(i);
        as = 0;
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                if (ds[i][j] != inf)
                    as = max(as, ds[i][j]);
            }
        }
        ans[s] = as;
        for (p = s; p >= 1; p--) {
            as = 0;
            for (i = 1; i <= line[ban[p]][0]; i++)
                ADD(n + ban[p], line[ban[p]][i]);
            bfs(n + ban[p]);
            for (i = 1; i <= n; i++) {
                for (j = i + 1; j <= n; j++) {
                    if (ds[i][j] != inf)
                        as = max(as, ds[i][j]);
                }
            }
            ans[p - 1] = as;
        }
        for (i = 0; i <= s; i++)
            printf("%d\n", ans[i] / 2 - 1);
    }
    return 0;
}
/*
1
5 4
3 1 3 5
2 1 4
2 2 3
2 2 4
3
1
4
3

*/