#include <bits/stdc++.h>
using namespace std;

const double g = 10.0;

int main() {
    int z;
    scanf("%d", &z);
    while (z--) {
        int v, n;
        scanf("%d%d", &v, &n);
        double r = 1e18, l = -r;
        for (int i = 1; i <= n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            double a = g * x * x, b = -2.0 * v * v * x,
                   c = 2.0 * v * v * y + g * x * x;
            double sqrt_delta = pow(b * b - 4.0 * a * c, 0.5);
            double t1 = (-b - sqrt_delta) * 0.5 / a;
            double t2 = (-b + sqrt_delta) * 0.5 / a;
            r = min(r, t2);
            l = max(l, t1);
        }
        printf("%.3lf\n", (l + r) / 2.0);
    }
    return 0;
}
