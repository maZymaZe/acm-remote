#include <bits/stdc++.h>
using namespace std;

const int N = 510, Q = 5e5 + 10;

int n, m;
bitset<N * N> b[N];
string s[N];
vector<pair<int, int>> v[N][N];  // target position and id
bool ans[Q];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        if (t == 3 || (t == 1 && y1 == y2) || (t == 2 && x1 == x2)) {
            v[x1][y1].push_back(make_pair((x2 - 1) * m + y2, i));
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (s[i][j - 1] == '1') {
                b[j].reset();
                continue;
            }
            if (j != m && s[i][j] == '0') {
                // inherit from the lower row
                b[j] |= b[j + 1];
            }
            b[j][(i - 1) * m + j] = 1;
            for (auto it : v[i][j]) {
                ans[it.second] = b[j][it.first];
            }
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << (ans[i] ? "yes" : "no") << '\n';
    }
    return 0;
}
