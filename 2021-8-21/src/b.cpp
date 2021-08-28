#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <random>
using namespace std;
const int NMAX = 1e5 + 10;
const long double EPS = 1e-6;
int T, n;
double a[NMAX], b[NMAX], c[NMAX], ca[301], cb[301];
int main() {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rand_num(seed);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%lf", &b[i]);
        for (int i = 0; i < n; i++)
            scanf("%lf", &c[i]);

        int s = 0, p = 0;
        for (int i = 1; i <= 300; i++) {
            int ta = rand_num() % n, tb = rand_num() % n;
            if (fabs(c[ta] - c[tb]) < EPS) {
                s++;
            } else if (c[ta] < 20 || c[tb] < 20) {
                s++;
            } else {
                p++;
                ca[p] = (a[ta] - a[tb]) / (c[ta] - c[tb]);
                cb[p] = (b[ta] - b[tb]) / (c[ta] - c[tb]);
            }
        }
        double maa = -1e18, mab = -1e18, mia = 1e18, mib = 1e18;
        for (int i = 1; i <= p; i++) {
            maa = max(maa, ca[i]);
            mab = max(mab, cb[i]);
            mia = min(mia, ca[i]);
            mib = min(mib, cb[i]);
        }
        if (maa - mia < mab - mib) {
            printf("1\n");
        } else {
            printf("2\n");
        }
    }
    return 0;
}
