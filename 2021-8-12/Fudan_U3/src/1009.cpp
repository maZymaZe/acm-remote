#include <bits/stdc++.h>

using namespace std;
#define N 100010
#define M 40
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod1 1000000007
#define mod2 998244353
#define base 131
#define mp make_pair

char s[N];
char a[M];

int len;

unordered_map<ll, pii> ma;

void pre() {
    ll pow1 = 1;
    ll pow2 = 1;
    for (int i = 1; i <= 30; i++) {
        ll now1 = 0;
        ll now2 = 0;
        for (int j = 1; j < i; j++) {
            now1 = (now1 * base + s[j]) % mod1;
            now2 = (now2 * base + s[j]) % mod2;
        }
        for (int j = i; j <= len; j++) {
            now1 =
                (((now1 - pow1 * s[j - i]) % mod1 + mod1) * base + s[j]) % mod1;
            now2 =
                (((now2 - pow2 * s[j - i]) % mod2 + mod2) * base + s[j]) % mod2;
            ll index = now1 * (mod2 + 1) + now2;
            if (ma.find(index) != ma.end()) {
                int id = ma[index].second;
                if (id <= j - i)
                    ma[index] = mp(ma[index].first + 1, j);
            } else
                ma[index] = mp(1, j);
        }
        pow1 = pow1 * base % mod1;
        pow2 = pow2 * base % mod2;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ma.clear();
        scanf("%s", s + 1);
        len = strlen(s + 1);
        pre();
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%s", a);
            int lena = strlen(a);
            ll now1 = 0;
            ll now2 = 0;
            for (int j = 0; j < lena; j++) {
                now1 = (now1 * base + a[j]) % mod1;
                now2 = (now2 * base + a[j]) % mod2;
            }
            printf("%d\n", ma[now1 * (mod2 + 1) + now2].first);
        }
    }
    return 0;
}