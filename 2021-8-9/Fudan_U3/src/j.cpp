#include <bits/stdc++.h>

using namespace std;
#define N 500010
#define pb push_back

int n, s, t;
vector<int> roads[N];
vector<int> st;
int depth[N];
// int qz[N];
// int hz[N];
int sz;
int cnt1[N];
int cnt2[N];
int st1[N][20];
int st2[N][20];

bool dfs(int x, int from) {
    if (x == t) {
        st.pb(x);
        return true;
    }
    int sz = roads[x].size();
    for (int i = 0; i < sz; i++) {
        int to = roads[x][i];
        if (to == from)
            continue;
        if (dfs(to, x)) {
            st.pb(x);
            return true;
        }
    }
    return false;
}

void dfs2(int x, int from1, int from2) {
    depth[x] = 1;
    int sz = roads[x].size();
    for (int i = 0; i < sz; i++) {
        int to = roads[x][i];
        if (to == from1 || to == from2)
            continue;
        dfs2(to, x, 0);
        depth[x] = max(depth[x], depth[to] + 1);
    }
}

int rs1(int p, int q) {
    int d = (1.0 * log(q - p + 1)) / log(2);
    return max(st1[p][d], st1[q - (1 << d) + 1][d]);
}

int rs2(int p, int q) {
    int d = (1.0 * log(q - p + 1)) / log(2);
    return max(st2[p][d], st2[q - (1 << d) + 1][d]);
}

int dp(int l, int r, int step) {
    if (step) {
        int res = depth[st[l]] - rs2(l + 1, r) + sz - r - 1;
        // printf("%d %d %d %d\n", l, r, step, res);
        if (r > l + 1)
            res = max(res, 1 - dp(l + 1, r, step ^ 1));
        // printf("%d %d %d %d\n", l, r, step, res);
        return res;
    } else {
        int res = depth[st[r]] - rs1(l, r - 1) + l;
        // printf("%d %d %d %d\n", l, r, step, res);
        if (r > l + 1)
            res = max(res, 1 - dp(l, r - 1, step ^ 1));
        // printf("%d %d %d %d\n", l, r, step, res);
        return res;
    }
}

int main() {
    scanf("%d%d%d", &n, &s, &t);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        roads[u].pb(v);
        roads[v].pb(u);
    }
    dfs(s, 0);
    sz = st.size();
    // for (int i = 0; i < sz; i++)
    //     printf("%d ", st[i]);
    // puts("");
    reverse(st.begin(), st.end());

    dfs2(s, st[1], 0);
    for (int i = 1; i < sz - 1; i++)
        dfs2(st[i], st[i - 1], st[i + 1]);
    dfs2(t, 0, st[sz - 2]);

    // for (int i = 0; i < sz; i++)
    //     printf("%d ", depth[st[i]]);
    // puts("");

    for (int i = 0; i < sz; i++) {
        cnt1[i] = depth[st[i]] + i;
        cnt2[i] = depth[st[i]] + sz - 1 - i;
        // printf("i %d %d %d\n", i, cnt1[i], cnt2[i]);
    }
    for (int i = 0; i < sz; i++) {
        st1[i][0] = cnt1[i];
        st2[i][0] = cnt2[i];
    }
    for (int j = 1; (1 << j) <= sz; j++) {
        for (int i = 0; i <= sz - (1 << j); i++) {
            st1[i][j] = max(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
            st2[i][j] = max(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
        }
    }

    // qz[0] = depth[s];
    // for (int i = 1; i < sz - 1; i++)
    //     qz[i] = max(i + depth[st[i]], qz[i - 1]);
    // hz[sz - 1] = depth[t];
    // for (int i = sz - 2; i > 0; i--)
    //     hz[i] = max(sz - 1 - i + depth[st[i]], hz[i + 1]);
    // for (int i = 0; i < sz; i++)
    //     printf("%d ", qz[i]);
    // puts("");
    // for (int i = 0; i < sz; i++)
    //     printf("%d ", hz[i]);
    // puts("");
    printf("%d\n", dp(0, sz - 1, 1));
    return 0;
}