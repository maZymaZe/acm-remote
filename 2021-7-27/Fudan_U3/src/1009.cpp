#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[105][105];
vector<int> va[105][105],vb[105][105];
int main(){
    int t,n,x,y;
     int ta,tb;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                va[i][j].clear();vb[i][j].clear();
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&b[i][j]);
            }
        }
        va[1][1].push_back(a[1][1]);vb[1][1].push_back(b[1][1]);
        for(int i=1;i<=2*n-2;i++){
            for(int x=1;x<=n;x++){
                y=i+2-x;
                if(y>n||y<1) continue;
                int u=0,v=0,x1,y1,x2,y2,cnt=-1;
                x1=x-1;y1=y;x2=x;y2=y-1;
                while(u<va[x1][y1].size()&&v<va[x2][y2].size()){
                    if(va[x1][y1][u]>va[x2][y2][v]||va[x1][y1][u]==va[x2][y2][v]&&vb[x1][y1][u]>vb[x2][y2][v]){
                        ta=va[x1][y1][u];tb=vb[x1][y1][u];
                        u++;
                    }
                    else{
                        ta=va[x2][y2][v];tb=vb[x2][y2][v];
                        v++;
                    }
                    if(cnt==-1||tb>vb[x][y][cnt]){
                        cnt++;
                        va[x][y].push_back(ta);
                        vb[x][y].push_back(tb);
                    }
                }
                while(u<va[x1][y1].size()){
                    ta=va[x1][y1][u];tb=vb[x1][y1][u];
                    u++;
                    if(cnt==-1||tb>vb[x][y][cnt]){
                        cnt++;
                        va[x][y].push_back(ta);
                        vb[x][y].push_back(tb);
                    }
                }
                while(v<va[x2][y2].size()){
                    ta=va[x2][y2][v];tb=vb[x2][y2][v];
                    v++;
                    if(cnt==-1||tb>vb[x][y][cnt]){
                        cnt++;
                        va[x][y].push_back(ta);
                        vb[x][y].push_back(tb);
                    }
                }
                for(int j=0;j<va[x][y].size();j++){
                    va[x][y][j]+=a[x][y];
                    vb[x][y][j]+=b[x][y];
                }
            }
        }
        long long ans=0;
        for(int i=0;i<va[n][n].size();i++){
            ans=max(ans,(long long)va[n][n][i]*vb[n][n][i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}