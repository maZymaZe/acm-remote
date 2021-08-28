#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 22, QL = 120002;
int n, m[6], d[6], h[NMAX];
int dp[NMAX][NMAX][NMAX][NMAX][5][5][2][4][8];
int que[QL + 10], cost[20][QL + 10], lasthit[20][QL + 10];
struct NODE {
    int per, hit, ok;
};
int kill(int i, int bomb, int pos, int ok) {  // left a little life
    int use = 1 << (pos - 1), hh;
    if (ok & 1)
        use |= (1 << 3);
    if (ok & 2)
        use |= (1 << 2);
    if (ok & 4)
        use |= (1 << 1);
    hh = h[i] - bomb * d[5];
    return lasthit[use][hh];
}
int kill2(int i, int bomb, int pos, int ok) {  // not left
    int use = 1 << (pos - 1), hh;
    if (ok & 1)
        use |= (1 << 3);
    if (ok & 2)
        use |= (1 << 2);
    if (ok & 4)
        use |= (1 << 1);
    hh = h[i] - bomb * d[5];
    if (hh <= 0)
        return 0;
    return cost[use][hh];
}
int getdp(int i1,
          int i2,
          int i3,
          int i4,
          int j1,
          int j2,
          int ok3,
          int ok2,
          int ok1) {  // ix pos x stands ix,j means aoe,ok x means pos ok
    if (i4 > n)
        i4 = n + 1;
    if (i1 > n)
        return 0;
    if (dp[i1][i2][i3][i4][j1][j2][ok3][ok2][ok1])
        return dp[i1][i2][i3][i4][j1][j2][ok3][ok2][ok1];
    int& ret = dp[i1][i2][i3][i4][j1][j2][ok3][ok2][ok1];
    ret = 750000;
    int now, i, j, jj1, jj2, del, okk, l;
    NODE x[5];
    for (int l = 0; l <= 15; l++) {
        now = m[5];
        x[1].per = i1, x[2].per = i2, x[3].per = i3, x[4].per = i4;
        x[1].hit = (j1 >= 1) + (j2 >= 1) + 1;
        x[2].hit = (j1 >= 2) + (j2 >= 2) + 1;
        x[3].hit = (j1 >= 3) + (j2 >= 3) + 1;
        x[4].hit = (j1 >= 4) + (j2 >= 4) + 1;
        x[1].ok = ok1 | 8;
        x[2].ok = ok2 | 4;
        x[3].ok = ok3 | 2;
        x[4].ok = 1;
        j = 0;
        del = 0;
        for (i = 1; i <= 4; i++) {
            if ((l & (1 << (i - 1))) == 0 && x[i].hit * d[5] < h[x[i].per])
                x[++j] = x[i];
            if (l & (1 << (i - 1))) {
                if (i == 1)
                    okk = ok1;
                if (i == 2)
                    okk = ok2;
                if (i == 3)
                    okk = ok3;
                if (i == 4)
                    okk = 0;
                del += kill2(x[i].per, x[i].hit, i, okk);
            }
        }
        i = i4 + 1;
        jj1 = jj2 = 0;
        for (j++; j <= 4; j++) {
            x[j].per = i++;
            if (x[j].per > n)
                x[j].per = n + 1;
            x[j].hit = x[j].ok = 0;
        }
        for (int j = 1; j <= 4; j++) {
            if (x[j].hit >= 1)
                jj1++;
            if (x[j].hit >= 2)
                jj2++;
        }
        ret = min(ret, del + now +
                           getdp(x[1].per, x[2].per, x[3].per, x[4].per, jj1,
                                 jj2, x[3].ok & 1, x[2].ok & 3, x[1].ok & 7));

        if (i1 <= n) {
            now = kill(i1, (j1 >= 1) + (j2 >= 1), 1, ok1);
            ret = min(ret, now + getdp(i2, i3, i4, i4 + 1, j1 - (j1 >= 1),
                                       j2 - (j2 >= 1), 1, ok3 | 2, ok2 | 4));
        }
        if (i2 <= n) {
            now = kill(i2, (j1 >= 2) + (j2 >= 2), 2, ok2);
            ret = min(ret, now + getdp(i1, i3, i4, i4 + 1, j1 - (j1 >= 2),
                                       j2 - (j2 >= 2), 1, ok3 | 2, ok1));
        }
        if (i3 <= n) {
            now = kill(i3, (j1 >= 3) + (j2 >= 3), 3, ok3);
            ret = min(ret, now + getdp(i1, i2, i4, i4 + 1, j1 - (j1 >= 3),
                                       j2 - (j2 >= 3), 1, ok2, ok1));
        }
        if (i4 <= n) {
            now = kill(i4, (j1 >= 4) + (j2 >= 4), 4, 0);
            ret = min(ret, now + getdp(i1, i2, i3, i4 + 1, j1 - (j1 >= 4),
                                       j2 - (j2 >= 4), ok3, ok2, ok1));
        }
    }
    return ret;
}
int main() {
    int i, j, k, lst, fs, ls;
    scanf("%d", &n);
    for (i = 1; i <= 4; i++)
        scanf("%d", &d[i]);
    for (i = 1; i <= 5; i++)
        scanf("%d", &m[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    d[5] = 40000;
    for (i = 1; i < QL; i++)
        cost[0][i] = 750000;
    // pre-process cost[i][j],i-position skill we can use, j-left hp
    for (i = 1; i <= 15; i++) {
        for (j = 0; j < 4; j++)
            if (i & (1 << j))
                break;

        lst = i ^ (1 << j);
        for (k = 0; k < QL; k++)
            cost[i][k] = cost[lst][k];
        for (k = d[j + 1]; k < QL; k++)
            cost[i][k] = min(cost[i][k - d[j + 1]] + m[j + 1], cost[i][k]);
        fs = ls = 0;
        lasthit[i][0] = 750000;
        for (k = 0; k < QL; k++) {
            while (fs >= ls && cost[i][k] < cost[i][que[fs]])
                fs--;
            que[++fs] = k;
            while (fs >= ls && que[ls] + d[j + 1] < k + 1)
                ls++;
            lasthit[i][k + 1] = m[j + 1] + cost[i][que[ls]];
        }
    }
    for (int i = 1; i < 16; i++) {
        for (int k = QL - 2; k >= 0; k--) {
            cost[i][k] = min(cost[i][k], cost[i][k + 1]);
        }
    }
    printf("%d\n", getdp(1, 2, 3, 4, 0, 0, 0, 0, 0));
    return 0;
}