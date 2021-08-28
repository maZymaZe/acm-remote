#include <algorithm>
#include <cstdio>
using namespace std;
long long a, b, T;
int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld", &a, &b);
        if (a > b) {
            swap(a, b);
        }
        long long d = b * b - a * a, tg = a * b * 2 - a * a * 2;
        if (d == 0) {
            printf("Yes\n");
            continue;
        }
        while ((d & 1) == 0)
            d >>= 1;
        if (tg % d == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}