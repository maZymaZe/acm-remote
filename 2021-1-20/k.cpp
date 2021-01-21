#include<string>
#include<iostream>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
const int NMAX=1e5+10;
const int MAXLEN=1e6;
string s[NMAX];
int lens[NMAX],maxlen=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s[i];
        maxlen=max(maxlen,(int)s[i].length());        
    }
    bitset<MAXLEN> res;
    for(int i=1;i<=n;i++){
        bitset<MAXLEN> t(s[i]);
        res^=t;
    }
    
   
    return 0;
}