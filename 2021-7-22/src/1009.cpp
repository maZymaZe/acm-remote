#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define M 320
#define K 70

int prime[N];
int minprime[N];
bool vis[N];
int tot;
int g[M][M];

void euler()
{
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            prime[tot++] = i;
            minprime[i] = i;
        }
        for (int j = 0; j < tot; j++)
        {
            long long mid = i * prime[j];
            if (mid >= N)
                break;
            vis[mid] = 1;
            minprime[mid] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = 1; i < M; ++i)
    {
        for (int j = 0; j < i; ++j)
            g[i][j] = g[j][i];
        g[i][i] = i;
        for (int j = i + 1; j < M; ++j)
        {
            g[i][j] = g[i][j - i];
        }
    }
}

int cnt[N];
int n;

long long dfs(int x, int a1, int a2, int a3)
{
    if (!x)
    {
        if (a1 <= a2 && a2 <= a3)
        {
            if (a1 == a2 && a2 == a3)
                return 1LL * cnt[a1] * (cnt[a1] - 1) * (cnt[a1] - 2) / 6;
            else if (a2 == a3)
                return 1LL * cnt[a1] * cnt[a2] * (cnt[a2] - 1) / 2;
            else
                return 1LL * cnt[a1] * cnt[a2] * cnt[a3];
        }
        return 0;
    }
    else
    {
        bool flag1 = a1 * prime[x - 1] < N;
        bool flag2 = a2 * prime[x - 1] < N;
        bool flag3 = a3 * prime[x - 1] < N;
        long long res = dfs(x - 1, a1, a2, a3);
        if (flag2 && flag3)
            res += dfs(x - 1, a1, a2 * prime[x - 1], a3 * prime[x - 1]);
        if (flag1 && flag3)
            res += dfs(x - 1, a1 * prime[x - 1], a2, a3 * prime[x - 1]);
        if (flag1 && flag2)
            res += dfs(x - 1, a1 * prime[x - 1], a2 * prime[x - 1], a3);
        return res;
    }
}

int main()
{
    euler();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(cnt, 0, sizeof cnt);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            int aa = 1;
            while (a != 1)
            {
                int temp = minprime[a];
                int cnt = 0;
                while (a % temp == 0)
                    a /= temp, cnt++;
                if (cnt & 1)
                    aa *= temp;
            }
            cnt[aa]++;
        }

        long long ans = dfs(K, 1, 1, 1);
        for (int i = K; i < tot; i++)
        {
            int p = prime[i];
            for (int j = 1; j * p < N; j++)
            {
                int a2 = j * p;
                if (!cnt[a2])
                    continue;
                for (int k = j; k * p < N; k++)
                {
                    int a3 = k * p;
                    if (!cnt[a3])
                        continue;
                    long long now = 0;
                    if (j == k)
                        now = 1LL * cnt[a2] * (cnt[a2] - 1) / 2;
                    else
                        now = 1LL * cnt[a2] * cnt[a3];
                    ans += 1LL * now * cnt[j * k / g[j][k] / g[j][k]];
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}