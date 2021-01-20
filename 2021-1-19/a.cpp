#include<cstdio>
#include<list>
#include<algorithm>
using namespace std;
int n,c,ans=0,a[1003];
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    list<int> ls;
    for(int i=1;i<=n;i++){
        ls.push_back(a[i]);
        if(ls.size()==3){
            if(ls.back()-ls.front()<=c)ans++,ls.clear();
            else ls.pop_front();
        }
    }
    printf("%d\n",ans);
    return 0;
}