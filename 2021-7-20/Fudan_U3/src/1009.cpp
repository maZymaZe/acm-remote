#include <algorithm>
#include <cstdio>
using namespace std;
int f[100016];
struct EDGE {
    /* data */
    int u, v, w;
    bool operator<(const EDGE& x) { return w < x.w; }
} e[500016];

int fnd(int x) {
    if (f[x] == x)
        return x;
    return f[x] = fnd(f[x]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i <= n; i++)
            f[i] = i;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            e[i] = {u, v, w};
        }

        sort(e, e + m);
        int ct = n;
        int id = 0;
        int d = e[0].w;
        if (ct == k) {
            printf("0\n");
            continue;
        }
        while (1) {
            while (id < m) {
                if (e[id].w == d) {
                    if (fnd(e[id].u) != fnd(e[id].v)) {
                        f[fnd(e[id].u)] = fnd(e[id].v);
                        ct--;
                    }
                    id++;
                } else
                    break;
            }
            if (ct < k) {
                printf("-1\n");
                break;
            } else if (ct == k) {
                printf("%d\n", d);
                break;
            } else if (id == m) {
                printf("-1\n");
                break;
            }
            d = e[id].w;
        }
    }
    return 0;
}