#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
#define ll long long
#define N 2000010

ll quick(ll a, ll b) {
    ll res = 1, temp = a;
    while (b) {
        if (b & 1)
            res = res * temp % mod;
        temp = temp * temp % mod;
        b >>= 1;
    }
    return res;
}

ll fac[N];
ll inv[N];

void pre() {
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = quick(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        inv[i] = (i + 1) * inv[i + 1] % mod;
    // printf("%d\n", inv[1]);
}

ll C(int n, int m) {
    if (m > n || m < 0)
        return 0;
    return fac[n] * quick(fac[n - m] * fac[m] % mod, mod - 2) % mod;
}

int main() {
    pre();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%lld\n", (C(n + m, n) - C(m - 1, n) + mod) % mod);
    }
}