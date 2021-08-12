#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
long double layer[N], sum[N];

void prework() {
    long double delta = 1;
    layer[0] = 0;
    for (int i = 1; i <= 10000; ++i) {
        layer[i] = layer[i - 1] + delta;
        delta /= 2.0;
    }
    for (int i = 1; i <= 10000; ++i) {
        sum[i] = sum[i - 1] + layer[i] * 2.0;
    }
}

int main() {
    prework();
    int T;
    scanf("%d", &T);
    while (T--) {
        int k;
        double x_root, y_root, x_lson, y_lson, x_rson, y_rson;
        scanf("%d%lf%lf%lf%lf%lf%lf", &k, &x_root, &y_root, &x_lson, &y_lson,
              &x_rson, &y_rson);
        double height = y_root - y_lson, init = x_rson - x_lson;
        // cout << height <<" "  init << endl;
        // cout << layer[k - 1] << endl;
        double ans = (sum[k - 1] - layer[k - 1]) * init * 0.5 * height;
        // cout << ans << endl;
        printf("%.3lf\n", ans);
    }
    return 0;
}