#include <bits/stdc++.h>

using namespace std;
#define N 20000020

bool vis[N];
int p[N];
int tot = 0;
int ans1[N / 2];
int ans2[N / 2];

void euler() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            p[tot++] = i;
        }
        for (int j = 0; j < tot; j++) {
            int mid = i * p[j];
            if (mid >= N)
                break;
            vis[mid] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
    ans1[0] = 3;
    ans2[0] = 3;
    ans1[1] = 2;
    ans2[1] = 4;
    ans1[N / 2 - 1] = 10000019 * 2;
    for (int i = N / 2 - 2; i > 1; i--) {
        if (!vis[i])
            ans1[i] = 1;
        else if (!vis[2 * i + 1] || !vis[2 * i - 1])
            ans1[i] = 2;
        else {
            ans1[i] = ans1[i + 1];
            if (ans1[i] <= 2)
                ans1[i] += 2 * i + 1;
        }
    }
    for (int i = N / 2 - 2; i > 1; i--) {
        if (!vis[i + 1])
            ans2[i] = 2 * i + 2;
        else if (!vis[2 * (i + 1) + 1])
            ans2[i] = 2 * i + 3;
        else
            ans2[i] = ans2[i + 1];
    }
    // for (int i = 0; i < 100; i++) {
    //     printf("i: %4d ans: %4d\n", i, ans2[i]);
    // }
}

int main() {
    euler();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n >= 0)
            printf("%d\n", ans1[n]);
        else
            printf("%d\n", ans2[-n]);
    }
    return 0;
}