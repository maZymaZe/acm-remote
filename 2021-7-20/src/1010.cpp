#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int NMAX = 1e5 + 10;
int T, n, m, k = 313, a[NMAX], num[NMAX], sum[NMAX], ans[NMAX];
struct QUE {
    int l, r, L, R, id;
} q[NMAX];
bool cmp(const QUE&a, const QUE&b){
    if(a.l/k==b.l/k){
        if((a.l/k)&1){
            return a.r<b.r;
        }else return a.r>b.r;
    }
    return a.l/k<b.l/k;
}
void add(int x){
    num[x]++;
    if(num[x]==1)sum[x/k]++;
}
void del(int x){
    num[x]--;
    if(num[x]==0)sum[x/k]--;
}
int cal(int x){
    int aans=0,t=x/k;
    for(int i =0;i<t; i++){
        aans+=sum[i];
    }
    for(int i=t*k;i<=x;i++){
        aans+=(num[i]>0);
    }
    return aans;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(num, 0, sizeof(num));
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d%d", &q[i].l, &q[i].L, &q[i].r, &q[i].R);
            q[i].id = i;
        }
        sort(q+1,q+m+1,cmp);
        int pl=q[1].l,pr = q[1].r;
        for(int i=pl;i<=pr;i++){
            add(a[i]);
        }
        ans[q[1].id]=cal(q[1].R)-cal(q[1].L-1);
        for(int i=2;i<=m;i++){
            while(pl>q[i].l){
                pl--,add(a[pl]);
            }
            while(pl<q[i].l){
                del(a[pl]),++pl;
            }
            while(pr>q[i].r){
                del(a[pr]),--pr;
            }
            while(pr<q[i].r){
                ++pr,add(a[pr]);
            }
            ans[q[i].id]=cal(q[i].R)-cal(q[i].L-1);
        }
        for(int i=1;i<=m; i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}