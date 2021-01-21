#include<cstdio>
int a[400003],n;
void dfs(int x){
    if(x*2<=n)dfs(2*x);
    if(x<=n)printf("%d ",a[x]);
    if(x*2+1<=n)dfs(2*x+1);
}
int main(){
    scanf("%d",&n);
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i/2]+1;
    }
    dfs(1);
    return 0;
}