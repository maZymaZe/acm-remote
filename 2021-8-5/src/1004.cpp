#include <cstdio>
const int SZM = 1e6 + 10;
int T, n, k, elp[SZM], dv[SZM];
int main() {
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d", &n, &k);
        int c = n / 2, p = 0;
        for (int i = 1; i <= c; i += 1) {
            elp[++p] = n;
            elp[++p] = i;
            for (int j = 1; j < c; j++) {
                elp[++p] = (i + j + n - 2) % (n - 1) + 1;
                elp[++p] = (i - j + n - 2) % (n - 1) + 1;
            }
            elp[++p] = i + c;
        }
        elp[++p] = n;
        for (int i = 1; i <= k; i++) {
            scanf("%d", &dv[i]);
        }
        int tot = 1;
        printf("Case #%d:\n", TT);
        for (int i = 1; i <= k; i++) {
            while (dv[i]) {
                printf("%d ", elp[tot]);
                dv[i]--;
                tot++;
            }
            printf("%d\n", elp[tot]);
        }
    }
    return 0;
}