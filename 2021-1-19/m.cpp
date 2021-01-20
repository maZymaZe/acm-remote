#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define N 1024

using namespace std;

const int d[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};

typedef pair<int, int> coord;
typedef pair<int, coord> area;
vector<area> s;
int n, m, a;
char g[N][N];
bool v[N][N];

void detect(int a, int b)
{
    bool f = false;
    queue<pair<int, int>> q;
    q.push({a, b});
    v[a][b] = true;
    int t = 1;

    while (!q.empty())
    {
        auto c = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = c.first + d[0][i], y = c.second + d[1][i];

            if (x <= 0 || x > n || y <= 0 || y > n)
                f = true;
            else if (g[x][y] == '.' && !v[x][y])
            {
                q.push({x, y});
                v[x][y] = true;
                ++t;
            }
        }
    }

    if (!f)
        s.push_back({t, {a, b}});
}

void fill(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    g[a][b] = '#';

    while (!q.empty())
    {
        auto c = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = c.first + d[0][i], y = c.second + d[1][i];

            if (x <= 0 || x > n || y <= 0 || y > n)
                continue;
            else if (g[x][y] == '.')
            {
                q.push({x, y});
                g[x][y] = '#';
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &a);
    for (int i = 1; i <= n; i++)
        scanf("%1005s", g[i] + 1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] == '.' && !v[i][j])
                detect(i, j);

    sort(s.begin(), s.end());

    for (size_t i = 0; i < s.size(); i++)
    {
        // if (a < s[i].first)
        //     break;

        // fill(s[i].second.first, s[i].second.second);
        // a -= s[i].first;
        if (s[i].first < a)
            fill(s[i].second.first, s[i].second.second);
    }

    for (int i = 1; i <= n; i++)
        puts(g[i] + 1);
    return 0;
}