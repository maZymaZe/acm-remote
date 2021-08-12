#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int NMAX = 6e5 + 10;
int T, n, x[NMAX], y[NMAX], z[NMAX];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        set<pair<int, int>> A, B, C;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
            A.insert({x[i], i});
            B.insert({y[i], i});
            C.insert({z[i], i});
        }
        int cx, cy, cz, ans = 0;
        while (!A.empty()) {
            auto c = *A.begin(), d = *B.begin(), e = *C.begin();
            cx = c.first, cy = d.first, cz = e.first;
            vector<pair<int, int>> K;
            K.push_back(
                {max(x[c.second] - cx, max(y[c.second] - cy, z[c.second] - cz)),
                 c.second});
            c = d;
            K.push_back(
                {max(x[c.second] - cx, max(y[c.second] - cy, z[c.second] - cz)),
                 c.second});
            c = e;
            K.push_back(
                {max(x[c.second] - cx, max(y[c.second] - cy, z[c.second] - cz)),
                 c.second});
            sort(K.begin(), K.end());
            ans = max(ans, K[0].first);
            A.erase({x[K[0].second], K[0].second});
            B.erase({y[K[0].second], K[0].second});
            C.erase({z[K[0].second], K[0].second});
        }
        printf("%d\n", (ans + 1) / 2);
    }
    return 0;
}