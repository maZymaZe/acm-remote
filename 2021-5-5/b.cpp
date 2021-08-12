#include<string>
#include<iostream>
using namespace std;
int n,k;
string s;
int main(){
    cin>>n>>k>>s;
    if(n==1){
        if(k)s[0]='0';
        cout<<s<<endl;
        return 0;
    }
    if(k&&s[0]!='1'){
        s[0]='1';
        k--;
    }
    for(int i=1;i<n&&k;i++){
        if(s[i]!='0'){
            s[i]='0';
            k--;
        }
    }
    cout<<s<<endl;
    return 0;
}