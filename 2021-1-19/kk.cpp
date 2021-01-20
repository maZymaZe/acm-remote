#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int k;
int n, m;
int e = -1;
int input[10010];
map<int, int> ma;
char str[10];
bool vis[110];
bool in[110];
int cnt = 0;

int main()
{
    srand(time(0));
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
        scanf("%d", &input[i]);
    sort(input, input + k);
    for (int i = 0; i < k; i++)
        ma[input[i]] = i;
    for (int i = 2; i <= (k - 1) / 2; i++)
    {
        if ((k - 1) % i == 0)
        {
            printf("r %d %d\n", input[0], input[i]);
            cnt++;
            cout.flush();
            scanf("%s", str);
            if (str[0] == 'y')
            {
                n = i;
                m = (k - 1) / i;
                for (int j = 1; j < m - 1; j++)
                {
                    printf("r %d %d\n", input[i * j], input[i * (j + 1)]);
                    cnt++;
                    cout.flush();
                    scanf("%s", str);
                    if (str[0] == 'n')
                    {
                        e = j;
                        break;
                    }
                }
                if (e == -1)
                    e = m - 1;
                break;
            }
            else
            {
                printf("r %d %d\n", input[0], input[i + 1]);
                cnt++;
                cout.flush();
                scanf("%s", str);
                if (str[0] == 'y')
                {
                    if (i == (k - 1) / 2)
                    {
                        n = i;
                        m = (k - 1) / i;
                        e = 0;
                        break;
                    }
                    printf("r %d %d\n", input[i + 1], input[i * 2 + 1]);
                    cnt++;
                    cout.flush();
                    scanf("%s", str);
                    if (str[0] == 'y')
                    {
                        n = i;
                        m = (k - 1) / i;
                        e = 0;
                        break;
                    }
                }
            }
        }
    }
    if (e == -1)
    {
        printf("! %d\n", input[0]);
        cout.flush();
        return 0;
    }
    int cnt = 1;
    int top = e * n;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
            if (!vis[j])
            {
                printf("c %d %d\n", input[top], input[e * n + j + 1]);
                cnt++;
                if (cnt > 2 * k)
                    while (1)
                        ;
                cout.flush();
                scanf("%s", str);
                if (str[0] == 'y')
                {
                    top = e * n + j + 1;
                    in[j] = true;
                    for (int k = 0; k < n; k++)
                        vis[k] = in[k];
                    break;
                }
            }
    }
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            printf("! %d\n", input[e * n + i + 1]);
            cout.flush();
            return 0;
        }

    return 0;
}