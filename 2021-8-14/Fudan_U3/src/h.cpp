#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int power = 3;
    int l = 0;
    n--;
    while (n >= power) {
        n -= power;
        power *= 3;
        l++;
    }
    for (int i = l; i >= 0; i--) {
        power /= 3;
        printf("%c", "236"[n / power]);
        n -= n / power * power;
    }
    return 0;
}