#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <string>
using namespace std;
list<int> ls;
string s;
int n, cnt[10], t[10], tot = 0, l, w,nw[10];
int main() {
    cin >> s;
    for (int i = 1; i < 10; i++) {
        scanf("%d", &cnt[i]);
        tot += cnt[i];
    }
    l = s.size();
    for (int i = 0; i < l; i++) {
        ls.push_back(s[i] - '0');
        nw[s[i] - '0']++;
    }
    w = l - tot;
    for (int k = 0; k < w; k++) {
        for (int i = 9; i > 0; i--) {
            if(cnt[i]==nw[i])continue;
            for (int j = 1; j < 10; j++)
                t[j] = cnt[j];
            auto it = ls.begin();
            while (*it != i) {
                if (t[*it])
                    t[*it]--, ++it;
                else
                    break;
            }
            if (*it == i) {             
                while (ls.front() != i) {
                    cnt[ls.front()]--;
                    nw[ls.front()]--;
                    ls.pop_front();
                    
                }
                break;
            }
        }
        printf("%d", ls.front());
        nw[ls.front()]--;
        ls.pop_front();
    }
    return 0;
}