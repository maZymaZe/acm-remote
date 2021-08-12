#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;
const int NMAX = 1e5 + 10;
string s;
int T, n, f[NMAX], v[30], height[NMAX], r[NMAX], u[NMAX];
long long k;
void radix(int* s, int* a, int* b, int n, int m) {
    static int c[NMAX];
    fill(c, c + m + 1, 0);
    for (int i = n; i--;)
        ++c[s[a[i]]];
    for (int i = 1; i <= m; i++)
        c[i] += c[i - 1];
    for (int i = n; i--;)
        b[--c[s[a[i]]]] = a[i];
}

void FSA(int* s, int* sa, int* h, int n, int m) {
    static int a[NMAX << 1], t[NMAX];
    fill(a, a + (n << 1), 0);
    copy(s, s + n, a);
    for (int len = 1; len / 2 < n; len <<= 1) {
        auto b = a + len / 2;
        iota(sa, sa + n, 0);
        radix(b, sa, t, n, m);
        radix(a, t, sa, n, m);
        t[sa[0]] = 1;
        for (int i = 1; i < n; i++) {
            t[sa[i]] = t[sa[i - 1]] +
                       (a[sa[i]] != a[sa[i - 1]] || b[sa[i]] != b[sa[i - 1]]);
        }
        copy(t, t + n, a);
        m = t[sa[n - 1]];
        if (m == n)
            break;
    }
    for (int i = 0; i < n; i++)
        --a[i];
    for (int i = 0; i < n; i++)
        u[sa[i]] = i;
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (k)
            k--;
        if (a[i]) {
            while (s[i + k] == s[sa[a[i] - 1] + k])
                k++;
        }
        h[a[i]] = k;
    }
}

bool ck(int x, long long y) {
    long long w = 0;
    for (int i = 0, j = 0, z = 0; i < n; z -= v[f[i++]]) {
        while (j < n && z <= x)
            z += v[f[j++]];
        if (j - i - (z > x) > height[u[i]])
            w += j - i - (z > x) - height[u[i]];
    }
    return w >= y;
}

int search() {
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        r += v[f[i]];
    }
    int b = r, mid = (l + r) / 2;
    while (l <= r) {
        mid = (l + r) / 2;
        if (ck(mid, k))
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l == b + 1 ? -1 : l;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld", &n, &k);
        cin >> s;
        for (int i = 0; i < n; i++) {
            f[i] = s[i] - 'a' + 1;
        }
        f[n] = 0;
        for (int i = 1; i <= 26; i++) {
            scanf("%d", &v[i]);
        }
        FSA(f, r, height, n, 27);
        printf("%d\n", search());
    }
    return 0;
}