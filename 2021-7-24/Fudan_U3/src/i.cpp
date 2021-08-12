#include <cstdio>
const int NMAX = 6e5 + 10;
int n, q, a[NMAX], op, l, r, x, b[NMAX];
bool f[NMAX][30];
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    while (q--) {
        scanf("%d%d%d%d", &op, &l, &r, &x);
        if (!op) {
            b[l] ^= x, b[r + 1] ^= x;
        } else {
            int k = 0;
            while (l + (1 << k) - 1 <= r) {
                if (x & (1 << k)) {
                    int pos = l + (1 << k);
                    b[l] ^= x, b[pos] ^= x;
                    f[l][k] ^= 1;
                    x += pos - l, l = pos;
                }
                k++;
            }
            while (l <= r) {
                if (l + (1 << k) - 1 <= r) {
                    int pos = l + (1 << k);
                    b[l] ^= x, b[pos] ^= x;
                    f[l][k] ^= 1;
                    x += pos - l, l = pos;
                }
                k--;
            }
        }
    }
    for (int j = 29; j > 0; j--) {
        for (int i = 1; i <= n; i++)
            if (f[i][j]) {
                f[i][j] = 0;
                f[i][j - 1] ^= 1;
                f[i + (1 << (j - 1))][j - 1] ^= 1;
                b[i + (1 << (j - 1))] ^= 1 << (j - 1);
                b[i + (1 << (j))] ^= 1 << (j - 1);
            }
    }
    for (int i = 1; i <= n; i++)
        b[i] ^= b[i - 1];
    for (int i = 1; i <= n; i++)
        a[i] ^= b[i];
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}