#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define mod 998244353

char s[N];
int nxt[26];
int cnt[26];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long ans = 0;
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < 26; j++)
            nxt[j] = 0, cnt[j] = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 26; j++) {
                if (j == s[i] - 'a') {
                    cnt[j] += nxt[j] + 1;
                    nxt[j] += 2 * i + 3;
                    cnt[j] %= mod;
                    nxt[j] %= mod;
                } else {
                    nxt[j]++;
                    nxt[j] %= mod;
                }
                ans += cnt[j];
                ans %= mod;
            }
            // printf("%lld\n", ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}