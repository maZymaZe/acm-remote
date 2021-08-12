#include <cstdio>
#include <unordered_map>
using namespace std;
const int NMAX = 8e5 + 310;
int n, a[NMAX], c[NMAX];
inline int lowbit(int x) {
    return (-x) & x;
}
void add(int x) {
    while (x < NMAX) {
        c[x]++;
        x += lowbit(x);
    }
}
int cal(int x) {
    int ret = 0;
    while (x) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
unordered_map<int, int> mp;
int main() {
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]] = i;
    }
    int pre = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (pre) {
            pre = 0;
        } else {
            if (mp[i] > mp[i + 1]) {
                a[mp[i]]++;
                pre = 1;
            }
        }
    }
    for (int i = n; i > 0; i--) {
        ans += cal(a[i] - 1);
        add(a[i]);
    }
    printf("%lld\n", ans);
    return 0;
}