#include<cstdio>
using namespace std;
const int NMAX=2e5+10;
int t,n,dp[NMAX][2],a[NMAX],ps=1;
long long ansp,ansn,cn,cp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        if(t>0)a[i]=1;
        else a[i]=-1;
    }
    cp=0;cn=0;
    for(int i=1;i<=n;i++){
        ps*=a[i];
        if(ps>0){
            ansp+=cp;
            ansn+=cn;
        }else{
            ansn+=cp;
            ansp+=cn;
        }
        if(ps>0)cp++,ansp++;
        else cn++,ansn++;
    }
    printf("%lld %lld\n",ansn,ansp);
    return 0;
}