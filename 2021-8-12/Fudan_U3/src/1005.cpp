#include <bits/stdc++.h>

using namespace std;
#define N 1000010
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

char x[N];
int k;
ll cnt[N];
ll C[N];
ll inv[N];
ll f[N];
ll invf[N];

ll CC(int n, int m)
{
    if (m > n || m < 0)
        return 0;
    return f[n] * invf[m] % mod * invf[n - m] % mod;
}

int main()
{
    inv[1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * i % mod;
    invf[N - 1] = quick(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        invf[i] = invf[i + 1] * (i + 1) % mod;

    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &k);
        k--;
        scanf("%s", x + 1);
        int len = strlen(x + 1);
        if (k == 0)
        {
            ll res = 0;
            for (int i = 1; i <= len; i++)
                res = (res * 10 + x[i] - '0') % mod;
            printf("%lld\n", res);
            continue;
        }
        for (int i = 1; i <= len; i++)
            cnt[i] = (cnt[i - 1] + x[i] - '0') % mod;
        C[0] = 1;
        for (int i = 1; i < k; i++)
            C[i] = 2 * C[i - 1] % mod;
        ll temp = 1;
        for (int i = k; i <= len; i++)
        {
            C[i] = (2 * C[i - 1] - temp + mod) % mod;
            temp = temp * (i) % mod * inv[i + 1 - k] % mod;
        }

        ll power = 1;
        ll ans = 0;
        for (int i = len - 1; i >= 1; i--)
        {
            ans = (ans + cnt[i] * power % mod * C[i - 1] % mod) % mod;
            power = 10 * power % mod;
            // printf("%d\n", C[i - 1]);
        }
        // printf("%lld\n", ans);
        power = 1;
        for (int i = len; i >= 1; i--)
        {
            ans = (ans + (x[i] - '0') * (C[i - 1] + CC(i - 1, k)) % mod * power) % mod;
            power = 10 * power % mod;
            // printf("%lld %lld\n", ans, C[i - 1] + CC(i - 1, k));
        }
        printf("%lld\n", ans);
    }
    return 0;
}