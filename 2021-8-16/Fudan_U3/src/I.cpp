#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int m = 0;
    while (m * m < n)
        m++;
    int mm = (n - 1) / m + 1;
    for (int i = 0; i < (1 << n); i++)
    {
        bool ans = 1;
        bool cnt = 0;
        for (int j = 0; j < mm; j++)
        {
            bool flag = 0;
            for (int k = 0; k < m && j * m + k < n; k++)
            {
                if (i & (1 << (j * m + k)))
                {
                    flag = 1;
                    cnt = !cnt;
                }
            }
            ans &= flag;
        }
        if (ans ^ cnt)
            printf("0");
        else
            printf("1");
    }
    return 0;
}