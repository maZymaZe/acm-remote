#include<cstdio>
int p[50]={0},cnt=0,t,d;
int main(){
    for(int i=1;i<=14;i++)scanf("%d",&t),p[t]++;
    for(int i=1;i<=13;i++)cnt+=(!p[i]);
    t=0;
    for(int i=1;i<=13;i++)t+=p[i];
    if(t+cnt==13)cnt++;
    printf("%d\n",cnt);
    return 0;
}