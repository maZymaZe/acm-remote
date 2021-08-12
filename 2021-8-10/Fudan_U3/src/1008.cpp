#include <iostream>
#include <string>
using namespace std;
int T, n, x, y, c, d, nx, ny;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> T;
    while (T--) {
        string s;
        cin >> x >> y >> d;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> nx >> ny;
            int xd, yd;
            if (nx > x)
                xd = 1;
            else
                xd = 3;
            if (ny > y)
                yd = 0;
            else
                yd = 2;

            if (!(d & 1)) {
                if (d == yd) {
                    s += string(abs(ny - y), 'f');
                    if (xd == (yd + 1) % 4) {
                        s += 'c';

                    } else {
                        s += 'u';
                    }
                    d = xd;
                    s += string(abs(nx - x), 'f');
                } else {
                    if (xd == (d + 1) % 4) {
                        s += 'c';

                    } else {
                        s += 'u';
                    }
                    d = xd;
                    s += string(abs(nx - x), 'f');
                    if (yd == (d + 1) % 4) {
                        s += 'c';
                    } else {
                        s += 'u';
                    }
                    d = yd;
                    s += string(abs(ny - y), 'f');
                }
            } else {
                if (d == xd) {
                    s += string(abs(nx - x), 'f');
                    if (yd == (xd + 1) % 4) {
                        s += 'c';
                    } else {
                        s += 'u';
                    }
                    d = yd;
                    s += string(abs(ny - y), 'f');
                } else {
                    if (yd == (d + 1) % 4) {
                        s += 'c';

                    } else {
                        s += 'u';
                    }
                    d = yd;
                    s += string(abs(ny - y), 'f');
                    if (xd == (d + 1) % 4) {
                        s += 'c';
                    } else {
                        s += 'u';
                    }
                    d = xd;
                    s += string(abs(nx - x), 'f');
                }
            }
            x = nx, y = ny;
        }
        cout << s << endl;
    }
    return 0;
}