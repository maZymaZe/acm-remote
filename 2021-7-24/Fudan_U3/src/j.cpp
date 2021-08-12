#include <bitset>
#include <cmath>
#include <cstdio>

#define N 8002

namespace G {
unsigned z1, z2, z3, z4, b, u;

unsigned get() {
    b = ((z1 << 6) ^ z1) >> 13;
    z1 = ((z1 & 4294967294U) << 18) ^ b;
    b = ((z2 << 2) ^ z2) >> 27;
    z2 = ((z2 & 4294967288U) << 2) ^ b;
    b = ((z3 << 13) ^ z3) >> 21;
    z3 = ((z3 & 4294967280U) << 7) ^ b;
    b = ((z4 << 3) ^ z4) >> 12;
    z4 = ((z4 & 4294967168U) << 13) ^ b;
    return (z1 ^ z2 ^ z3 ^ z4);
}

bool read() {
    while (!u)
        u = get();

    bool res = u & 1;
    u >>= 1;
    return res;
}

void srand(int x) {
    z1 = x;
    z2 = (~x) ^ 0x233333333U;
    z3 = x ^ 0x1234598766U;
    z4 = (~x) + 51;
    u = 0;
}
}  // namespace G

using namespace std;

int d[N], n, m;
bool e[N][N];
long long t;

int main() {
    scanf("%d%d", &n, &m);
    G::srand(m);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((e[j][i] = e[i][j] = G::read())) {
                ++d[i];
                ++d[j];
            }
        }
    }

    for (int i = 0; i < n; i++)
        t += (long long)d[i] * (n - 1 - d[i]);

    printf("%lld\n", (long long)n * (n - 1) * (n - 2) / 6 - t / 2);
    return 0;
}
