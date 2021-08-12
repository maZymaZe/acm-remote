#include <cstdio>
long long p;
long long MUL(long long a, long long b) {
    long long tmp = (a * b - (long long)((long double)a / p * b + 1.0e-8) * p);
    return (tmp + p) % p;
}
long long qpow(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = MUL(ret, a);
        a = MUL(a, a);
        b >>= 1;
    }
    return ret;
}
int main() {
    long long T, a;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld", &a, &p);
        if (qpow(a, (p - 1) / 2) == 1) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }
    return 0;
}