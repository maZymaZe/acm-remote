#include<cstdio>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;
const long long MOD=1e9+7;
long long hs(long long x,long long y){
    return (x<<20)|y;
}
unordered_map<long long, long long> mp;
unordered_set<long long> s;
long long dfs(long long x,long long y){
    if(mp.count(hs(x,y)))return mp[hs(x,y)];
    if(!s.count(hs(x+1,y))||!s.count(hs(x,y+1)))return mp[hs(x,y)]=1;
    long long ans=0;
    ans+=dfs(x+1,y);
    ans%=MOD;
    ans+=dfs(x,y+1);
    ans%=MOD;
    return mp[hs(x,y)]=ans;
}

long long x,y,n;
int main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&x,&y);
        s.insert(hs(x,y));
    }
    long long ans=0;
    ans=dfs(1,1);
    printf("%lld\n", ans);
    return 0;
}