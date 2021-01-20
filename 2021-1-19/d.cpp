#include <cstdio>

#define N 128

const int d[2][8] = {{1, 1, 0, -1, -1, -1, 0, 1}, {0, 1, 1, 1, 0, -1, -1, -1}};

int n, m, l, r, t, c;
char g[2][N][N];

bool judge(int k, int x, int y)
{
    int z = 0;

    for (int i = 0; i < 8; i++)
    {
        int a = x + d[0][i], b = y + d[1][i];
        z += a >= 0 && a < n && b >= 0 && b < m && g[k][a][b] == '*';
    }

    return z >= l && z <= r;
}

int main()
{
    scanf("%d%d%d%d%d", &n, &m, &l, &r, &t);
    for (int i = 0; i < n; i++)
        scanf("%105s", g[0][i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            c += g[0][i][j] == '*';

    for (int k = 1; k < t; k++)
    {
        c = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                c += ((g[k & 1][i][j] = judge((k & 1) ^ 1, i, j) ? '*' : '.') == '*');

        if (!c)
        {
            t = k - 1;
            break;
        }
    }

    for (int i = 0; i < n; i++)
        puts(g[(t & 1) ^ 1][i]);
    return 0;
}