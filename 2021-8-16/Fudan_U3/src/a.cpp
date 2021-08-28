#include <algorithm>
#include <cstdio>
#include <cstring>
const int NMAX = 1e5 + 10, LMAX = 103;
char s[NMAX][LMAX];
int d[NMAX], ans[NMAX], n;
bool cmp(const int& a, const int& b) {
    return strcmp(s[a], s[b]) < 0;
}
void dfs(int l, int r, int x, int k) {
    if (l == r)
        return;
    int maxx = 0, i, j;
    for (int i = l, j = l; i <= r; i++) {
        maxx = std::max(maxx, d[i]);
        if (i == r || s[d[i]][k] != s[d[i + 1]][k]) {
            ans[maxx]++, ans[x]--;
            dfs(j, i, maxx, k + 1);
            j = i + 1, maxx = 0;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        d[i] = i;
        scanf("%s", s[i]);
    }

    if (n == 1) {
        printf("1\n");
        return 0;
    }
    std::sort(d + 1, d + 1 + n, cmp);
    dfs(1, n, n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i - 1];
        printf("%d\n", ans[i]);
    }
    return 0;
}