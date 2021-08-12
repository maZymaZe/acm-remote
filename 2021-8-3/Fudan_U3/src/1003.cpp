#include <cstdio>
long long T, n, k;
int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        printf((n > k + 1) ? "No\n" : "Yes\n");
    }
    return 0;
}