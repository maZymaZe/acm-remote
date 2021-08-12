#include <algorithm>
#include <cmath>
#include <cstdio>

#define R 2000000

long long f[R], n;
int t;

void calc(long long x) {
    long long y = x * x * x, z = x;

    while (true) {
        f[++f[0]] = y;
        if (y > (1000000000000000000LL + z) / (x * x))
            break;

        long long k = x * x * y - z;
        z = y;
        y = k;
    }
}

int search() {
    int l = 1, r = f[0];

    for (int m = (l + r) >> 1; l <= r; m = (l + r) >> 1) {
        if (f[m] > n)
            r = m - 1;
        else
            l = m + 1;
    }

    return r;
}

int main() {
    f[++f[0]] = 1;
    for (int i = 2; i <= 1000000; i++)
        calc(i);
    std::sort(f + 1, f + f[0] + 1);

    for (scanf("%d", &t); t--; printf("%d\n", search()))
        scanf("%lld", &n);
    return 0;
}
