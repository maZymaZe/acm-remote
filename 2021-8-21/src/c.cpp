#include <cstdio>
#include <set>
using namespace std;
const int NMAX = 10002;
int T, n, m, a[NMAX], t[NMAX], u[NMAX], nx[NMAX];
struct PR {
    int del, id;
    bool operator<(const PR& x) const {
        return (del == x.del)
                   ? ((nx[id] == nx[x.id]) ? (id < x.id) : (nx[id] < nx[x.id]))
                   : (del > x.del);
    }
};
set<PR> st;
int main() {
    scanf("%d", &T);
    while (T--) {
        st.clear();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &t[i]);
            u[i] = 1;
            if (t[i] != 1) {
                st.insert({a[i] - (a[i] + 1) / 2, i});
                nx[i] = 1;
            }
        }
        for (int i = 1; i <= m; i++) {
            auto it = st.begin();
            if (it == st.end()) {
                break;
            }
            int nxdel = (a[it->id] + u[it->id] - 1) / u[it->id] -
                        (a[it->id] + u[it->id]) / (u[it->id] + 1);
            u[it->id]++;
            if (nxdel == 0) {
                if (((a[it->id] + u[it->id] - 1) / u[it->id] - 1) == 0 ||
                    ((a[it->id] + u[it->id] - 1) / u[it->id]) == 0)
                    nx[it->id] = 0x3f3f3f3f;
                else
                    nx[it->id] =
                        a[it->id] /
                            ((a[it->id] + u[it->id] - 1) / u[it->id] - 1) -
                        a[it->id] / ((a[it->id] + u[it->id] - 1) / u[it->id]);
            } else
                nx[it->id] = 1;
            int nxid = it->id;

            st.erase(it);
            if (u[nxid] != t[nxid]) {
                st.insert({nxdel, nxid});
            } else {
                int as = 111111;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += (a[i] + u[i] - 1) / u[i];
        printf("%d\n", ans);
    }
    return 0;
}