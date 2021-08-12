#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 1e5 + 20;
int T, a[NMAX], vis[NMAX], n;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            scanf("%d", &a[i]);
        }
        int flag = 0, cnt = 0, suc = 1;
        long long ta, tb;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                cnt++;
                vis[i] = cnt;
                int nx = a[i];
                while (vis[nx] == 0) {
                    vis[nx] = cnt;
                    nx = a[nx];
                }
                if (vis[nx] == cnt) {
                    long long c = nx, len = 1, p = nx;
                    p = a[p];
                    while (p != nx) {
                        c += p;
                        len++;
                        p = a[p];
                    }

                    if (!flag) {
                        ta = c, tb = len;
                        long long gd = __gcd(ta, tb);
                        ta /= gd;
                        tb /= gd;
                        flag = 1;
                    } else {
                        if (ta * len != tb * c) {
                            suc = 0;
                            break;
                        }
                    }
                }
            }
        }
        if (suc)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}