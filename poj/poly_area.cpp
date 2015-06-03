#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main() {
	int a,t,i;
	char str[1000002];
	int x1,x2,y1,y2;
	long long area;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",str);
		area=0;i=0;x1=0;x2=0;y1=0;y2=0;
		while(1) {
			a=str[i++] - '0';
			if(a==5)
				break;
			else if(a==8) {
				y2=y1+1;
				x2=x1;
			}
			else if(a==2) {
				y2=y1-1;
				x2=x1;
			}
			else if(a==6) {
				y2=y1;
				x2=x1-1;
			}
			else if(a==4) {
				y2=y1;
				x2=x1+1;
			}
			else if(a==9) {
				y2=y1+1;
				x2=x1-1;
			}
			else if(a==7) {
				y2=y1+1;
				x2=x1+1;
			}
			else if(a==3) {
				y2=y1-1;
				x2=x1-1;
			}
			else if(a==1) {
				y2=y1-1;
				x2=x1+1;
			}
			area+=(long long)((x1*y2)-(x2*y1));
			x1=x2;y1=y2;
		}
		if(area<0)
			area=-1*area;
		if(area%2==0)
			printf("%llu\n",area/2);
		else
			printf("%0.1lf\n",double(area)/2);
	}
	return 0;
}
