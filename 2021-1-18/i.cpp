#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int cal_price(int price) {
    if (price < 500)
        return price;
    else
        return (price - 100);
}

int main() {
    int arr[3], res = 0, mark = -1, sum = 0;
    scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
    sort(arr, arr + 3);
    for (int i = 2; i >= 0; i -= 1)
        if (arr[i] >= 500)
            res += (arr[i] - 100);
        else {
            mark = i;
            break;
        }
    for (int i = 0; i <= mark; i += 1)
        sum += arr[i];
    res += cal_price(sum);
    printf("%d\n", res);
    return 0;
}