#include <iostream>
#include <string>
using namespace std;
string s[103];
string t;
int v[103] = {0}, nxt[103][103] = {0};
int n, ans = 0;
void calnxt(int i) {
    nxt[i][0] = -1;
    int l = s[i].size();
    for (int k = 1; k < l; k++) {
        int j = nxt[i][k - 1];
        while (s[i][j + 1] != s[i][k] && j >= 0) {
            j = nxt[i][j];
        }
        if (s[i][j + 1] == s[i][k]) {
            nxt[i][k] = j + 1;
        } else
            nxt[i][k] = -1;
    }
}
bool mch(int i) {
    int pot = 0, pop = 0, lot = t.size(), lop = s[i].size();
    while (pot < lot) {
        if (t[pot] == s[i][pop]) {
            pot++;
            pop++;
        } else {
            if (pop == 0)
                pot++;
            else
                pop = nxt[i][pop - 1] + 1;
        }
        if (pop == lop)
            return true;
    }
    return false;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
        calnxt(i);
    for (int i = 1; i <= n; i++) {
        if (!v[i])
            ans++;

        t = s[i] + s[i];
        for (int j = i + 1; j <= n; j++) {
            if (v[j]||s[i].size()!=s[j].size())
                continue;
            if (mch(j)) {
                v[j] = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
