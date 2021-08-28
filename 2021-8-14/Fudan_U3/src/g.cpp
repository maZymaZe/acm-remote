#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 998244353
#define N 500010

ll quick(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll n, p;

vector<int> child[N];

ll cnt[N], ex[N];
ll pw[N];

void cal(int x) {
    ll sz = child[x].size();
    cnt[x] = 0;
    pw[x] = 1;
    ex[x] = 0;
    if (!sz)
        return;

    ll totpl = 1;
    ll totp = quick(p, sz - 1);
    ll sumEx = 0;
    ll sumCnt = 0;
    for (int i = 0; i < sz; i++) {
        int c = child[x][i];
        cal(c);
        totpl = totpl * pw[c] % mod;
        sumCnt = (sumCnt + cnt[c] * quick(pw[c], mod - 2) + 1) % mod;
        sumEx = (sumEx + ex[c] * quick(pw[c], mod - 2)) % mod;
    }
    pw[x] = totpl * totp % mod * (p + sz * (mod + 1 - p) % mod) % mod;
    cnt[x] = totpl * sumCnt % mod * totp % mod * (mod + 1 - p) % mod;
    ex[x] = (pw[x] * sumEx + cnt[x]) % mod;
}

int main() {
    scanf("%lld%lld", &n, &p);
    for (int i = 2; i <= n; i++) {
        int a;
        scanf("%d", &a);
        child[a].push_back(i);
    }
    cal(1);
    printf("%lld\n", ex[1]);
    return 0;
}