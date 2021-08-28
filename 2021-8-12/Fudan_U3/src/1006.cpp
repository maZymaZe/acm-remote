#include <bits/stdc++.h>

using namespace std;

#define N 10000010

int vis[N];
int p[N];
int tot;
int cnt[N];

void euler() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            p[tot++] = i;
            cnt[i] = 1;
        }
        for (int j = 0; j < tot; j++) {
            int mid = i * p[j];
            if (mid >= N)
                break;
            vis[mid] = 1;
            cnt[mid] = 1 + cnt[mid / p[j]];
            if (i % p[j] == 0)
                break;
        }
    }
}

int main() {
    euler();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            res ^= cnt[a];
        }
        // printf("%d\n", res);
        if (res)
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}