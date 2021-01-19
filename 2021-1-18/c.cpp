#include <iostream>
using namespace std;
void sol(){
    long long i, t, n, k, res;
    cin >> t;
    for(i = 0; i < t; i++){
        cin >> n >> k;
        res = (k + 1)*(((n + 2)*(n + 1) / 2) % 1000000007);
        res %= 1000000007;
        cout << res << endl;
    }
}
int main(){
    sol();
    return 0;
}