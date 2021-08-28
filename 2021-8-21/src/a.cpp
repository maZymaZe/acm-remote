#include <cstdio>
#include <cstring>
int T, n, m, x;
long long c[40], nd[40];
int main() {
    scanf("%d", &T);
    while (T--) {
        memset(c, 0, sizeof(c));
        memset(nd, 0, sizeof(nd));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            for (int j = 0; j <= 31; j++) {
                if (x == (1 << j)) {
                    nd[j]++;
                    break;
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &x);
            for (int j = 0; j <= 31; j++) {
                if (x & (1 << j)) {
                    c[j]++;
                }
            }
        }
        int suc = 1;
        for (int i = 31; i >= 0; i--) {
            if (nd[i] > c[i]) {
                suc = 0;
                break;
            }
            c[i] -= nd[i];
            if (i != 0)
                c[i - 1] += c[i] * 2;
        }
        printf(suc ? "Yes\n" : "No\n");
    }
    return 0;
}