#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define int long long  //哈哈哈#define真好用
using namespace std;
int fastRead() {
    int f = 1, r = 0;
    char c = getchar();
    while (c > '9' || c < '0') {
        if (c == '-') {
            f = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        r = r * 10 + c - '0';
        c = getchar();
    }
    return f * r;
}
void fastWrite(int x) {
    if (x > 9) {
        fastWrite(x / 10);
    }
    putchar(x % 10 + '0');
}
int n, m, ans;
int f[110];
int getf(int x) {
    if (x == f[x])
        return x;
    else
        return f[x] = getf(f[x]);
}
signed main() {  //这里相应的也要改成signed
    n = fastRead(), m = fastRead();
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    ans = n;
    for (int i = 1; i <= m; i++) {
        int x = fastRead(), y = fastRead();
        int fx = getf(x), fy = getf(y);
        if (fx == fy) {
            ans++;
        } else {
            f[fx] = fy;
            ans--;
        }
    }
    if (ans & 1) {
        puts("Alice");
    } else {
        puts("Bob");
    }
    return 0;
}