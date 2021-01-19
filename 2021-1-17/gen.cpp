#include<cstdio>
#include<cstdlib>
#include<ctime>
int main(){
    int n,k,g;
    srand(time(NULL));
    scanf("%d",&n);
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        k=rand()%10;
        g=rand()%10+10;
        if(g-k<k)k=g-k;
        printf("%d %d\n",k,g);
    }
    return 0;
}