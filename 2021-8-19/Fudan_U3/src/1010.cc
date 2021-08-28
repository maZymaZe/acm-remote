#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Power {
    __int128_t a, b, c;
    __int128_t f(__int128_t x) { return a * x * x + b * x + c; }
    __int128_t delta() { return b * b - 4 * a * c; }
    __int128_t root() {
        return (-b + (__int128_t)sqrt((double)delta())) / (2 * a) + 1;
    }
} peo;

void output(__int128_t x) {
    if (x < 0 || x > 1e18)
        cout << "none\n";
    else
        cout << (ll)x << '\n';
}

int main() {
    // freopen("1010.in", "r", stdin);
    // freopen("j.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        peo.a = peo.b = peo.c = 0;
        int n, m;
        cin >> n >> m;
        int j = n;
        __int128_t flag = -1;
        for (int p = 0; p < 2; ++p) {
            flag *= -1;
            for (int i = 1; i <= j; ++i) {
                ll h, dh, d, dd;
                cin >> h >> dh >> d >> dd;
                peo.a += flag * dh * dd;
                peo.b += flag * (h * dd + dh * d);
                peo.c += flag * h * d;
            }
            j = m;
        }
        if (peo.c > 0) {
            output(0);
        } else if (peo.f(1) > 0) {
            output(1);
        } else if (peo.a == 0) {
            if (peo.b <= 0) {
                output(-1);
            } else {
                __int128_t ans = -peo.c / peo.b + 1;
                output(ans);
            }
        } else {
            if (peo.delta() <= 0) {
                output(-1);
            } else {
                __int128_t ans = peo.root();
                // cerr << ans << endl;
                if (ans + 100 <= 0) {
                    output(-1);
                } else {
                    for (__int128_t i = ans - 100; i <= ans + 100; ++i) {
                        if (i <= 0)
                            continue;
                        if (peo.f(i) > 0) {
                            output(i);
                            break;
                        }
                        if (i == ans + 100) {
                            output(-1);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
