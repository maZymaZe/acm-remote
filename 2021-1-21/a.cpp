#include <cstdio>
#include <queue>
using namespace std;
const int NMAX = 5e5 + 10;
queue<int> p, q;
int n, a[NMAX],ql,pl,qm,pm,sp,fail=0,now;
void func(int cur){
    for(int i=cur;i<=n;i++){
        if(a[i]<qm){
            
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sp=n;
    for(int i = 1; i <= n; i++){
        if(a[i]!=i){
            sp=i-1;
        }
    }
    int pre=0;
    for (int i = sp+1; i <= n; i++) {
        if(a[i]==sp+1){
            q.push(sp+1);
            ql=i;
            qm=sp+1;
            now=i+1;
            break;
        }else{
            if(a[i]>pre){
                p.push(a[i]);
                pre=a[i];
                pl=i;
                pm=a[i];
            }else{
                fail=1;
                break;
            }
        }
        if(fail==1){
            printf("-1\n");
            return 0;
        }
        func(now);
    }
    
    return 0;
}