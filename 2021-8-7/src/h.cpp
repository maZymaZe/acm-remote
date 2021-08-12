#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
const int NMAX = 1e6 + 10;
long long ans, cnt[NMAX], n, t;

int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &t);
        cnt[t]++;
    }
    for (int i = 1; i < NMAX; i++) {
        for (int j = 1; j * i < NMAX; j += 1) {
            ans += cnt[i] * cnt[j] * cnt[i * j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}