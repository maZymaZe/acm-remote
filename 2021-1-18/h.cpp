#include <algorithm>
#include <cmath>
#include <cstdio>
int n, k, c, due, sum;
int comb[24], pts[24], ptss[24], res[200000][20];
bool comp(const int& left, const int& right) {
    return left > right;
}

void find_prime(int ns, int ks) {
    for (int i = 0; i <= ns - ks; i += 1) {
        comb[k - ks] = i + n - ns;
        if (ks > 1)
            find_prime(ns - i - 1, ks - 1);
        else {
            int sub_sum = 0;
            for (int j = 0; j < k; j += 1)
                sub_sum += pts[comb[j]];
            if (sub_sum >= due) {
                for (int j = 0; j < k; j += 1)
                    res[c][j + 1] = comb[j] + 1;
                res[c++][0] = sub_sum * 100 / sum;
            }
        }
    }
}

int main() {
    int g = 0, ex_sum;
    scanf("%d%d", &n, &g);
    for (int i = 0; i < n; i += 1)
        scanf("%d", &pts[i]), sum += (ptss[i] = pts[i]);
    std::sort(ptss, ptss + n, comp);
    due = ceil(g * sum / 100.0);
    ex_sum = ptss[k++];
    while (ex_sum < due)
        ex_sum += ptss[k++];

    find_prime(n, k);
    printf("%d %d\n", k, c);
    for (int i = 0; i < c; i += 1) {
        for (int j = 0; j < k + 1; j += 1) {
            printf("%d", res[i][j]);
            if (j < k)
                printf(" ");
        }
        if (i < c - 1)
            printf("\n");
    }
    return 0;
}