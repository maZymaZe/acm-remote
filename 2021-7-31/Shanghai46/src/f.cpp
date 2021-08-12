#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int z;
    cin >> z;
    while (z--) {
        int n;
        char k;
        string s, t;
        cin >> n >> k >> s >> t;
        int st = 0;
        bool flag = false, ok = false;
        while (s[st] == t[st])
            flag |= (s[st] == k), ++st;
        bool flag1 = flag, flag2 = flag;
        int ii;
        for (int i = st; (i < n) && !ok; ++i) {
            if (i == st) {
                for (char j = s[i] + 1; j < t[i]; ++j) {
                    if (flag1 | (j == k)) {
                        ii = i;
                        ok = true;
                        for (int i = 0; i < ii; ++i) {
                            cout << s[i];
                        }
                        cout << j;
                        for (int i = 1; i < n - ii; ++i) {
                            cout << 'a';
                        }
                        cout << "\n";
                        break;
                    }
                }
            } else {
                for (char j = s[i] + 1; j <= 'z'; ++j) {
                    if (flag1 | (j == k)) {
                        ii = i;
                        ok = true;
                        for (int i = 0; i < ii; ++i) {
                            cout << s[i];
                        }
                        cout << j;
                        for (int i = 1; i < n - ii; ++i) {
                            cout << 'a';
                        }
                        cout << "\n";
                        break;
                    }
                }
                if (ok)
                    break;
                for (char j = 'a'; j < t[i] - 1; ++j) {
                    if (flag2 | (j == k)) {
                        ii = i;
                        ok = true;
                        for (int i = 0; i < ii; ++i) {
                            cout << t[i];
                        }
                        cout << j;
                        for (int i = 1; i < n - ii; ++i) {
                            cout << 'a';
                        }
                        cout << "\n";
                        break;
                    }
                }
            }
            flag1 |= (s[i] == k);
            flag2 |= (t[i] == k);
        }
        if (!ok) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
