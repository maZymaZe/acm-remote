#include<cstdio>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==1)printf("Yes\n");
    else if(k>3){
        printf("No\n");
    }else if(k==3){
        if(n==4)printf("Yes\n");
        else printf("No\n");
    }else if(k==2){
        if(n%2==0)printf("Yes\n");
        else printf("No\n");
    }else printf("Yes\n");
    return 0;
}