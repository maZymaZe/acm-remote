#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int N,G,P[33],tot,w[33],ans1,lt=0,cs[33],ans2;
int ans[2000000][22];
void dfs(int p,int pre){
    if(p==ans1+1){
        int sc=0;
        for(int i=1;i<=ans1;i++){
            sc+=P[cs[i]];
        }
        if(sc*100/tot>=G){
            ans2++;
            ans[ans2][0]=100*sc/tot;
            for(int i=1;i<=ans1;i++){
                ans[ans2][i]=cs[i];
            }
        }
        return;
    }
    for(int i=pre+1;i<=N;i++){
        cs[p]=i;
        dfs(p+1,i);
    }
}
int main(){
    scanf("%d%d",&N,&G);
    for(int i=1;i<=N;i++){
        scanf("%d",&P[i]);
        w[i]=P[i];
        tot+=P[i];
    }
    sort(w+1,w+1+N);
    for(int i=N;i>0;i--){
        lt+=w[i];
        if(lt*100/tot>=G){
            ans1=N-i+1;
            break;
        }
    }
    dfs(1,0);
    printf("%d %d\n",ans1,ans2);
    for(int i=1;i<=ans2;i++){
        printf("%d ",ans[i][0]);
        for(int j=1;j<ans1;j++)printf("%d ",ans[i][j]);
        printf("%d\n",ans[i][ans1]);
    }
    return 0;
}