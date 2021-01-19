#include<cstdio>
int n;
long double t,ans,p[100];
int main(){
    scanf("%d",&n);
    p[0]=1;
    for(int i=1;i<=n;i++)p[i]=p[i-1]*1.1;
    t=n*200;
    ans=t;
    for(int i=1;i<=n;i++){
        t-=100;
        if(t*p[i]>ans)ans=t*p[i];
    }
    printf("%.12lf",(double)ans);
    return 0;
}