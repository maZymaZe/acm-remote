#include <cstring>
#include <iostream>

using namespace std;

char in[100010];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", in);
        int len = strlen(in);
        bool flag = false;
        for (int i = 0; i < len; i++) {
            if (in[i] == '1' && in[i + 1] == '1' && in[i + 2] == '4' &&
                in[i + 3] == '5' && in[i + 4] == '1' && in[i + 5] == '4')
                flag = true;
        }
        if (flag)
            puts("AAAAAA");
        else
            puts("Abuchulaile");
    }
    return 0;
}