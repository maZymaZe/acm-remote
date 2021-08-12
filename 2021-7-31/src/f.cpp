#include <cstdio>
#include <cstring>

#define N 100005

char a[32], s[N], t[N];
int z, n;

int main()
{
    for (scanf("%d", &z); z--;)
    {
        scanf("%d%s%s%s", &n, a, s, t);

        int k = n - 1;
        for (; k >= 0 && s[k] == 'z'; k--)
            s[k] = 'a';

        if (!~k)
        {
            puts("NO");
            continue;
        }

        ++s[k];
        bool f = false;

        for (int i = 0; !f && i < n; i++)
            f = s[i] == a[0];

        if (!f)
        {
            if (s[n - 1] < a[0])
                s[n - 1] = a[0];
            else
            {
                k = n - 2;
                for (; k >= 0 && s[k] == 'z'; k--)
                    s[k] = 'a';

                if (!~k)
                {
                    puts("NO");
                    continue;
                }

                ++s[k];
                s[n - 1] = 'a';
                f = false;

                for (int i = 0; !f && i < n; i++)
                    f = s[i] == a[0];
                if (!f)
                    s[n - 1] = a[0];
            }
        }

        puts(!~strncmp(s, t, n) ? s : "NO");
    }

    return 0;
}
