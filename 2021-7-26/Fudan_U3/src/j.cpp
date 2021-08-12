#include <bits/stdc++.h>
using namespace std;

int a[100007], b[100007];

vector<int> c;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    vector<double> sums(n + 1, 0);
    double left = *min_element(nums.begin(), nums.end());
    double right = *max_element(nums.begin(), nums.end());
    while (right - left > 1e-7) {
        double minSum = 0, mid = left + (right - left) / 2.0;
        bool check = false;
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1] - mid;
            if (i >= k) {
                minSum = min(minSum, sums[i - k]);
            }
            if (i >= k && sums[i] > minSum) {
                check = true;
                break;
            }
        }
        if (check)
            left = mid;
        else
            right = mid;
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    double ansa, ansb;
    for (int i = 1; i <= n; ++i)
        c.push_back(a[i]);
    ansa = findMaxAverage(c, x);
    c.clear();
    for (int j = 1; j <= m; ++j)
        c.push_back(b[j]);
    ansb = findMaxAverage(c, y);
    cout << setprecision(8) << ansa + ansb << endl;
    return 0;
}
