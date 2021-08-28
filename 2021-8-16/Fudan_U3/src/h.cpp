#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                cnt++;
        if (cnt & 1)
            printf("1");
        else
            printf("0");
    }
    puts("");
    return 0;
}