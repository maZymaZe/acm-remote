#include <cstring>
#include <iostream>

using namespace std;

#define mod 1000000007

char in[100010];
int n;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", in);
        bool flag = false;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (in[i] == in[0])
                ans = 2 * ans % mod;
            else
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}