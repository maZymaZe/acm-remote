#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

ll n, s, t, h, suma, sumb, mxa, mnb;
ll a[N], b[N];
priority_queue<ll> pqa, pqb;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    a[0] = 1, b[0] = 1;
    while (T--) {
        cin >> n >> t >> s >> h;
        suma = sumb = mxa = 0;
        mnb = 2e9;
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
            // suma += a[i];
            mxa = max(mxa, a[i]);
        }
        for (int i = 1; i < n; ++i) {
            cin >> b[i];
            // sumb += b[i];
            mnb = min(mnb, b[i]);
        }
        // a[n] = mxa, b[n] = mnb;
        sort(a + 1, a + n);
        sort(b + 1, b + n);
        a[n] = h, b[n] = h;
        for (int i = s + 1; i + t < n; ++i) {
            suma += a[i];
            sumb += b[i];
        }
        ll la = suma + a[s], ra = suma + a[n - t], lb = sumb + b[s],
           rb = sumb + b[n - t];
        ll ans = 2e11;
        if (ra <= lb) {
            cout << "IMPOSSIBLE\n";
            continue;
        } else if (rb < la) {
            cout << a[0] - b[n] << '\n';
            continue;
        }
        ans = sumb - suma + 1;
        if (la <= rb) {
            if (la - 1 >= lb)
                ans = min(ans, a[0] - (la - 1 - sumb));
            if (rb + 1 <= ra)
                ans = min(ans, rb + 1 - suma - b[n]);
        }
        cout << ans << '\n';
    }
    return 0;
}