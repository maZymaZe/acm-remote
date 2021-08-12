#include <bits/stdc++.h>
using namespace std;
map<long double, int> mp;
int num[1000005];
int main() {
    int t, n, cnt, a, b, c, d;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        cnt = 1;
        mp.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            long double tmp;
            if (a == c)
                tmp = 1e9 + 7;
            else
                tmp = ((long double)b - d) / ((long double)a - c);
            //			cout<<tmp;
            mp[tmp] += 1;
        }
        memset(num, 0, sizeof(num));
        for (map<long double, int>::iterator ite = mp.begin(); ite != mp.end();
             ite++) {
            num[ite->second] += 1;
        }
        for (int i = n + 1; i > 1; i--) {
            num[i - 1] += num[i];
        }
        int sum = num[1];
        //		printf("::%d\n",sum);
        for (int i = 1; i <= n; i++) {
            printf("%d\n", i - cnt);
            if (i == sum) {
                cnt++;
                sum += num[cnt];
            }
        }
    }
    return 0;
}
