#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int t;
int h,l,w;
double hd,ld,wd,le,ri,mid,r,width,b,c,x;

inline double disquare(double x1,double y1,double x2,double y2){
	double ans;
	ans=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return ans;
}
inline double distance(double x1,double y1,double x2,double y2){
	double ans;
	ans=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	ans=sqrt(ans);
	return ans;
}
bool check(double r,double x,double y){
	if(fabs(distance(r,r,x,y)-r)<1e9) return 1;
	return 0;
}

int main(){
	scanf("%d",&t);
	for(int o=1;o<=t;o++){
		scanf("%d%d%d",&h,&l,&w);
		hd=(double)h;
		ld=(double)l;
		wd=(double)w;
		
		r=ld*wd*(sqrt(hd*hd+wd*wd/4.0)+hd+wd/2.0)/(2.0*hd);
		r=r/(2.0*(sqrt(hd*hd+wd*wd/4.0) + hd));
		
		width=r*(1.0+hd/sqrt(hd*hd+wd*wd/4.0));
		if(width > wd/2.0){
			
			b=-(wd+2*hd-2*ld);
			c=(hd-ld)*(hd-ld)+wd*wd/4.0;
			x=(-b-sqrt(b*b-4.0*c))/2.0;
			
			
			/*bx=wd*ld/(hd*2.0)+(hd-ld)*wd/(hd*2.0);
			by=hd-ld;
			le=0;
			ri=wd*ld/(hd*2.0);
		    while(fabs(le-ri)>1e8){
		        mid=(le+ri)/2;
		        if(check(mid,bx,by)){
		    	    le=mid;
			    }else{
				    ri=mid;
			    }
		    }*/
		    r=max(r,x);
		}
		
		printf("%.10lf\n",r);
		
		
	}
	return 0;
}