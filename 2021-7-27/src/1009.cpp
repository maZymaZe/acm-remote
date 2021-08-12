#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int NMAX = 103;
ll mpa[NMAX][NMAX], mpb[NMAX][NMAX], mpal[NMAX][NMAX], mpbl[NMAX][NMAX],
    mpac[NMAX][NMAX], mpbc[NMAX][NMAX];
int T, n;
int main() {
    scanf("%d", &T);
    srand(19122417);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%lld", &mpa[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%lld", &mpb[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mpal[i][j] = mpal[i][j - 1] + mpa[i][j];
                mpac[i][j] = mpac[i - 1][j] + mpa[i][j];
                mpbl[i][j] = mpbl[i][j - 1] + mpb[i][j];
                mpbc[i][j] = mpbc[i - 1][j] + mpb[i][j];
            }
        }
        ll ans = 0, tota = 0, totb = 0;
        int px = 1, py = 1;
        while (px <= n && py <= n) {
            tota += mpa[px][py];
            totb += mpb[px][py];
            if (px == n) {
                py++;
            } else if (py == n) {
                px++;
            } else {
                ll xav = (mpac[n][py] - mpac[px][py]) / (n - px);
                ll xbv = (mpbc[n][py] - mpbc[px][py]) / (n - px);
                ll yav = (mpal[px][n] - mpal[px][py]) / (n - py);
                ll ybv = (mpbl[px][n] - mpbl[px][py]) / (n - py);
                if (xav * xbv > yav * ybv) {
                    px++;
                } else
                    py++;
            }
        }
        ans = max(ans, tota * totb);
        for (int i = 1; i <= 10000; i++) {
            tota = 0, totb = 0;
            px = 0, py = 0;
            while (px <= n && py <= n) {
                tota += mpa[px][py];
                totb += mpb[px][py];
                if (px == n) {
                    py++;
                } else if (py == n) {
                    px++;
                } else {
                    ll xav = (mpac[n][py] - mpac[px][py]) / (n - px);
                    ll xbv = (mpbc[n][py] - mpbc[px][py]) / (n - px);
                    ll yav = (mpal[px][n] - mpal[px][py]) / (n - py);
                    ll ybv = (mpbl[px][n] - mpbl[px][py]) / (n - py);
                    if ((xav * xbv > yav * ybv) ^ (rand() % 100 > 80)) {
                        px++;
                    } else
                        py++;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}