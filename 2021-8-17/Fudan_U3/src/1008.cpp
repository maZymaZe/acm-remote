#include <bits/stdc++.h>
using namespace std;
#define N 2000010
#define ll long long
mt19937_64 gen(time(0));

int p[N];
bool vis[N];
int tot = 0;
ll prime[100];
int cnt = 0;
int n;

void euler() {
    for (int i = 2; i < N; i++) {
        if (!vis[i])
            p[tot++] = i;
        for (int j = 0; j < tot; j++) {
            int mid = i * p[j];
            if (mid >= N)
                break;
            vis[mid] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}

void get_prime(ll x) {
    if (x < 2)
        return;
    ll now = x;
    cnt = 0;
    for (int i = 0; 1LL * p[i] * p[i] <= now; i++) {
        int temp = p[i];
        if (now % temp == 0) {
            prime[cnt++] = temp;
            while (now % temp == 0)
                now /= temp;
        }
        if (now == 1)
            break;
    }
    if (now != 1) {
        prime[cnt++] = now;
    }
}

ll a[N];

int main() {
    euler();
    int T;
    scanf("%d", &T);
    srand(time(0));
    while (T--) {
        scanf("%d", &n);
        int ans = (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int t = 0; t < 30; t++) {
            int x = gen() % n, y = gen() % n;
            get_prime(abs(a[x] - a[y]));
            for (int i = 0; i < cnt; i++) {
                int res = 0;
                for (int j = 0; j < n; j++) {
                    if (abs(a[x] - a[j]) % prime[i] == 0)
                        res++;
                }
                ans = max(res, ans);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}