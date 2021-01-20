#include <cstdio>
#include <cstring>

#define V 256
#define E 2048

struct edge
{
    int u, v, w, c, x;
} e[E];

struct queue
{
    int q[V + 1], f, t;

    inline void clear() { f = t = 0; }
    inline bool empty() { return f == t; }

    void push(int x)
    {
        q[t++] = x;
        if (t == V)
            t = 0;
    }

    int pop()
    {
        int x = q[f++];
        if (f == V)
            f = 0;
        return x;
    }
} q;

int h[V], d[V], p[V], t, n, m, a, u, v, w;
bool f[V];

inline int min(int a, int b) { return a < b ? a : b; }

inline long long min(long long a, long long b) { return a < b ? a : b; }

inline void adde(int u, int v, int w, int c)
{
    e[t] = (edge){u, v, w, c, h[u]};
    h[u] = t++;
    e[t] = (edge){v, u, -w, 0, h[v]};
    h[v] = t++;
}

bool spfa()
{
    memset(d, 0x3f, sizeof d);
    d[0] = 0;
    q.push(0);
    f[0] = true;

    while (!q.empty())
    {
        int z = q.pop();
        f[z] = false;

        for (int i = h[z]; ~i; i = e[i].x)
        {
            if (e[i].c && d[e[i].v] > d[z] + e[i].w)
            {
                d[e[i].v] = d[z] + e[i].w;
                p[e[i].v] = i;

                if (!f[e[i].v])
                {
                    q.push(e[i].v);
                    f[e[i].v] = true;
                }
            }
        }
    }

    return d[(n << 1) - 1] < 0x3f3f3f3f;
}

long long solve()
{
    long long c = 0, y = 0x7fffffffffffffff;

    while (spfa())
    {
        int r = 0x7fffffff;
        for (int z = (n << 1) - 1; z; z = e[p[z]].u)
            r = min(r, e[p[z]].c);

        for (int z = (n << 1) - 1; z; z = e[p[z]].u)
        {
            c += (long long)r * e[p[z]].w;
            e[p[z]].c -= r;
            e[p[z] ^ 1].c += r;
        }

        y = min(y, c);
    }

    return -y;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        adde(i << 1, i << 1 | 1, -a, 0x7fffffff);
    }

    for (; m--; adde((u - 1) << 1 | 1, (v - 1) << 1, 0, w))
        scanf("%d%d%d", &u, &v, &w);

    printf("%lld\n", solve());
    return 0;
}