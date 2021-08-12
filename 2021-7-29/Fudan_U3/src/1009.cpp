#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int T, a[300], b[300], c[200], ap, bp;
string s;
int main() {
    cin >> T;
    for (int ttt = 1; ttt <= T; ttt++) {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= 30; i++) {
            cin >> s;
            for (int j = 1; j <= 100; j++) {
                if (s[j - 1] == '#')
                    c[j] = 1;
            }
        }
        ap = 0, bp = 0;
        for (int i = 1; i < 100; i++) {
            if (c[i] == 0 && c[i + 1] == 1) {
                a[++ap] = i + 1;
            }
            if (c[i] == 1 && c[i + 1] == 0) {
                b[++bp] = i;
            }
        }
        cout << "Case #" << ttt << ":\n";
        cout << a[1] << ' ' << b[bp - 6] << endl;
        for (int i = 1; i <= 6; i++) {
            cout << a[ap - 6 + i] << ' ' << b[bp - 6 + i] << endl;
        }
    }
    return 0;
}