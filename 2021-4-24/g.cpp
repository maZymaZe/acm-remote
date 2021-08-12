#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
long long idsm[30],tgsm[30];
int n,t,cnt[30];
vector<int> pr;
vector<int> pos[30];
vector<long long> ps[30];
long long ans=1e18;
const int MAXSZ=6;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        cnt[t]++;
        pos[t].push_back(i);
        if()
    }
    for(int i=1;i<=MAXSZ;i++){
        pr.push_back(i);
    }
    do{
       /* long long tot=0,p=1;
        for(int i=0;i<MAXSZ;i++){
            tgsm[pr[i]]=(p+p+cnt[pr[i]]-1)*cnt[pr[i]]/2;
            p+=cnt[pr[i]];
        }
        for(int i=1;i<=MAXSZ;i++){
            tot+=abs(tgsm[i]-idsm[i]);
        }
        ans=min(tot/2,ans);
        for(int i=0;i<MAXSZ;i++)printf("%d ",pr[i]);printf("\n");*/
    }while(next_permutation(pr.begin(),pr.end()));
    printf("%lld\n", ans);
    return 0;
}