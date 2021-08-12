#include<cstdio>
long long T,x;
int main(){
    scanf("%lld",&T);
    while (T--)
    {
        /* code */
        scanf("%lld",&x);
        x--;
        int ans=0;
        for(int i=0;i<63;i++){
            if(x&(1ll<<i))ans=i;
        }
        printf("%lld\n",(1ll<<ans)-1);
    }
    return 0;
}