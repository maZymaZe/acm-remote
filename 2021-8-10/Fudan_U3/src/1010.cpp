#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        double p, q;
        scanf("%lf%lf", &p, &q);
        if (q > p - eps)
            puts("N0 M0R3 BL4CK 1CE TEA!");
        else
            puts("ENJ0Y YOURS3LF!");
    }
    return 0;
}