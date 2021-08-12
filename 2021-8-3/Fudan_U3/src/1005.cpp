#include <bits/stdc++.h>

using namespace std;

#define N 310
#define mod 998244353
#define ll long long

ll quick(ll a, ll b)
{
    ll res = 1, temp = a;
    while (b)
    {
        if (b & 1)
            res = res * temp % mod;
        temp = temp * temp % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) { return quick(a, mod - 2); }

ll m1[N][N], m2[N][N], temp[N][N * 2], ans[N][N];

void divide(int l)
{
    for (int i = 0; i < l; i++)
        for (int j = 0; j < l; j++)
            temp[i][j] = m1[i][j], temp[i][j + l] = 0;
    for (int i = 0; i < l; i++)
        temp[i][i + l] = 1;

    for (int i = 0; i < l; i++)
    {
        ll fi = temp[i][i];
        ll invf = inv(fi);
        for (int j = 0; j < 2 * l; j++)
            temp[i][j] = temp[i][j] * invf % mod;

        for (int j = 0; j < l; j++)
        {
            if (j == i)
                continue;
            ll t = temp[j][i];
            for (int k = 0; k < 2 * l; k++)
                temp[j][k] = ((temp[j][k] - temp[i][k] * t) % mod + mod) % mod;
        }
    }
    // for (int i = 0; i < l; i++)
    //     for (int j = 0; j < 2 * l; j++)
    //         printf("%d%c", temp[i][j], (j == 2 * l - 1) ? '\n' : ' ');

    for (int i = 0; i < l; i++)
        for (int j = 0; j < l; j++)
        {
            ans[i][j] = 0;
            for (int k = 0; k < l; k++)
            {
                ans[i][j] += temp[i][k + l] * m2[k][j] % mod;
                ans[i][j] %= mod;
            }
        }
}

int n;
ll w[N][N];
ll sum[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            sum[i] = 0;
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &w[i][j]);
                sum[i] += w[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            ll invs = inv(sum[i]);
            for (int j = 0; j < n; j++)
            {
                m1[i][j] = mod - (invs * w[i][j] % mod);
            }
            m1[i][i] = 1;
            m2[i][i] = invs * w[i][i] % mod;
        }
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < n; j++)
        //         printf("%d%c", m1[i][j], (j == n - 1) ? '\n' : ' ');
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < n; j++)
        //         printf("%d%c", m2[i][j], (j == n - 1) ? '\n' : ' ');
        divide(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                printf("%d%c", ans[i][j], (j == n - 1) ? '\n' : ' ');
    }
    return 0;
}