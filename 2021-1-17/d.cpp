#include<cstdio>
int main(){
    long long t,n,m,k,tn,tk;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&m,&k);
        if(m==2||m==n){
            printf("yes\n");
            continue;
        }
        tk=m-1;
        tn=(n-tk*k+tk-2);
        tk--;
        
        //printf("%lld %lld\n",tk,tn);
        
        if(tn-tk<tk)tk=tn-tk;
        if(tk==0||tk==tn){
            printf("yes\n");
            continue;
        }else if(tk==1){
            if(tn%2==0)printf("no\n");
            else printf("yes\n");
            continue;
        }

        long long pre=1;
        int flag=0;
        while(pre<=tk){
            pre=pre*2;
            if((tn/pre-(tn-tk)/pre>(tk/pre))){
                flag=1;break;
            }
        }    
        if(flag==1)printf("no\n");
        else printf("yes\n");
        //
    }
    return 0;
}