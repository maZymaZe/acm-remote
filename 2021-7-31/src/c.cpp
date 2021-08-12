#include <cstdio>
const int NMAX = 1e5 + 10;
int T, f[NMAX], n, x, y, c[NMAX];
int ff(int x) {
    if (f[x] == x)
        return 0;
    return f[x] = ff(f[x]);
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            f[i] = i, c[i] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &x, &y);
            f[ff(x)] = ff(y);
        }
        for (int i = 1; i <= n; i++) {
            if (++c[ff(i)] > ans)
                ans = c[ff(i)];
        }
        printf("%d\n", ans);
    }
}