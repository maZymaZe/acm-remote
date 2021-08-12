#include <cstdio>
#include <vector>
using namespace std;
struct TP {
    int l, r, flag;
};
const int NMAX = 1e5 + 10;
vector<TP> lines[NMAX];
int n, d, sq[2][2], tt[2][2];
struct SEG {
    int v, z;
} t[NMAX << 2];
int L(int x) {
    return x << 1;
}
int R(int x) {
    return (x << 1) + 1;
}
void build(int k, int l, int r) {
    t[k] = {0, 0};
    if (l + 1 < r) {
        int m = (l + r) / 2;
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
    int mid = (l + r) / 2;
    if (x < mid)
        add(L(k), l, mid, x, y, v);
    if (y > mid)
        add(R(k), mid, r, x, y, v);
    t[k].v = min(t[L(k)].v, t[R(k)].v);
}
int query(int k, int l, int r) {
    if (l + 1 == r)
        return l;
    push(k);
    int m = (l + r) / 2;
    return (t[L(k)].v == 0) ? query(L(k), l, m) : query(R(k), m, r);
}
int main() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &sq[0][0], &sq[0][1], &sq[1][0], &sq[1][1]);

        for (int j = 0; j < 2; j++) {
            if (sq[1][j] - sq[0][j] >= d) {
                tt[0][j] = 0, tt[1][j] = d;
            } else {
                tt[0][j] = (sq[0][j] % d + d) % d;
                tt[1][j] = ((sq[1][j] - 1) % d + d) % d + 1;
            }
        }
        if (tt[0][0] >= tt[1][0] && tt[0][1] >= tt[1][1]) {
            lines[tt[0][0]].push_back({tt[0][1], d, 1});
            lines[d].push_back({tt[0][1], d, -1});

            lines[0].push_back({tt[0][1], d, 1});
            lines[tt[1][0]].push_back({tt[0][1], d, -1});

            lines[tt[0][0]].push_back({0, tt[1][1], 1});
            lines[d].push_back({0, tt[1][1], -1});

            lines[0].push_back({0, tt[1][1], 1});
            lines[tt[1][0]].push_back({0, tt[1][1], -1});

        } else if (tt[0][0] >= tt[1][0]) {
            lines[tt[0][0]].push_back({tt[0][1], tt[1][1], 1});
            lines[d].push_back({tt[0][1], tt[1][1], -1});

            lines[0].push_back({tt[0][1], tt[1][1], 1});
            lines[tt[1][0]].push_back({tt[0][1], tt[1][1], -1});

        } else if (tt[0][1] >= tt[1][1]) {
            lines[tt[0][0]].push_back({tt[0][1], d, 1});
            lines[tt[1][0]].push_back({tt[0][1], d, -1});

            lines[tt[0][0]].push_back({0, tt[1][1], 1});
            lines[tt[1][0]].push_back({0, tt[1][1], -1});

        } else {
            lines[tt[0][0]].push_back({tt[0][1], tt[1][1], 1});
            lines[tt[1][0]].push_back({tt[0][1], tt[1][1], -1});
        }
    }
    build(1, 0, d);
    for (int i = 0; i < d; i++) {
        int len = lines[i].size();
        for (int j = 0; j < len; j++) {
            add(1, 0, d, lines[i][j].l, lines[i][j].r, lines[i][j].flag);
        }
        if (!t[1].v) {
            printf("YES\n%d %d\n", i, query(1, 0, d));
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}