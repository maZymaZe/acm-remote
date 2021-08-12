#include <bits/stdc++.h>
using namespace std;

long long a[10000007];

bool valid[10000007];
int ans[10000007];
int tot = 0;

int main() {
    memset(valid, true, sizeof(valid));
    for (int i = 2; i <= 10000000; ++i) {
        if (valid[i]) {
            ++tot;
            ans[tot] = i;
        }
        for (int j = 1; ((j <= tot) && (i * ans[j] <= 10000000)); ++j) {
            valid[i * ans[j]] = false;
            if (i % ans[j] == 0)
                break;
        }
    }
    a[2] = 0;
    for (int i = 3; i <= 10000000; ++i) {
        if (valid[i])
            a[i] = a[i - 1] + 2 * i;
        else
            a[i] = a[i - 1] + i;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}