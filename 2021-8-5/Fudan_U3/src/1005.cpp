#include <bits/stdc++.h>

using namespace std;
#define N 100010

int n, m;
int a[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + m + 1);
        int tempn = n;
        int id = m;
        bool flag = false;
        while (id > 0 && a[id] > tempn / 2) {
            tempn = 2 * a[id] - n - 1 + m - id;
            if (tempn <= 0) {
                flag = true;
                break;
            }
            id--;
        }
        if (flag) {
            puts("YES");
            continue;
        }
        if (id == 0) {
            puts("NO");
            continue;
        }
        if (2 * a[id] >= tempn)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}