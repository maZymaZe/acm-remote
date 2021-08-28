#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using uint128 = __uint128_t;
const uint128 K = 16;
int pos[9] = {0, 9, 8, 7, 6, 5, 4, 3, 2};

int precalc(uint128 n) {
    cout << "p1\n";
    for (int i = 2; i <= K / 2; ++i) {
        cout << "p1\n";
        cout << "add 1\n";
        if (i == n) {
            return 1;
        }
    }
    cout << "dup\nadd 1\n";
    if (n == K) {
        return 1;
    }
    return 0;
}

uint128 read() {
    ull x;
    cin >> x;
    return uint128(x);
}

stack<uint128> s;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("ans.txt", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        while (!s.empty())
            s.pop();
        uint128 n = read();
        if (n == 0) {
            cout << "p1\nsub 0\nend\n";
            continue;
        } else if (n == 1) {
            cout << "p1\nend\n";
            continue;
        } else if (precalc(n)) {
            cout << "end\n";
            continue;
        }
        s.push(n);
        while (s.top() > K) {
            uint128 tmp = s.top() / K, p = s.top() - tmp * K;
            if (p <= K / 2) {
                s.push(tmp);
            } else {
                s.push(tmp + 1);
            }
        }
        if (s.top() > K / 2) {
            cout << "dup\n";
            if (s.top() < K) {
                cout << "sub " << pos[K - s.top()] << '\n';
            }
        } else {
            if (s.top() > 1) {
                cout << "p1\nadd " << pos[s.top() - 1] << '\n';
            } else {
                cout << "dup\n";
                s.pop();
                cout << "add " << pos[s.top() - K] << '\n';
            }
        }
        while (s.size() > 1) {
            uint128 tmp = s.top();
            s.pop();
            cout << "mul 1\n";
            tmp *= K;
            if (tmp > s.top()) {
                cout << "sub " << pos[tmp - s.top()] << '\n';
            } else if (tmp < s.top()) {
                cout << "add " << pos[s.top() - tmp] << '\n';
            }
        }
        cout << "end\n";
    }
    return 0;
}
