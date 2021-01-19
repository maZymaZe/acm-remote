#include <iostream>
using namespace std;
int store[31];
void preprocess(){
    for(int i = 0; i <= 30; i++){
        store[i] = (i + 1)/2;
    }
}
int main(){
    int w, h;
    preprocess();
    cin >> w >> h;
    if(h < store[w]) cout << h;
    else cout << store[w];
    return 0;
}