#include <bits/stdc++.h>

using namespace std;

char in[110];
long long cnt;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", in);
        cnt = 0;
        int l = strlen(in);
        for (int i = 0; i < l;) {
            long long c = 0;
            while (in[i] <= '9' && in[i] >= '0') {
                c *= 10;
                c += in[i] - '0';
                i++;
            }
            if (c) {
                puts("NO");
                break;
            }
            while (i < l && (in[i] > '9' || in[i] < '0'))
                i++;
            if (i == l)
                puts("YES");
        }
    }
    return 0;
}