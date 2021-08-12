#include <bits/stdc++.h>

using namespace std;

#define pi 3.1415926535897932384626L
#define ld long double
#define eps 1e-9

ld w, d;

int main() {
    // printf("%.8f\n", pi);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%LF%LF", &w, &d);
        ld mi = min(w, d);
        ld ma = max(w, d);
        ld c = sqrt(ma * ma + mi * mi);
        if (c / mi > 1.5 + eps) {
            long long ans1 = 4 + (long long)(pi / mi) * 2;
            long long ans2 = 0;
            if (pi - c > eps)
                ans2 = 7 + (long long)((pi - c) / mi) * 2;
            // long long ans3 = 0;
            // if (pi - 2 * c > eps)
            //     ans3 = 10 + ((pi - 2 * c) / mi) * 2;
            printf("%lld\n", max(ans1, ans2));
        } else {
            long long ans1 = 4 + (long long)(pi / c) * 3;
            long long ans2 = 0;
            if (pi - mi > eps)
                ans2 = 6 + (long long)((pi - mi) / c) * 3;
            long long ans3 = 0;
            if (pi - 2 * mi > eps)
                ans3 = 8 + (long long)((pi - 2 * mi) / c) * 3;
            printf("%lld\n", max(max(ans1, ans2), ans3));
        }
        // long long ans1 = 4 + (long long)(pi / mi) * 2;
        // long long ans2 = 4 + (long long)(pi / c) * 3;
        // long long ans3 = 0;
        // if (pi - c > eps)
        //     ans3 = 7 + ((pi - c) / mi) * 2;
        // long long ans4 = 0;
        // if (pi - mi > eps)
        //     ans4 = 6 + ((pi - mi) / c) * 3;
        // long long ans5 = 0;
        // if (pi - 2 * c > eps)
        //     ans5 = 10 + ((pi - 2 * c) / mi) * 2;
        // long long ans6 = 0;
        // if (pi - 2 * mi > eps)
        //     ans6 = 8 + ((pi - 2 * mi) / c) * 3;
        // printf("%lld\n",
        //        max(max(max(ans1, ans2), max(ans3, ans4)), max(ans5, ans6)));
    }
    return 0;
}