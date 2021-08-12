#include <bits/stdc++.h>

using namespace std;

int tis(int L, int R) {
    if (R - L == 0)
        return 1;
    if (R - L == 1)
        return 3;
    int b = L + ((R - L + 1) / 3) - 1;
    int c = (b + R) / 2;
    return tis(L, b) + tis(b + 1, c) + tis(c + 1, R) + 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
        }
        printf("%d\n", tis(1, n));
    }
}