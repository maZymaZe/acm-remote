#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[105][105];
int main(){
	int t,n,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
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
		for(int i=1;i<=2*n-2;i++){
			for(int x=1;x<=n;x++){
				y=i+2-x;
				if(y>n||y<1) continue;
				
			}
		}
	}
	return 0;
}
