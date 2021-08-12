#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
const int NMAX = 1e6 + 10;
vector<int> pos[NMAX];
int T, n, a[NMAX];
int main() {
    scanf("%d", &T);
    while (T--) {
        unordered_set<int> s;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
            pos[a[i]].push_back(i);
        }
        long long ans = 0;
        for (auto x : s) {
            long long ps = 0, res = 0;
            unordered_map<int, int> f1, f2;
            pos[x].push_back(n + 1);
            long long k = 0, minn = 0;
            for (int j = 1; j <= n; j++) {
                if (j > pos[x][k])
                    k++;
                if (a[j] != x && ps == minn) {
                    long long len = pos[x][k] - j - 1;
                    f2[ps + 1]--;
                    f2[ps - len]++;
                    j += len;
                    ps -= len + 1;
                } else if (a[j] == x) {
                    f1[ps] += f2[ps];
                    f2[ps + 1] += f2[ps];
                    f2[ps] = 0;
                    f1[ps]++;
                    res += f1[ps];
                    ps++;
                    ans += res;
                } else {
                    f1[ps]++;
                    ps--;
                    res -= f1[ps];
                    ans += res;
                }
                if (minn > ps)
                    minn = ps;
            }
        }
        printf("%lld\n", ans);
        for (auto i : s)
            pos[i].clear();
    }
    return 0;
}