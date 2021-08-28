#include <cstdio>
int tmp[5002];
void rec(int* st, int sz) {
    if (sz <= 1)
        return;
    int mid = sz >> 1;
    printf("%d %d\n", st[mid], st[mid + 1]);
    rec(st, mid);
    rec(st + mid, sz - mid);
}
void div(int l, int r) {
    int len = (r - l) / 3;
    if (!len)
        return;
    printf("%d %d\n", l + 2 * len, r);
    div(l + len * 2, r - 1);
    printf("%d %d\n", l + len - 1, r);

    for (int i = 1; i <= len; i++)
        tmp[i] = i + l - 1;
    rec(tmp, len);
    for (int i = 1; i <= len; i++)
        tmp[i] = i + l + len - 1;
    tmp[len + 1] = r;
    rec(tmp, len + 1);
}
int main() {
    int n = 3280;
    printf("%d\n", n);
    div(1, n);
    return 0;
}