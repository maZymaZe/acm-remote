#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int n, x;
stack<int> st;
vector<int> v, vis, cnt, ans, cc;
vector<vector<int>> clb;
string s;

struct PR {
    int cnt, color;
    bool operator<(const PR& x) const {
        if (cnt == x.cnt)
            return x.color < color;
        return cnt > x.cnt;
    }
};
set<PR> ss;

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a.size() > b.size();
}
int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cin >> n;
    cin >> s;
    cnt.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 0; i <= n; i++) {
        if (cnt[i])
            ss.insert({cnt[i], i});
    }
    v.resize(2 * n);
    ans.resize(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            v[st.top()] = i;
            v[i] = st.top();
            st.pop();
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == ')')
            continue;
        int p = i + 1;
        cc.clear();

        while (p != v[i]) {
            cc.push_back(p);
            p = v[p] + 1;
        }
        if (cc.size() > 1)
            clb.push_back(cc);
    }

    cc.clear();
    int p = 0;
    while (p < 2 * n) {
        cc.push_back(p);
        p = v[p] + 1;
    }
    if (cc.size() > 1)
        clb.push_back(cc);

    sort(clb.begin(), clb.end(), cmp);
    int len = clb.size();
    for (int i = 0; i < len; i++) {
        vis.clear();
        int l = clb[i].size();
        if (l > ss.size()) {
            cout << "NO" << endl;
            return 0;
        }
        int ccnt = 0;
        for (auto it : ss) {
            vis.push_back(it.color);
            ans[clb[i][ccnt++]] = it.color;
            if (ccnt == l)
                break;
        }
        for (int j = 0; j < l; j++) {
            ss.erase({cnt[vis[j]], vis[j]});
            cnt[vis[j]]--;
            if (cnt[vis[j]])
                ss.insert({cnt[vis[j]], vis[j]});
        }
    }
    p = 0;
    cout << "YES" << endl;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '(') {
            if (ans[i])
                cout << ans[i] << ' ';
            else {
                while (cnt[p] == 0) {
                    p++;
                }
                ans[i] = p;
                cnt[p]--;
                cout << ans[i] << ' ';
            }
        }
    }
    return 0;
}