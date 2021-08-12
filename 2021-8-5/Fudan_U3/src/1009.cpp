#include <bits/stdc++.h>

using namespace std;
#define N 110
#define F 1100
#define ll long long

ll s[N];
ll f[N];
char in[10];
ll sum;
int n;
ll dp[F];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        sum = 0;
        scanf("%d", &n);
        // printf("n: %d\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &s[i]);
            scanf("%s", in);
            f[i] = (in[0] - '0') * 100 + (in[2] - '0') * 10 + in[3] - '0';
            sum += f[i];
        }
        while (sum * sum > 10000 * (n + 2))
            sum--;
        ll ans = 0;
        for (int i = 1; i <= sum; i++)
        {
            for (int j = 0; j <= i; j++)
                dp[j] = 0;
            for (int j = 0; j < n; j++)
            {
                if (f[j] == 0 || f[j] > i)
                    continue;
                ll res = s[j] * (10000 + f[j] * f[j] - f[j] * i);
                // if (res < 0)
                //     continue;
                for (int k = i; k >= f[j]; k--)
                    dp[k] = max(dp[k], dp[k - f[j]] + res);
                // printf("j: %d\n", j);
            }
            ans = max(ans, dp[i]);
            // printf("i: %d\n", i);
        }
        for (int i = 0; i < n; i++)
            if (f[i] == 0)
                ans += s[i] * 10000;
        printf("%lld.%04lld00000\n", ans / 10000, ans % 10000);
    }
    return 0;
}