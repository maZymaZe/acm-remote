#include<cstdio>
int n,a[100003];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        printf("%d ",i);
    }
    printf("%d\n",n);
    for(int i=0;i<n;i++){printf("1 ");}
    return 0;
}