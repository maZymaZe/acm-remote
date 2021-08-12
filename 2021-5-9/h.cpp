#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;
const int NMAX=4003;
int T,n,m,a[NMAX],k;
deque<int> pos1,val1,pos2,val2;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        pos1.clear(),pos2.clear(),val1.clear(),val2.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        if(k>=m-1){
            int ans=a[1];
            for(int i=1;i<=m;i++)ans=max(ans,a[i]);
            for(int i=n;i>=n-m+1;i--)ans=max(ans,a[i]);
            printf("%d\n",ans);
            continue;
        }
        int sldlen1=m-k; 


    }
}