#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 1e5 + 10, MMAX = 3e6 + 10;
int p[MMAX][2], mx[MMAX], a[NMAX];
int T, n, k;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i] ^= a[i - 1];
        }
        int ansl = -1, ansr = n, tot = 1;
        mx[1] = -1;
        p[1][0] = p[1][1] = 0;
        for (int i = 0; i <= n; i++) {
            int x = 1, res = -1;
            for (int j = 29; j >= 0; j--) {
                int w = (a[i] >> j) & 1;
                if (!((k >> j) & 1)) {
                    if (p[x][w ^ 1])
                        res = max(res, mx[p[x][w ^ 1]]);
                    x = p[x][w];
                } else
                    x = p[x][w ^ 1];
                if (!x)
                    break;
            }
            if (x)
                res = max(res, mx[x]);
            if (res >= 0 && i - res < ansr - ansl)
                ansr = i, ansl = res;
            x = 1;
            for (int j = 29; j >= 0; j--) {
                int w = (a[i] >> j) & 1;
                if (!p[x][w]) {
                    p[x][w] = ++tot;
                    mx[tot] = -1;
                    p[tot][0] = p[tot][1] = 0;
                }
                x = p[x][w];
                mx[x] = max(mx[x], i);
            }
        }
        if (ansl >= 0) {
            printf("%d %d\n", ansl + 1, ansr);
        } else
            printf("-1\n");
    }
    return 0;
}
