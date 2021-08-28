#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define G 3
#define invG 332748118
#define ll long long
#define vl vector<ll>

int n, m;

ll quick(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void ntt(vl &a, bool flag = false)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n - 1; i++)
    {
        for (int s = n; j ^= s >>= 1, ~j & s;)
            ;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int b = 1; b < n; b <<= 1)
    {
        ll wn = quick(flag ? invG : G, (mod - 1) / (b << 1));
        for (int j = 0; j < n; j += (b << 1))
        {
            ll w = 1;
            for (int k = 0; k < b; k++, w = w * wn % mod)
            {
                int x = a[j + k], y = w * a[j + k + b] % mod;
                a[j + k] = (x + y) % mod, a[j + k + b] = (x - y + mod) % mod;
            }
        }
    }
    if (flag)
    {
        ll inv = quick(n, mod - 2);
        for (int i = 0; i <= n; i++)
            a[i] = a[i] * inv % mod;
    }
}

vl operator+(vl a, vl b)
{
    if (a.size() > b.size())
    {
        for (size_t i = 0; i < b.size(); i++)
            a[i] = (a[i] + b[i]) % mod;
        return a;
    }
    else
    {
        for (size_t i = 0; i < a.size(); i++)
            b[i] = (a[i] + b[i]) % mod;
        return b;
    }
}

vl operator*(vl a, vl b)
{
    int len = a.size() + b.size() - 1;
    if (a.size() * b.size() < 16384)
    {
        vl c(len);

        for (size_t i = 0; i < a.size(); i++)
            for (size_t j = 0; j < b.size(); j++)
                c[i + j] = (c[i + j] + a[i] * b[j]) % mod;

        c.resize(min(len, m + 1));
        return c;
    }

    int n = 1;
    while (n < a.size() + b.size() - 1)
        n <<= 1;

    a.resize(n);
    b.resize(n);
    ntt(a);
    ntt(b);

    vl c(n);
    for (int i = 0; i < n; i++)
        c[i] = a[i] * b[i] % mod;

    ntt(c, true);
    c.resize(min(len, m + 1));

    return c;
}

struct matrix
{
    vl a[2][2];

    matrix(bool I = false)
    {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = vl(1, 0);
        if (I)
            a[0][0] = a[1][1] = vl(1, 1);
    }

    matrix operator*(const matrix &m) const
    {
        matrix r = matrix();
        r.a[0][0] = a[0][0] * m.a[0][0] + a[0][1] * m.a[1][0];
        r.a[0][1] = a[0][0] * m.a[0][1] + a[0][1] * m.a[1][1];
        r.a[1][0] = a[1][0] * m.a[0][0] + a[1][1] * m.a[1][0];
        r.a[1][1] = a[1][0] * m.a[0][1] + a[1][1] * m.a[1][1];

        return r;
    }

    matrix operator^(int b) const
    {
        matrix r = matrix(true);
        matrix a = *this;
        while (b)
        {
            if (b & 1)
                r = r * a;
            a = a * a;
            b >>= 1;
        }
        return r;
    }
} z;

int main()
{
    // clock_t begin = clock();
    // freopen("data.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    z.a[0][0] = {1, 1, 1};
    z.a[0][1] = {0, 1, 2, 1};
    z.a[1][0] = {1};

    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        matrix r = z ^ n;
        for (int i = 1; i <= m; i++)
            printf("%lld ", r.a[0][0][i]);
        puts("");
    }
    // clock_t end = clock();
    // printf("%.6f\n", 1.0 * (end - begin) / CLOCKS_PER_SEC);
    return 0;
}