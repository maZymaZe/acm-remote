#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int dp[40],ans;
int xx, yy;
bool ck(int x){
    for(int i = 1; i <= xx; i++){
        dp[i]=yy;
    }
    for(int i =x;i>=1;i--){
        int ff=0;
        for(int j=1;j<=xx-i+1; j++){
            if(dp[j]>=i){
                int f=0;
                for(int k=0;k<i;k++){
                    if(dp[j+k]<i){
                        f=1;
                        break;
                    }
                }
                if(!f){
                    for(int k=0;k<i;k++){
                        dp[j+k]-=i;
                    }
                    ff=1;
                    break;
                }
            }
        }
        if(!ff)return false;
    }
    return true;
}
int main() {
 
    scanf("%d%d", &xx, &yy);
    for(int j=12;j>=1;j--) {
        if(ck(j)){
            printf("%d\n", j);
            return 0;
        }
    }
    
    return 0;
}