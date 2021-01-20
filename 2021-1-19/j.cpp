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

int f[5];
int temp[5];

int main()
{
    srand(time(NULL));
    int t;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 5; i++)
        {
            scanf("%d", &temp[i]);
            // temp[i] = rand() % 200 - 100;
        }
        for (int i = 0; i < 243; i++)
        {
            int x = i;
            for (int j = 0; j < 5; j++)
            {
                f[j] = temp[j] + x % 3 - 1;
                x /= 3;
            }
            int a = f[4] - 4 * f[3] + 6 * f[2] - 4 * f[1] + f[0];
            if (a % 24 != 0)
                continue;
            a /= 24;
            if (abs(a) > 100)
                continue;
            int b = f[3] - 3 * f[2] + 3 * f[1] - f[0] - 60 * a;
            if (b % 6 != 0)
                continue;
            b /= 6;
            if (abs(b) > 100)
                continue;
            int c = f[2] - 2 * f[1] + f[0] - 12 * b - 50 * a;
            if (c % 2 != 0)
                continue;
            c /= 2;
            if (abs(c) > 100)
                continue;
            int d = f[1] - f[0] - 3 * c - 7 * b - 15 * a;
            if (abs(d) > 100)
                continue;
            int e = f[0] - d - c - b - a;
            if (abs(e) > 100)
                continue;
            printf("%d %d %d %d %d\n", e, d, c, b, a);
            // int test[5];
            // test[0] = e + d + c + b + a;
            // test[1] = e + 2 * d + 4 * c + 8 * b + 16 * a;
            // test[2] = e + 3 * d + 9 * c + 27 * b + 81 * a;
            // test[3] = e + 4 * d + 16 * c + 64 * b + 256 * a;
            // test[4] = e + 5 * d + 25 * c + 125 * b + 625 * a;
            // for (int j = 0; j < 5; j++)
            //     if (test[j] - temp[j] > 1 || test[j] - temp[j] < -1)
            //         printf("???");
            break;
        }
    }

    return 0;
}