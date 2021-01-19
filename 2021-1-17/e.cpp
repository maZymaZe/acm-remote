#include<cstdio>
#include<algorithm>
using namespace std;
int n,hp[10],atk[10],tot=0,nhp[10],ord[10],cc=1;
double ends,l[10];
void dfs(int t,double ps){
    if(t==n+1){
        for(int i=1;i<=n;i++)if(nhp[i]>0)l[i]+=ps;
        return;
    }
    if(nhp[ord[t]]<=0)dfs(t+1,ps);
    else{
        int c=0;
        for(int i=1;i<=n;i++){
            if(i!=ord[t]&&nhp[i]>0)c++;
        }
        if(c==0){
            dfs(t+1,ps);
            return;
        }
        double p=ps/c;
        for(int i=1;i<=n;i++){
            if(i!=ord[t]&&nhp[i]>0){
                nhp[i]-=atk[ord[t]];
                nhp[ord[t]]-=atk[i];
                dfs(t+1,p);
                nhp[i]+=atk[ord[t]];
                nhp[ord[t]]+=atk[i];
            }
        }

    }
    
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&atk[i],&hp[i]);
    }
    for(int i=1;i<=n;i++)cc*=i;
    for(int i=1;i<=n;i++)ord[i]=i;
    for(int i=0;i<cc;i++){
        for(int j=1;j<=n;j++)nhp[j]=hp[j];
        dfs(1,100000);
        next_permutation(ord+1,ord+1+n);
    }
    ends=(double)cc*100000;
    for(int i=1;i<=n;i++){
        printf("%.12lf\n",l[i]/ends);
    }
    return 0;
}