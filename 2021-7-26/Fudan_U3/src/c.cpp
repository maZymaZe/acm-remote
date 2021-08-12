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
int a, b, c, n, m;
void process1() {
    for (int i = 1; i <= a - c; i++) {
        printf("%c", 'a');
    }
    for (int i = 1; i <= c; i++) {
        printf("%c", 'b');
    }
    for (int i = 1; i <= n - a; i++) {
        printf("%c", 'e');
    }
    puts("");
    for (int i = 1; i <= a - c; i++) {
        printf("%c", 'a');
    }
    for (int i = 1; i <= c; i++) {
        printf("%c", 'b');
    }
    for (int i = 1; i <= b - c; i++) {
        printf("%c", 'c');
    }
    for (int i = 1; i <= n - a - b + c; i++) {
        printf("%c", 'f');
    }
    puts("");
    for (int i = 1; i <= a - c; i++) {
        printf("%c", 'g');
    }
    for (int i = 1; i <= c; i++) {
        printf("%c", 'b');
    }
    for (int i = 1; i <= b - c; i++) {
        printf("%c", 'c');
    }
    for (int i = 1; i <= n - a - b + c; i++) {
        printf("%c", 'h');
    }
}
void process2() {
    for (int i = 1; i <= b - a; i++) {
        printf("%c", 'm');
    }
    for (int i = 1; i <= a; i++) {
        printf("%c", 'a');
    }
    for (int i = 1; i <= c - a; i++) {
        printf("%c", 'c');
    }
    for (int i = 1; i <= n - c - b + a; i++) {
        printf("%c", 'q');
    }
    puts("");
    for (int i = 1; i <= b - a; i++) {
        printf("%c", 'b');
    }
    for (int i = 1; i <= a; i++) {
        printf("%c", 'a');
    }
    for (int i = 1; i <= n - b; i++) {
        printf("%c", 'u');
    }
    puts("");
    for (int i = 1; i <= b - a; i++) {
        printf("%c", 'b');
    }
    for (int i = 1; i <= a; i++) {
        printf("%c", 'a');
    }
    for (int i = 1; i <= c - a; i++) {
        printf("%c", 'c');
    }
    for (int i = 1; i <= n - c - b + a; i++) {
        printf("%c", 'h');
    }
}
void process3() {
    for (int i = 1; i <= a - b; i++) {
        printf("%c", 'a');
    }
    for (int i = 1; i <= b; i++) {
        printf("%c", 'b');
    }
    for (int i = 1; i <= c - b; i++) {
        printf("%c", 'c');
    }
    for (int i = 1; i <= n - a - c + b; i++) {
        printf("%c", 'q');
    }
    puts("");
    for (int i = 1; i <= a - b; i++) {
        printf("%c", 'a');
    }
    for (int i = 1; i <= b; i++) {
        printf("%c", 'b');
    }
    for (int i = 1; i <= n - a; i++) {
        printf("%c", 'u');
    }
    puts("");
    for (int i = 1; i <= a - b; i++) {
        printf("%c", 'x');
    }
    for (int i = 1; i <= b; i++) {
        printf("%c", 'b');
    }
    for (int i = 1; i <= c - b; i++) {
        printf("%c", 'c');
    }
    for (int i = 1; i <= n - a - c + b; i++) {
        printf("%c", 'h');
    }
}
signed main() {  //这里相应的也要改成signed
    a = fastRead(), b = fastRead(), c = fastRead(), n = fastRead();
    m = min(a, b);
    m = min(m, c);
    if (a + b + c - 2 * m > n) {
        puts("NO");
        return 0;
    }

    if (c == m) {
        process1();
    } else if (a == m) {
        process2();
    } else {
        process3();
    }

    return 0;
}