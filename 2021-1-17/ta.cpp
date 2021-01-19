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
        while(pre<=tk){
            pre*=2;
        }    
        if(tn/pre!=(tn-tk+1)/pre||(tn-tk+1)%pre==0)printf("no\n");
        else if(tn%2==0&&(tn-tk+1)%2==0)printf("no\n");
        else printf("yes\n");
        //
    }
    return 0;
}