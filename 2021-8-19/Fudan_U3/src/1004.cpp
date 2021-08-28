#include <bits/stdc++.h>
using namespace std;

#define K 16
#define KK 6
#define M 30030
#define ull unsigned long long
#define ll long long
#define pll pair<ll, ll>

ll p[K] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
ll f[M + 1];
ll x[1 << KK];
ll flag[1 << KK];
ll xx[1 << (K - KK)];
ll flagg[1 << (K - KK)];

ll cal(ll n)
{
    ll p = n / M, q = n % M;
    return p * f[M] + f[q];
}

int main()
{
    for (int i = 0; i < (1 << KK); i++)
    {
        x[i] = 1;
        flag[i] = true;
        for (int j = 0; j < KK; j++)
            if (i & (1 << j))
                x[i] *= p[j], flag[i] = !flag[i];
    }
    for (int i = 0; i < (1 << (K - KK)); i++)
    {
        xx[i] = 1;
        flagg[i] = true;
        for (int j = 0; j < (K - KK); j++)
            if (i & (1 << j))
                xx[i] *= p[j + KK], flagg[i] = !flagg[i];
    }
    for (int i = 0; i <= M; i++)
        for (int j = 0; j < (1 << KK); j++)
            f[i] += (i / x[j]) * (flag[j] ? 1 : -1);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n;
        ll k;
        scanf("%lld%lld", &n, &k);

        ll res = 0;
        if (k <= KK)
        {
            for (int j = 0; j < (1 << k); j++)
                res += (n / x[j]) * (flag[j] ? 1 : -1);
        }
        else
        {
            for (int i = 0; i < (1 << (k - KK)); i++)
                res += cal(n / xx[i]) * (flagg[i] ? 1 : -1);
        }
        printf("%lld\n", res);
        // 136087034284230482
    }
    return 0;
}