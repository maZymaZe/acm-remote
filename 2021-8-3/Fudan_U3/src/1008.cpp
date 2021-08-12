#include <bits/stdc++.h>

using namespace std;
#define N 1050000
#define mod 998244353
#define ll long long

int n, m;
ll cnt[N];
ll ans1[N];
ll ans2[N];

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

void FWT_and(ll *a)
{
    for (int i = 1; i < n; i <<= 1)
        for (int p = i << 1, j = 0; j < n; j += p)
            for (int k = 0; k < i; ++k)
                a[j + k] = (a[j + k] + a[i + j + k]) % mod;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(cnt, 0, sizeof cnt);
        scanf("%d%d", &n, &m);
        n = 1 << n;
        for (int i = 0; i < m; i++)
        {
            int a;
            scanf("%d", &a);
            cnt[a]++;
        }
        FWT_and(cnt);
        for (int i = 0; i < n; i++)
            ans1[i] = cnt[i];
        FWT_and(cnt);
        for (int i = 0; i < n; i++)
            ans2[i] = cnt[i];
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll temp = ans2[i] * (1 << __builtin_popcount(i)) % mod;
            temp = temp * quick(ans1[i], mod - 2) % mod;
            ans = (ans + temp) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}