#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 998244353;
const ld PI = atan(1.0L) * 4;
struct MYCOMPLEX {
    ld r, i;
    MYCOMPLEX(ld a = 0, ld b = 0) { r = a, i = b; }
    MYCOMPLEX conj() const { return MYCOMPLEX(r, -i); }
    MYCOMPLEX operator/(ld x) const { return MYCOMPLEX(r / x, i / x); }
    MYCOMPLEX operator+(const MYCOMPLEX& b) const {
        return MYCOMPLEX(r + b.r, i + b.i);
    }
    MYCOMPLEX operator-(const MYCOMPLEX& b) const {
        return MYCOMPLEX(r - b.r, i - b.i);
    }
    MYCOMPLEX operator*(const MYCOMPLEX& b) const {
        return MYCOMPLEX(r * b.r - i * b.i, i * b.r + r * b.i);
    }
};

int qpow(int a, int e) {
    int r = 1;
    while (e) {
        if (e & 1)
            r = (ll)r * a % MOD;
        a = (ll)a * a % MOD;
        e >>= 1;
    }
    return r;
}
void dft(vector<MYCOMPLEX>& a, int op = 1) {
    int n = a.size();
    for (int i = 1, j = 0; i < n - 1; i++) {
        for (int s = n; j ^= s >>= 1, ~j & s;)
            ;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int i = 1; i < n; i <<= 1) {
        MYCOMPLEX u(cos(PI / i), op * sin(PI / i));
        for (int j = 0; j < n; j += i << 1) {
            MYCOMPLEX w(1, 0);
            for (int k = 0; k < i; k++, w = w * u) {
                MYCOMPLEX x = a[j + k], y = w * a[j + k + i];
                a[j + k] = x + y;
                a[j + k + i] = x - y;
            }
        }
    }
    if (op == -1) {
        for (int i = 0; i < n; i++)
            a[i] = a[i] / n;
    }
}
vector<ll> multi(vector<ll> a, vector<ll> b) {
    if (a.size() * b.size() < 4096) {
        vector<ll> c(a.size() + b.size() - 1);
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                c[i + j] = (c[i + j] + a[i] * b[j] % (MOD - 1)) % (MOD - 1);
            }
        }
        return c;
    }
    int n = 1;
    while (n < a.size() + b.size() - 1) {
        n <<= 1;
    }
    a.resize(n), b.resize(n);
    ll q = round(sqrt(MOD - 1));
    vector<MYCOMPLEX> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++) {
        A[i] = MYCOMPLEX(a[i] / q, a[i] % q);
        B[i] = MYCOMPLEX(b[i] / q, b[i] % q);
    }
    dft(A), dft(B);
    for (int i = 0; i < n; i++) {
        int j = (n - i) % n;
        C[i] = B[i] * (A[i] - A[j].conj()) * MYCOMPLEX(0, -0.5);
        D[i] = B[i] * (A[i] + A[j].conj()) * MYCOMPLEX(0.5, 0);
    }
    dft(C, -1), dft(D, -1);
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = (llround(D[i].r) % (MOD - 1) * q * q +
                llround(D[i].i) % (MOD - 1) * q +
                llround(C[i].r) % (MOD - 1) * q + llround(C[i].i) % (MOD - 1)) %
               (MOD - 1);
    }
    return c;
}
vector<ll> ppow(vector<ll> a, int e) {
    vector<ll> r = {1};
    for (; e; e >>= 1, a = multi(a, a)) {
        if (e & 1)
            r = multi(r, a);
    }
    return r;
}

bool cmp(const vector<ll>& a, const vector<ll>& b) {
    return a.size() < b.size();
}
int T, n, r;
ll ipt;
unordered_map<ll, ll> m;
deque<vector<ll>> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        while (!q.empty())
            q.pop_back();
        m.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> ipt;
            m[ipt]++;
        }
        if (m.count(0)) {
            cout << 0 << '\n';
            continue;
        }
        for (auto v : m) {
            vector<ll> c(v.first + 1);
            c[0] = 1;
            ++c[v.first];
            q.push_back(ppow(c, v.second));
        }
        sort(q.begin(), q.end(), cmp);
        while (q.size() > 1) {
            q.push_back(multi(q[0], q[1]));
            q.pop_front(), q.pop_front();
        }
        for (int i = r = 1; i < q[0].size(); i++) {
            r = (ll)r * qpow(i, q[0][i]) % MOD;
        }
        cout << r << '\n';
    }
    return 0;
}