#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=2e5+10;
int n,t,l[NMAX],r[NMAX],cnt=0,price[NMAX],p=0;
int main(){
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
        if(r[i]>l[i])cnt++;
        else price[++p]=(l[i]-r[i])/2;
    }
    sort(price+1,price+1+p);
    int nd=n/2+1,pp=1;
    while(cnt<nd&&pp<=p&&t>=price[pp]){
        cnt++;
        t-=price[pp];
        pp++;
    }
    if(cnt>=nd)printf("Make Byteland Great Again!\n");
    else printf("Fake Polls!\n");
    return 0;
}