#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int maze[40][40], T, n, m, q, xs, ys, x2, y2, a, b, z, rond;
char mps[40], mode[5003];
unordered_map<int, int> situ;
inline int situhash(int x, int y, int z) {
    return (x << 18) | (y << 13) | z;
}
int main() {
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d%d", &n, &m, &q);
        memset(maze, 0, sizeof(maze));
        for (int i = 1; i <= n; i++) {
            scanf("%s", mps);
            for (int j = 1; j <= m; j++) {
                maze[i][j] = (mps[j - 1] == '.');
            }
        }
        scanf("%s", mode);
        int modelen = strlen(mode);
        printf("Case #%d:\n", TT);
        for (int i = 1; i <= q; i++) {
            scanf("%d%d%d%d%d%d%d", &xs, &ys, &z, &x2, &y2, &a, &b);
            situ.clear();
            rond = 0;
            situ.insert({situhash(xs, ys, (z - 2 + modelen) % modelen + 1), 0});
            if (a == 0 && xs == x2 && ys == y2) {
                printf("0\n");
                continue;
            }
            int x = xs, y = ys, nx, ny, step = 0, flag = 0;
            while (rond == 0) {
                if (mode[z - 1] == 'R') {
                    nx = x, ny = y + 1;
                } else if (mode[z - 1] == 'L') {
                    nx = x, ny = y - 1;
                } else if (mode[z - 1] == 'U') {
                    nx = x - 1, ny = y;
                } else {
                    nx = x + 1, ny = y;
                }
                if (maze[nx][ny]) {
                    x = nx, y = ny;
                }
                step++;
                if (step >= a && step <= b && x == x2 && y == y2) {
                    printf("%d\n", step);
                    flag = 1;
                    break;
                }

                int hs = situhash(x, y, z);
                if (situ.count(hs)) {
                    rond = step - situ[hs];

                } else
                    situ.insert({hs, step});
                z = z % modelen + 1;
            }
            if (flag == 1)
                continue;
            if (step < a) {
                int lf = a - step;
                lf %= rond;
                while (lf--) {
                    if (mode[z - 1] == 'R') {
                        nx = x, ny = y + 1;
                    } else if (mode[z - 1] == 'L') {
                        nx = x, ny = y - 1;
                    } else if (mode[z - 1] == 'U') {
                        nx = x - 1, ny = y;
                    } else {
                        nx = x + 1, ny = y;
                    }
                    if (maze[nx][ny]) {
                        x = nx, y = ny;
                    }
                    z = z % modelen + 1;
                }
                step = a;
            }
            while (true) {
                if (x == x2 && y == y2) {
                    printf("%d\n", step);
                    break;
                }
                if (mode[z - 1] == 'R') {
                    nx = x, ny = y + 1;
                } else if (mode[z - 1] == 'L') {
                    nx = x, ny = y - 1;
                } else if (mode[z - 1] == 'U') {
                    nx = x - 1, ny = y;
                } else {
                    nx = x + 1, ny = y;
                }
                if (maze[nx][ny]) {
                    x = nx, y = ny;
                }
                step++;
                z = z % modelen + 1;
            }
        }
    }
    return 0;
}