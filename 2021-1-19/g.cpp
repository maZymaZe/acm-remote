#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[103],b[103],dp[2][5003];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    dp[0][0]=0,dp[1][0]=0;
    for(int i=1;i<=n;i++){
        dp[0][i]=0;
        for(int j=1;j<=m;j++){
            if(i-a[j]>=0&&dp[1][i-a[j]]==0){
                dp[0][i]=1;
                break;
            }
        }
        dp[1][i]=0; 
        for(int j=1;j<=m;j++){
            if(i-b[j]>=0&&dp[0][i-b[j]]==0){
                dp[1][i]=1;
                break;
            }
        } 
    }
    if(dp[0][n])printf("Long Long nb!\n");
    else printf("Mao Mao nb!\n");
    return 0;
}
