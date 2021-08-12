#include <algorithm>
#include <cstdio>
using namespace std;
int n, ans;
int dp[3000][2];
int main() {
    scanf("%d", &n);
    dp[1][0] = 0, dp[1][1] = 0;
    dp[2][0] = 1;
    dp[2][1] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i][0] = dp[(i + 1) / 2][0] + 1;
        dp[i][1] = max(dp[i / 2][1] + 2, dp[i - i / 2][1] + 2);
    }
    printf("%d ", dp[n][1]);
    for (int i = 2; i < n; i++) {
        ans = 1 + max(dp[i - 1][0], dp[n - i + 1][1]);
        ans = min(ans, dp[n][1]);
        printf("%d ", ans);
    }
    printf("%d", max(1, 1 + dp[n - 1][0]));
    return 0;
}