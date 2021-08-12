#include <cstdio>
int n, ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (n - i - j > j)
                ans++;
            if (2 * n - i - j > j && 2 * n - i - j <= n)
                ans++;
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (n - i - j > j)
                printf("%d %d %d\n", i, j, n - i - j);
            if (2 * n - i - j > j && 2 * n - i - j <= n)
                printf("%d %d %d\n", i, j, 2 * n - i - j);
        }
    }
    return 0;
}