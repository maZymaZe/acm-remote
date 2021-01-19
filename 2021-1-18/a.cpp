#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T,P,E[12],D[102],S[102],dp[12][102][102],ans=0;

int main(){
    scanf("%d%d",&T,&P);
    for(int i=1;i<=T;i++)scanf("%d",&E[i]);
    for(int i=1;i<=P;i++)scanf("%d",&D[i]);
    for(int i=1;i<=P;i++)scanf("%d",&S[i]);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=P;i++){
        for(int j=1;j<=T;j++){
            for(int k=0;k<=E[j];k++){
                dp[j][k][i]=dp[j][k][i-1];
                if(k!=0)dp[j][k][i]=max(dp[j][k][i],dp[j][k-1][i]);
                if(j>1&&k==E[j])dp[j][k][i]=max(dp[j][k][i],dp[j-1][E[j-1]][i]);
                if(k+D[i]<=E[j])dp[j][k][i]=max(dp[j][k][i],dp[j][k+D[i]][i-1]+S[i]);
            }
        }
    }
    for(int j=T;j>0;j--){
        for(int k=E[j];k>=0;k--){
            if(ans<dp[j][k][P])ans=dp[j][k][P];
        }
    }
    printf("%d\n",ans);
    return 0;
}