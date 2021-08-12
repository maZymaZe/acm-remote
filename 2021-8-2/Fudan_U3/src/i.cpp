#include <bits/stdc++.h>

using namespace std;
#define N 1010

int n, m;
int l[N], r[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &l[i], &r[i]);
            if (r[i] < l[i])
                r[i] += n;
        }
        sort(l, l + m);
        sort(r, r + m);
        printf("%d\n", m);
        for (int i = 1; i <= m; i++) {
            printf("%d %d\n", l[i % m], (r[i - 1] - 1) % n + 1);
        }
    }
    return 0;
}
