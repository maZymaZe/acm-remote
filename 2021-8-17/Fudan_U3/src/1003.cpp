#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 5004;
int T, n, b[NMAX], tx, bestans[NMAX], worstans[NMAX];
struct TEAM {
    int mark, id;
    bool operator<(const TEAM& x) const { return mark < x.mark; }
} team[NMAX];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &team[i].mark);
            team[i].id = i;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
        }
        sort(team + 1, team + 1 + n);
        for (int i = 1; i <= n; i++) {
            int pc = 0, totm = team[i].mark + b[1];
            int l = 2, r = n;
            for (int j = n; j > 0; j--) {
                if (j == i)
                    continue;

                if (team[j].mark + b[r] <= totm) {
                    r--;
                } else {
                    l++;
                    pc++;
                }
            }
            bestans[team[i].id] = pc + 1;
            pc = 0;
            totm = team[i].mark + b[n];
            l = 1, r = n - 1;
            for (int j = 1; j <= n; j++) {
                if (j == i)
                    continue;
                if (team[j].mark + b[l] > totm) {
                    pc++;
                    l++;
                } else {
                    r--;
                }
            }
            worstans[team[i].id] = pc + 1;
        }
        for (int i = 1; i <= n; i++) {
            printf("%d %d\n", bestans[i], worstans[i]);
        }
    }
    return 0;
}