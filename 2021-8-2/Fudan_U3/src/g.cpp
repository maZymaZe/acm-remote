#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#define ll long long
#define pb push_back
#define N 100010
#define mod 1145140019

unordered_map<ll, ll> cache;

ll sz;
vector<ll> pi, pl;

void ini(ll n) {
    sz = n;
    pi.assign(n + 1, 1);
    pi[0] = pi[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (pi[i]) {
            pl.pb(i);
            if (n / i >= i)
                for (ll j = i * i; j <= n; j += i)
                    pi[j] = 0;
        }
    }
    for (size_t i = 1; i < pi.size(); i++)
        pi[i] += pi[i - 1];
}

ll phi(ll x, ll a) {
    if (a == 1 || !x)
        return (x + 1) / 2;
    ll& r = cache[(x << 10) + a];
    if (r)
        return r;
    return r = phi(x, a - 1) - phi(x / pl[a - 1], a - 1);
}

ll get_pi(ll n) {
    if (n < sz)
        return pi[n];
    ll a = get_pi(sqrt(sqrt(n))), b = get_pi(sqrt(n));
    ll c = get_pi(cbrt(n));
    ll r = phi(n, a) + (b + a - 2) * (b - a + 1) / 2;
    for (int i = a + 1; i <= b; i++) {
        ll w = n / pl[i - 1];
        r -= get_pi(w);
        if (i <= c) {
            int upp = get_pi(sqrt(w));
            for (int j = i; j <= upp; j++)
                r += j - 1 - get_pi(w / pl[j - 1]);
        }
    }
    return r;
}

int prime[N];
int tot = 0;
bool vis[N];

void euler() {
    for (int i = 2; i < N; i++) {
        if (!vis[i])
            prime[tot++] = i;
        for (int j = 0; j < tot && i * prime[j] < N; j++) {
            int mid = i * prime[j];
            vis[mid] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

ll sum(ll x) {
    ll q = sqrt(x) + 1;
    ll res = 0;
    for (ll i = 1; x / i >= q; i++)
        res += x / i;

    for (ll i = q - 1; i > 0; i--)
        res += i * (x / i - x / (i + 1));
    return res % mod;
}

void solve(ll n) {
    ll q = sqrt(n) + 1;
    ll res = 0;
    for (ll i = 0; n / prime[i] >= q; i++)
        res = (res + sum(n / prime[i])) % mod;

    for (ll i = q - 1; i > 0; i--)
        res = (res + sum(i) * (get_pi(n / i) - get_pi(n / (i + 1)))) % mod;
    printf("%lld\n", res);
}

int main() {
    ini(N);
    euler();
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n);
        solve(n);
    }
    return 0;
}