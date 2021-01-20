#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<string>

using namespace std;
int n,m,tot,nb[10004],mi[10004],stat,vis[10004];
string s;
int main(){
    cin>>tot;
    for(int i=0;i<tot;i++)cin>>nb[i];
    sort(nb,nb+tot);
    stat=1;
    int guessn,tl,tr;
    while(1){
        if(stat==1){
            int get0=0;
            for(int i=2;i<tot;i++){
                cout<<"r "<<nb[0]<<" "<<nb[i]<<endl;
                cin>>s;
                if(s[0]=='y'){
                    get0=i;break;
                }
            }
            if(get0==0){
                cout<<"!"<<nb[0]<<endl;
                break;
            }
            guessn=get0;
            stat++;
        }
        else if(stat==2){
            
        }
        else if(stat==5){
            for(int i=tl;i<=tr;i++){
                if(!vis[i]){
                    int flag=0;
                    for(int j=tl+1;j<=tr;j++){
                        
                    }
                }
            }
        }
    }


}
