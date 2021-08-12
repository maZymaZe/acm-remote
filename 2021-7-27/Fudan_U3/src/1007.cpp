#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
const int NMAX = 1e5 + 20;
vector<int> v;
int n, x, y, T, r[NMAX], g[NMAX], b[NMAX], q, op;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &q);
        v.clear();
        v.push_back(0);
        for (int i = 1; i <= n; i++) {
            scanf("%d%x", &op, &x);
            if (op == 1) {
                r[i] = x >> 16;
                g[i] = (x >> 8) & 0xFF;
                b[i] = x & 0xFF;
                v.push_back(i);
            } else {
                r[i] = r[i - 1] + (x >> 16);
                g[i] = g[i - 1] + ((x >> 8) & 0xFF);
                b[i] = b[i - 1] + (x & 0xFF);
            }
        }
        for (int i = 1; i <= q; i++) {
            scanf("%d%d", &x, &y);
            auto it = lower_bound(v.begin(), v.end(), y);
            if (*it == y) {
                printf("%02X%02X%02X\n", min(0xFF, r[y]), min(0xFF, g[y]),
                       min(0xFF, b[y]));
            } else {
                --it;
                if (x < *it) {
                    x = *it;
                }
                if (x == *it) {
                    printf("%02X%02X%02X\n", min(0xFF, r[y]), min(0xFF, g[y]),
                           min(0xFF, b[y]));
                } else {
                    printf("%02X%02X%02X\n", min(0xFF, r[y] - r[x - 1]),
                           min(0xFF, g[y] - g[x - 1]),
                           min(0xFF, b[y] - b[x - 1]));
                }
            }
        }
    }
    return 0;
}