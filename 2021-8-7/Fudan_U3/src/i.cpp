#include <bits/stdc++.h>
long long x, s;
int main() {
    scanf("%lld%lld", &x, &s);
    if ((s & x) != x) {
        puts("0");
    } else {
        long long cnt = 1;
        for (int i = 0; i < 32; i++) {
            if (x & (1 << i))
                cnt *= 2;
        }
        printf("%lld\n", cnt - (s == x));
    }
    return 0;
}