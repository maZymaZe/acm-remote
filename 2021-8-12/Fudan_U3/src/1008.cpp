#include <bits/stdc++.h>

using namespace std;
#define ld double
#define eps 1e-8L
#define pi acosl(-1)

ld xx1, yy1, r1;
ld xx2, yy2, r2;

ld a;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%lf%lf", &r1, &xx1, &yy1);
        scanf("%lf%lf%lf", &r2, &xx2, &yy2);
        scanf("%lf", &a);
        if (r2 * 2.L - eps < a) {
            puts("0.000000");
            continue;
        }
        ld rr1 = sqrt(r1 * r1 - a * a / 4.L) - a / 2.L;
        ld rr2 = sqrt(r2 * r2 - a * a / 4.L) - a / 2.L;
        ld c = sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2));

        // printf("%.6f %.6f %.6f\n", (double)rr1, (double)rr2, (double)c);
        if (rr1 + rr2 - eps < c || rr2 < eps) {
            puts("0.000000");
            continue;
        }
        if (abs(rr1 - rr2) > c - eps) {
            if (rr2 > rr1)
                puts("1.000000");
            else
                printf("%.6f\n", (double)(rr2 * rr2 / (rr1 * rr1)));
            continue;
        }

        ld cosa = (rr1 * rr1 + c * c - rr2 * rr2) / (2.L * rr1 * c);
        ld cosb = (rr2 * rr2 + c * c - rr1 * rr1) / (2.L * rr2 * c);
        ld alpha = acosl(cosa);
        // printf("%.6f\n", (double)alpha);
        ld beta = acosl(cosb);
        // printf("%.6f\n", (double)beta);
        ld p = (rr1 + rr2 + c) / 2.L;
        ld S = sqrt(p * (p - rr1) * (p - rr2) * (p - c));
        // printf("%.6f\n", (double)S);
        ld ans =
            (rr1 * rr1 * alpha + rr2 * rr2 * beta - 2.L * S) / (pi * rr1 * rr1);
        printf("%.6f\n", (double)(ans));
    }
    return 0;
}