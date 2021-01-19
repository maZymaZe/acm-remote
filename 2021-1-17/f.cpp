#include<cstdio>
#include<algorithm>
using namespace std;
struct pr{
    int x,p;
    bool operator<(const pr&y){
        return x<y.x;
    }
}a[2000002];
int n,p,q,b,c,t,m;
int main(){
    scanf("%d%d%d%d%d%d%d",&n,&p,&q,&m,&b,&c,&t);
    for(int i=1;i<=m;i++)scanf("%d",&a[i].x),a[i].p=i;
    int tn=max(m,min(2000000,n));
    for(int i=m+1;i<=tn;i++)a[i].x=((long long)a[i-1].x*b+c)%t+1,a[i].p=i;
    sort(a+1,a+1+tn);
    for(int i=1;i<tn;i++){
        if((long long)a[i].x*q>=(long long)a[i+1].x*p){
          //  printf("%d %d\n",a[i].x,a[i+1].x);
            int u=a[i].p,v=a[i+1].p;
            if(u>v)swap(u,v);
            printf("%d %d",u,v);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}