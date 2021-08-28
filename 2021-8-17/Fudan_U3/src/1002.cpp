#include <bits/stdc++.h>

using namespace std;

#define N 100010

vector<int> a[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        long long k;
        scanf("%d%d%lld", &n, &m, &k);
        for (int i = 0; i < n; i++) {
            a[i].clear();
            for (int j = 0; j < m; j++) {
                int x;
                scanf("%d", &x);
                a[i].push_back(x);
            }
        }
        if (k == 1) {
            int ma = 0;
            for (int j = 0; j < m; j++)
                ma = max(ma, a[0][j]);
            printf("%d\n", ma);
        } else if (k & 1) {
            int mi = 1000000000;
            for (int i = 0; i < n; i++) {
                int ma = 0;
                for (int j = 0; j < m; j++) {
                    ma = max(ma, a[i][j]);
                }
                mi = min(mi, ma);
            }
            printf("%d\n", max(mi, a[0][0]));
        } else {
            int ma = a[0][0];
            for (int j = 0; j < m; j++) {
                int mi = 1000000000;
                for (int i = 0; i < n; i++) {
                    mi = min(mi, a[i][j]);
                }
                ma = max(ma, mi);
            }
            printf("%d\n", ma);
        }
    }
}