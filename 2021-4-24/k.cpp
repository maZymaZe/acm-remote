#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    cout<<max(0,n-(k1-1)*a1-(k2-1)*a2)<<' ';
    if(k1>k2)swap(k1,k2),swap(a1,a2);
    if(n<=a1*k1){
        cout<<n/k1<<endl;
    }else{
        cout<<a1+min(a2,(n-a1*k1)/k2)<<endl;
    }
    return 0;
}