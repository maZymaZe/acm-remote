#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
string str;
ll str2num(string str, int m){
    int n = str.length();
    ll res = 0;
    if(n > 10) return -1;
    for(int i = 0; i < n; i++){
        res *= 10;
        res += (str[i] - '0');
    }
    if(res <= m) return res;
    else return -1;
}
void uncompress(vector<int> start, vector<int> len, vector<ll> store){
    int i, pos = 0, n = start.size();
    for(i = 0; i < n; i++){
        cout << str.substr(pos, start[i]-pos);
        cout << string(store[i], str[start[i] + len[i]]);
        pos = start[i] + len[i] + 1;
    }
    if(pos != str.length() + 1)
        cout << str.substr(pos, str.length() + 1 - pos)<<endl;
}
void sol(){
    int t, i, j, k, m, f, sum;
    char ch;
    cin >> t;
    for(k = 0; k < t; k++){
        f = 0;
        sum = 0;
        vector<int> start, len;
        vector<ll> store;
        cin >> str;
        cin >> m;
        for(i = 0; i < str.length(); i++){
            ch = str[i];
            if(ch >= '0' && ch <= '9'){
                j = i;
                while(ch >= '0' && ch <= '9'){
                    j ++;
                    ch = str[j];
                }
                start.push_back(i);
                len.push_back(j - i);
                int tmp = str2num(str.substr(i, j - i), m);
                if(tmp == -1) {f = 1; break;}
                store.push_back(tmp);
                i = j;
                i--;
                sum += tmp - 1;
            }
            else sum++;
        }
        if(sum > m) f = 1;
        if(f == 1) cout << "unfeasible" << endl;
        else {
            uncompress(start, len, store);
        }
    }
    

}
int main(){
    ios::sync_with_stdio(0);
    sol();
    return 0;
}