#pragma gcc optimize(2)

#include <bits/stdc++.h>

using namespace std;
const int N = 701;
const int M = (N - 2) * (N - 1) / 2 + 1;

int n;
bitset<M> ans[N];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 1; i < N; i++)
    {
        ans[i][0] = 1;
        int o = max(i - (i >> 1), i - 40);
        for (int k = i - 1, temp = i - 1; k >= o; k--, temp += (k << 1) + 1 - i)
        {
            ans[i] |= (ans[k] << temp);
        }
    }
    // printf("%d\n", ans[N - 1].size());
    // cout << "f\n";
    // return 0;

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << 0;
        int cnt = 0;
        for (int i = 1; i <= M; ++i)
        {
            if (ans[n][i])
            {
                cout << ' ' << i;
                cnt++;
            }
        }
        cout << '\n';
        // cout << cnt << '\n';
    }
    return 0;
}