#include<cstdio>
const int NMAX=1e5+3;
int n,a[NMAX],b[NMAX],c[NMAX],ans[NMAX]={0},ret=0;
void dfs(int x){
    if(x>n)return;
    for(int i=b[x];i<=c[x];i++){
        if(x+i<=n&&ans[x]+a[x+i]>ans[x+i]){
            ans[x+i]=ans[x]+a[x+i];
            dfs(x+i);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);    
    }
    for(int i=1;i<=n;i++){
        if(a[i]>ans[i])ans[i]=a[i],dfs(i);
    }
    for(int i=1;i<=n;i++)if(ret<ans[i])ret=ans[i];
    printf("%d\n",ret);
    return 0;
}
