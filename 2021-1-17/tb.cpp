#include<cstdio>
int main(){
    long long t,n,m,k,tn,tk;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&tk,&tn);
        if(tk==0||tk==tn){
            printf("yes\n");
            continue;
        }
        //printf("%lld %lld\n",tk,tn);
        long long pre=1;
        for(int i=tn-tk+1;i<=tn;i++)pre*=i;
        for(int i=1;i<=tk;i++)pre/=i;
        if(pre%2==0)printf("no\n");
        else printf("yes\n");
        //
    }
}