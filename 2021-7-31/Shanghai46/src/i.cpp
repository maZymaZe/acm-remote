#include <bits/stdc++.h>

using namespace std;
#define N 1000010
#define pb push_back

int visit[N];
int prime[N];
int tot;
int minprime[N];
set<int> factors[N];
set<int> ans[N];
int timer = 0;

void euler() {
    tot = 0;
    memset(visit, 0, sizeof(visit));
    for (int i = 2; i < N; i++) {
        if (!visit[i]) {
            prime[tot++] = i;
            minprime[i] = i;
        }
        for (int j = 0; j < tot; j++) {
            long long mid = i * prime[j];
            if (mid >= N)
                break;
            visit[mid] = 1;
            minprime[mid] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
    factors[1].insert(1);
    set<int>::iterator it;
    for (int i = 2; i < N; i++) {
        int temp = minprime[i];
        for (it = factors[i / temp].begin(); it != factors[i / temp].end();
             it++) {
            int fac = *it;
            factors[i].insert(fac);
            fac = *it * temp;
            if (fac <= 1010)
                factors[i].insert(fac);
            // timer++;
        }
        // printf("%d :\n", i);
        // for (it = factors[i].begin(); it != factors[i].end(); it++)
        //     printf("%d ", *it);
        // puts("");
    }
    // printf("%d\n", timer);
}

int gcd(int x, int y) {
    return x ? gcd(y % x, x) : y;
}

int n;
int cnt[N];

int main() {
    // freopen("test2.out", "w", stdout);
    euler();
    for (int i = 1; i < N; i++) {
        for (set<int>::iterator it = factors[i].begin(); it != factors[i].end();
             it++) {
            int j = *it;
            if ((i ^ j) < N && (i ^ j) > 0)
                if (gcd(i ^ j, i) == j) {
                    ans[i].insert(i ^ j);
                    timer++;
                }
            j = i / *it;
            if (j <= 1010)
                continue;
            if ((i ^ j) < N && (i ^ j) > 0)
                if (gcd(i ^ j, i) == j) {
                    ans[i].insert(i ^ j);
                    timer++;
                }
        }
        // for (set<int>::iterator it = ans[i].begin(); it != ans[i].end();
        // it++)
        //     printf("%d %d\n", i, *it);
        factors[i].clear();
    }
    // printf("%d\n", timer);

    int T = 0;
    scanf("%d", &T);
    while (T--) {
        memset(cnt, 0, sizeof cnt);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            cnt[a]++;
        }
        long long res = 0;
        for (int i = 1; i < N; i++) {
            for (set<int>::iterator it = ans[i].begin(); it != ans[i].end();
                 it++) {
                res += 1LL * cnt[i] * cnt[*it];
            }
        }
        printf("%lld\n", res / 2);
    }
    return 0;
}