#include <bits/stdc++.h>

using namespace std;
#define N 100010

int b[N];
int c[N];
int d[N];
int e[N];
int cnt[N];
int n;

int main() {
    bool flag = true;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i < n; i++) {
        scanf("%d", &c[i]);
        // cnt[i] = c[i] - c[i - 1];
        d[i] = c[i] - b[i];
        e[i] = b[i] - d[i];
        if (d[i] < 0 || (d[i] & b[i]) != d[i])
            flag = false;
    }
    if (!flag) {
        puts("0");
        return 0;
    }
    int ans = 1;
    for (int j = 0; j < 31; j++) {  // digit
        int res = 0;
        for (int k = 0; k < 2; k++) {  // first is 0 or 1
            int now = k;
            flag = true;
            for (int i = 1; i < n; i++) {  // iterate
                int nxt = ((e[i] >> j) & 1);
                int temp = nxt ^ now;
                if ((temp & now) != ((d[i] >> j) & 1)) {
                    flag = false;
                    break;
                }
                if ((temp | now) != ((b[i] >> j) & 1)) {
                    flag = false;
                    break;
                }
                now = temp;
                // int temp = ((cnt[i] >> j) & 1) - now;
                // int ano_temp = now & temp;
                // if ((ano_temp & now) != d[i])
                // if (now ^ temp != ((e[i] >> j) & 1)) {
                //     flag = false;
                //     break;
                // }
            }
            res += flag;
        }
        ans *= res;
    }
    printf("%d\n", ans);
    return 0;
}