#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 * 31;

int ch[N][2];
int sum[N];
bool tag[N];

int cnt = 1, root = 1;

void work(int& p, int l, int r, int x, int y, int v) {
    int len = r - l;
    int nl = l ^ (v & ~(len - 1));
    int nr = nl + len;
    if (nl >= x && nr <= y) {
        return;
    }
    if (!p) {
        p = ++cnt;
    }
    if (nl >= y || nr <= x) {
        tag[p] = true;
        sum[p] = len;
        return;
    }
    int m = (l + r) / 2;
    work(ch[p][0], l, m, x, y, v);
    work(ch[p][1], m, r, x, y, v);
    sum[p] = tag[p] ? len : sum[ch[p][0]] + sum[ch[p][1]];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
    }

    std::vector<std::vector<std::pair<int, int>>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, x;
        std::cin >> u >> v >> x;
        u--;
        v--;
        e[u].emplace_back(v, x);
        e[v].emplace_back(u, x);
    }

    std::function<void(int, int, int)> dfs = [&](int u, int p, int w) {
        work(root, 0, 1 << 30, l[u], r[u] + 1, w);
        for (auto [v, x] : e[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u, w ^ x);
        }
    };
    dfs(0, -1, 0);

    std::cout << (1 << 30) - sum[1] << "\n";

    return 0;
}