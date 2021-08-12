#include <bits/stdc++.h>

using namespace std;

#define N 1000010
#define mod 1000000007
#define ll long long

ll dp[N];
ll inv[N];
ll ans[N];

ll cal(int x) {
    if (dp[x])
        return dp[x];
    if (x & 1)
        dp[x] = cal(x / 2 + 1) * 2 - 1;
    else
        dp[x] = cal(x / 2) + cal(x / 2 + 1) - 1;
    return dp[x];
}

void pre() {
    inv[1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    for (int i = 1; i < N; i++)
        cal(i);
    // for (int i = 1; i < 100; i++)
    //     printf("%d %d\n", i, dp[i]);
    ll cnt = 0;
    for (int i = 1; i < N; i++) {
        cnt += dp[i];
        cnt %= mod;
        ans[i] = (cnt * 2 - i + mod) * inv[i] % mod;
    }
}

int main() {
    pre();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
    return 0;
}