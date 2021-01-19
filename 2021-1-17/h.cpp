#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int NMAX=500050;
int n,f[NMAX],ord[NMAX],h[NMAX],m[NMAX],l,t,ep=0;
int s[NMAX],sp,ans=0;
struct EDGE{
    int u,v,nx;
}e[NMAX];
void dfs(int x){
    if(h[x]==0){
        sp=0;
        for(int i=1;i<=l;i++){
            if(ord[m[i]]){
                if(sp==0)s[++sp]=ord[m[i]];
                else if(ord[m[i]]>s[sp])s[++sp]=ord[m[i]];
                else if(ord[m[i]]==s[sp]);
                else if(ord[m[i]]<s[1])s[1]=ord[m[i]];
                else{
                    int p=lower_bound(s+1,s+1+sp,ord[m[i]])-s;
                    s[p]=ord[m[i]];
                }
            }
        }
        if(sp>ans)ans=sp;

        return;
    }
    for(int i=h[x];i;i=e[i].nx){
        ord[e[i].v]=ord[x]+1;
        dfs(e[i].v);
        ord[e[i].v]=0;
    }
}
int main(){
    scanf("%d%d",&n,&l);
    for(int i=2;i<=n;i++){
        scanf("%d",&t);
        e[++ep]={t,i,h[t]};
        h[t]=ep;
    }
    for(int i=1;i<=l;i++)scanf("%d",&m[i]);
    ord[1]=1;
    dfs(1);
    printf("%d",ans);
    return 0;
}