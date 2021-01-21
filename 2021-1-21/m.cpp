#include <cstdio>

long long mod = 1e9 + 7;
long long quick_power(long long a, long long n)
{
    long long ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= a;
        a = a * a % mod;
        ans %= mod;
        n >>= 1;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    long long inv2 = quick_power(2, mod - 2);
    while (t--)
    {
        long long i1, i2, j1, j2;
        scanf("%lld%lld%lld%lld", &i1, &i2, &j1, &j2);
        long long a = quick_power(2, i1);
        long long b = quick_power(3, j1);
        
        a = a * (quick_power(2, i2 - i1 + 1) - 1) % mod;
        b = b * (quick_power(3, j2 - j1 + 1) - 1) % mod * inv2 % mod;
        printf("%lld\n", a * b % mod);
    }
    return 0;
   
}