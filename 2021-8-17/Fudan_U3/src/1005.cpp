#include <bits/stdc++.h>

using namespace std;
#define N 51
#define M 5
#define pb push_back
#define inf 0x3f3f3f3f

vector<int> d[M];
int dp[N * N * N * N][M];
int n;
int sz[M];
int base[M];
int a[M];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < M; i++)
            d[i].clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            d[b - 1].pb(a);
        }
        for (int i = 0; i < M; i++)
            sort(d[i].begin(), d[i].end());
        // for (int i = 0; i < M; i++)
        // {
        //     printf("i: %d\n", i);
        //     for (int j = 0; j < d[i].size(); j++)
        //         printf("%d ", d[i][j]);
        //     puts("");
        // }
        base[0] = 1;
        for (int i = 1; i < M; i++)
            sz[i - 1] = 1 + d[i - 1].size(), base[i] = base[i - 1] * sz[i - 1];

        for (int mark = 1; mark < base[M - 1]; mark++)
        {
            for (int i = 0; i < M - 1; i++)
                a[i] = (mark / base[i]) % sz[i];
            dp[mark][0] = 0;
            for (int i = 0; i < M - 1; i++)
                if (a[i])
                    dp[mark][0] = max(dp[mark][0], d[i][a[i] - 1] + dp[mark - base[i]][i + 1]);
            for (int c = 1; c < M; c++)
            {
                dp[mark][c] = inf;
                for (int i = 0; i < M - 1; i++)
                    if (a[i])
                        dp[mark][c] = min(dp[mark][c], dp[mark - base[i]][c - 1]);
            }
        }
        printf("%d\n", dp[base[M - 1] - 1][0]);
        // printf("%d\n", cal(d[1].size(), d[2].size(), d[3].size(), d[4].size(), 0));
    }
    return 0;
}