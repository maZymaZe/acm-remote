#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll P = 4933;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0)
        return x = 1, y = 0, a;
    ll t = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return t;
}

ll INV(ll a, ll n) {
    ll x, y;
    if (exgcd(a, n, x, y) == 1)
        return (x % n + n) % n;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m, k, a, l;
    cin >> n >> m >> k >> a >> l;
    ll fac = 1;
    for (int _ = 1; _ <= k; ++_) {
        ll x, y, z;
        cin >> x >> y >> z;
        if (x)
            fac = fac * (z - y) % P * INV(z, P) % P;
    }
    fac = (fac + a) % P;
    cout << fac << '\n';
    return 0;
}