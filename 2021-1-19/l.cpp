#include <cstring>
#include <deque>
#include <iostream>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 1010

deque<pii> q;
int s[N][N];
int p[N][N];
long long dp[N][N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d%d", &s[i][j], &p[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = 0x3f3f3f3f3f;
    for (int i = 0; i < n; i++)
    {
        q.clear();
        q.pb(mp(s[i][0], p[i][0]));
        for (int j = 1; j < m; j++)
        {
            while (!q.empty() && q.back().second >= p[i][j])
                q.pop_back();
            q.pb(mp(s[i][j], p[i][j]));
        }
        int now = -1;
        for (int j = 0; j < q.size(); j++)
        {
            pii temp = q[j];
            for (int k = now + 1; k <= temp.fi; k++)
                dp[i][k] = temp.se;
            now = temp.fi;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     puts("");
    // }
    double rate = 0x3f3f3f3f3f3f3f3f;
    long long ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i < N; i++)
    {
        long long temp = 0;
        for (int j = 0; j < n; j++)
            temp += dp[j][i];
        if (1. * temp / i < rate)
        {
            ans = temp;
            rate = 1. * temp / i;
        }
        // printf("%lld\n", ans);
    }
    printf("%lld\n", ans);

    return 0;
}