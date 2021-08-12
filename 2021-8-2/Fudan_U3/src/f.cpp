#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t[100007];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    ll m;
    cin >> n >> m;
    ll mx = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        mx = max(mx, t[i]);
        sum += t[i];
    }
    ll mid_t = mx;
    mid_t = max(mid_t, sum % m == 0 ? sum / m : (sum / m) + 1);
    int id = 1;
    ll current_size = 0;
    bool is_last = false;
    ll last_id, last_l, last_r;
    for (int i = 1; i <= n;) {
        current_size += t[i];
        if (current_size > mid_t) {
            cout << 2 << " ";
            last_id = id, last_l = current_size - t[i], last_r = mid_t;
            ++id;
            t[i] = current_size - mid_t;
            current_size = 0;
            is_last = true;
        } else if (current_size == mid_t) {
            if (is_last) {
                cout << id << " " << current_size - t[i] << " " << current_size
                     << " s";
                cout << last_id << " " << last_l << " " << last_r << "\n";
            } else {
                cout << 1 << " " << id << " " << current_size - t[i] << " "
                     << current_size << "\n";
            }
            current_size = 0;
            ++id;
            ++i;
            is_last = false;
        } else {
            if (is_last) {
                cout << id << " " << current_size - t[i] << " " << current_size
                     << " ";
                cout << last_id << " " << last_l << " " << last_r << "\n";
            } else {
                cout << 1 << " " << id << " " << current_size - t[i] << " "
                     << current_size << "\n";
            }
            ++i;
            is_last = false;
        }
    }

    return 0;
}