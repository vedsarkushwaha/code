#include<cstdio>
#include<iostream>
#include<cmath>
#define pi 3.141592653589793
using namespace std;
void calc_bisector(double x1,double y1,double x2,double y2,double *xp,double *yp,double *m) {
	if (y2-y1)
		*m=(x1-x2)/(y2-y1);
	*xp=(x1+x2)/2;
	*yp=(y1+y2)/2;
}
int main() {
	double r,x,y,x1,x2,x3,y1,y2,y3,m1,m2,xp,yp,xq,yq,a,b,c,d,e,f;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF) {
		calc_bisector(x1,y1,x2,y2,&xp,&yp,&m1);
		calc_bisector(x3,y3,x2,y2,&xq,&yq,&m2);
		if(!(y2-y1)) {
			x=xp;
			y=m2*x-m2*xq+yq;
		}
		else if(!(y2-y3)) {
			x=xq;
			y=m1*x-m1*xp+yp;
		}
		else {
			x=(yq-yp-m2*xq+m1*xp)/(m1-m2);
			y=m1*x-m1*xp+yp;
		}
		r=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
		printf("%0.2lf\n",2*pi*r);
	}
	return 0;
}
