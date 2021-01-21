#include<cstdio>
const int NMAX=1e5+10;
int f[NMAX],cnt[NMAX],b[NMAX],n,m,a,bb,flag=0;
int ff(int x){
    return f[x]==x?x:f[x]=ff(f[x]);
}
int main(){
    scanf("%d",&n);
    for(int i=1; i <= n; i++)scanf("%d",&b[i]),f[i]=i;
    scanf("%d",&m);
    for(int i=1; i <= m; i++)scanf("%d%d",&a,&bb),f[ff(a)]=ff(bb);
    for(int i=1;i<=n;i++)cnt[ff(i)]+=b[i];
    for(int i=1;i<=n;i++)flag=(cnt[i]&1)|flag;
    printf(flag?"No\n":"Yes\n");
    return 0;
}