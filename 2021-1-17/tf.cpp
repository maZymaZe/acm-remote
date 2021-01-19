#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
struct pr {
    int x, y;
};
vector<pr> v, d;
int dp[40][40]={0};
void cal() {
    for (int i = 2; i <= 12; i++) {
        int t = v.size();
        for (int j = 0; j < t; j++) {
            int p = v[j].x, q = v[j].y;
            int np = max(p, i), nq = q + i;
            if (np <= 30 && nq <= 30) {
                dp[np][nq] = i;
                dp[nq][np] = i;
                d.push_back({np, nq});
                d.push_back({nq, np});
            }
            np = p + i;
            nq = max(i, q);
            if (np <= 30 && nq <= 30) {
                dp[np][nq] = i;
                dp[nq][np] = i;
                d.push_back({np, nq});
                d.push_back({nq, np});
            }
        }
        v=d;
        d.clear();
    }
}
int main() {
    v.push_back({1, 1});
    dp[1][1] = 1;
    cal();
    int ans = 1;
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 30; j++) {
           printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}