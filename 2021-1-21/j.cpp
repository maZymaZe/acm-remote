#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n, m, p, xx, yy, fail = 0, q;
vector<int> nn, mm;
vector<vector<int>> ans;
int main() {
    scanf("%d%d", &n, &m);
    nn.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nn[i]);
        if (nn[i] != 0) {
            if (xx == 0)
                xx = i;
            else
                fail = 1;
        }
    }
    mm.resize(m + 1);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &mm[i]);
        if (mm[i] != 0) {
            if (yy == 0)
                yy = i;
            else
                fail = 1;
        }
    }
    if (xx == 0 || yy == 0)
        fail = 1;
    if (nn[xx] == mm[yy] && nn[xx] != 1)
        fail = 1;
    if (!(nn[xx] == 1 || mm[yy] == 1))
        fail = 1;
    if (n == 1 && nn[xx] != m) {
        fail = 1;
    }
    if (m == 1 && mm[yy] != n) {
        fail = 1;
    }
    if (fail) {
        printf("No\n");
        return 0;
    }
    ans.resize(n + 1);
    for (int i = 0; i <= n; i++)
        ans[i].resize(m + 1);
    ans[xx][yy] = 0;
    if (1 == mm[yy]) {
        p = 1;
        if (nn[xx] > m) {
            fail = 1;
        }
        for (int i = 1; i <= m; i++) {
            if (i == yy)
                continue;
            if (p == nn[xx]) {
                if (yy + 1 <= m && xx + 1 <= n) {
                    ans[xx + 1][yy + 1] = p;
                    p++;
                    break;
                } else if (yy + 1 <= m && xx - 1 > 0) {
                    ans[xx - 1][yy + 1] = p;
                    p++;
                    break;
                } else if (yy - 1 > 0 && xx - 1 > 0) {
                    ans[xx - 1][yy - 1] = p;
                    p++;
                    break;
                } else if (yy - 1 > 0 && xx + 1 <= n) {
                    ans[xx + 1][yy - 1] = p;
                    p++;
                    break;
                }
            }

            ans[xx][i] = p;
            p++;
        }
    } else if (nn[xx] == 1) {
        p = 1;
        if (mm[yy] > n) {
            fail = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (i == xx)
                continue;
            if (p == mm[yy]) {
                if (yy + 1 <= m && xx + 1 <= n) {
                    ans[xx + 1][yy + 1] = p;
                    p++;
                    break;
                } else if (yy + 1 <= m && xx - 1 > 0) {
                    ans[xx - 1][yy + 1] = p;
                    p++;
                    break;
                } else if (yy - 1 > 0 && xx - 1 > 0) {
                    ans[xx - 1][yy - 1] = p;
                    p++;
                    break;
                } else if (yy - 1 > 0 && xx + 1 <= n) {
                    ans[xx + 1][yy - 1] = p;
                    p++;
                    break;
                }
            }

            ans[i][yy] = p;
            p++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ans[i][j] == 0 && !(i == xx && j == yy)) {
                ans[i][j] = p;
                p++;
            }
        }
    }
    if (fail) {
        printf("No\n");
        return 0;
    } else {
        printf("Yes\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < m; j++) {
                printf("%d ", ans[i][j]);
            }
            printf("%d\n", ans[i][m]);
        }
    }
    return 0;
}