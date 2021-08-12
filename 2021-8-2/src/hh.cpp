#include <algorithm>
#include <iostream>
#include <vector>

#define N 100005

#define L(K) ((K) << 1)
#define R(K) ((K) << 1 | 1)

using namespace std;

typedef pair<int, int> range;
typedef pair<int, range> segment;
typedef pair<segment, int> op;

struct seg {
    int v, z;
} t[N << 1];

int p[2][2][N], g[2][2], n, d;
vector<op> q;

void build(int k, int l, int r) {
    t[k] = (seg){0, 0};

    if (l + 1 < r) {
        int m = (l + r) >> 1;
        build(L(k), l, m);
        build(R(k), m, r);
    }
}

void push(int k) {
    if (t[k].z) {
        t[L(k)].v += t[k].z;
        t[L(k)].z += t[k].z;
        t[R(k)].v += t[k].z;
        t[R(k)].z += t[k].z;
    }

    t[k].z = 0;
}

void add(int k, int l, int r, int x, int y, int v) {
    if (x <= l && y >= r) {
        t[k].v += v;
        t[k].z += v;
        return;
    }

    push(k);
    int m = (l + r) >> 1;
    if (x < m)
        add(L(k), l, m, x, y, v);
    if (y > m)
        add(R(k), m, r, x, y, v);
    t[k].v = min(t[L(k)].v, t[R(k)].v);
}

int query(int k, int l, int r) {
    if (l + 1 == r)
        return l;

    push(k);
    int m = (l + r) >> 1;
    return !t[L(k)].v ? query(L(k), l, m) : query(R(k), m, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                cin >> p[j][k][i];

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 2; k++) {
            if (p[1][k][i] - p[0][k][i] >= d) {
                g[0][k] = 0;
                g[1][k] = d;
            } else {
                g[0][k] = (p[0][k][i] % d + d) % d;
                g[1][k] = ((p[1][k][i] - 1) % d + d) % d + 1;
            }
        }

        if (g[0][0] >= g[1][0] && g[0][1] >= g[1][1]) {
            q.push_back({{g[0][0], {g[0][1], d}}, 1});
            q.push_back({{d, {g[0][1], d}}, -1});
            q.push_back({{0, {g[0][1], d}}, 1});
            q.push_back({{g[1][0], {g[0][1], d}}, -1});
            q.push_back({{g[0][0], {0, g[1][1]}}, 1});
            q.push_back({{d, {0, g[1][1]}}, -1});
            q.push_back({{0, {0, g[1][1]}}, 1});
            q.push_back({{g[1][0], {0, g[1][1]}}, -1});
        } else if (g[0][0] >= g[1][0]) {
            q.push_back({{g[0][0], {g[0][1], g[1][1]}}, 1});
            q.push_back({{d, {g[0][1], g[1][1]}}, -1});
            q.push_back({{0, {g[0][1], g[1][1]}}, 1});
            q.push_back({{g[1][0], {g[0][1], g[1][1]}}, -1});
        } else if (g[0][1] >= g[1][1]) {
            q.push_back({{g[0][0], {g[0][1], d}}, 1});
            q.push_back({{g[1][0], {g[0][1], d}}, -1});
            q.push_back({{g[0][0], {0, g[1][1]}}, 1});
            q.push_back({{g[1][0], {0, g[1][1]}}, -1});
        } else {
            q.push_back({{g[0][0], {g[0][1], g[1][1]}}, 1});
            q.push_back({{g[1][0], {g[0][1], g[1][1]}}, -1});
        }
    }

    sort(q.begin(), q.end());
    build(1, 0, d);

    for (int i = 0, j = 0; i < d; i++) {
        for (; j < (int)q.size() && q[j].first.first == i; j++) {
            add(1, 0, d, q[j].first.second.first, q[j].first.second.second,
                q[j].second);
            // cout << "CUR [" << q[j].first.second.first << ", "
            //      << q[j].first.second.second << "] V " << q[j].second <<
            //      '\n';
        }

        if (!t[1].v) {
            cout << "YES\n" << i << ' ' << query(1, 0, d) << '\n';
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}