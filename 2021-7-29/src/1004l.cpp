#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>

#define A 26
#define N 100005

using namespace std;

int v[A + 2], f[N], r[N], h[N], u[N], t, n;
long long k;
char s[N];

void radix(int* s, int* a, int* b, int n, int m) {
    static int c[N];
    fill(c, c + m + 1, 0);
    for (int i = n; i--;)
        ++c[s[a[i]]];
    for (int i = 1; i <= m; i++)
        c[i] += c[i - 1];
    for (int i = n; i--;)
        b[--c[s[a[i]]]] = a[i];
}

void sa(int* s, int* sa, int* h, int n, int m) {
    static int a[N << 1], t[N];
    fill(a, a + (n << 1), 0);
    copy(s, s + n, a);

    for (int len = 1; len / 2 < n; len <<= 1) {
        auto b = a + len / 2;
        iota(sa, sa + n, 0);
        radix(b, sa, t, n, m);
        radix(a, t, sa, n, m);
        t[sa[0]] = 1;

        for (int i = 1; i < n; i++)
            t[sa[i]] = t[sa[i - 1]] +
                       (a[sa[i]] != a[sa[i - 1]] || b[sa[i]] != b[sa[i - 1]]);

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
            --k;
        if (a[i])
            while (s[i + k] == s[sa[a[i] - 1] + k])
                ++k;
        h[a[i]] = k;
    }
}

bool test(int x, long long k) {
    // printf("TEST X %d K %lld\n", x, k);
    long long w = 0;

    for (int i = 0, j = 0, z = 0; i < n; z -= v[f[i++]]) {
        while (j < n && z <= x)
            z += v[f[j++]];
        // printf("REAL J %d Z %d\n", j, z);
        // printf("I %d H %d J %d Z %d\n", i, h[u[i]], j - i - (z > x), z);
        if (j - i - (z > x) > h[u[i]])
            w += j - i - (z > x) - h[u[i]];
    }

    // printf("W %lld K %lld\n", w, k);
    return w >= k;
}

int search() {
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
        r += v[f[i]];
    int b = r;

    for (int m = (l + r) >> 1; l <= r; m = (l + r) >> 1) {
        if (test(m, k))
            r = m - 1;
        else
            l = m + 1;
    }

    return l == b + 1 ? -1 : l;
}

void FSA(int* s, int* sa, int* h, int n, int m) {
    static int a[N << 1], t[N];
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
int main() {
    for (scanf("%d", &t); t--; printf("%d\n", search())) {
        scanf("%d%lld%100002s", &n, &k, s);
        for (int i = 0; i < n; i++)
            f[i] = s[i] - 'a' + 1;
        f[n] = 0;
        for (int i = 1; i <= A; i++)
            scanf("%d", &v[i]);
        FSA(f, r, h, n, A + 1);
        // for (int i = 0; i < n; i++) printf("I %d SA %d H %d\n", i, r[i],
        // h[i]); for (int i = 0; i < n; i++)
        //     printf("J %d SU %d H %d\n", i, u[i], h[u[i]]);
    }

    return 0;
}