#include <cstdio>

#define N 1024

int a[N], f[N][N], n, w;

inline int max(int a, int b) { return a > b ? a : b; }

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[n + i] = a[i];
    }

    for (int k = 2; k <= n; k++)
        for (int i = 1; i + k <= n << 1; i++)
            for (int j = i + 1; j < i + k; j++)
                f[i][i + k] = max(f[i][i + k], f[i][j] + f[j][i + k] + a[i] * a[j] * a[i + k]);

    for (int i = 1; i <= n; i++)
        w = max(w, a[i] + f[i][i + n]);

    printf("%d\n", w);
    return 0;
}