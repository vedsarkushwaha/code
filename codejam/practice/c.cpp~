#include<stdio.h>

int a[301],h,i,n,t,s;

int main() {
	a[0]=2;a[1]=6;
	for(i=2;i<301;i++)
		a[i]=(a[i-1]*6-a[i-2]*4+4000)%1000;
	for(i=0;i<301;i++) {printf("%d ",a[i]);}
	scanf("%d",&t);
	for(h=0;h<t;h++)
	{
		scanf("%d",&n);
		if(n==2)s=28;
		else s=a[n%100+100];
		printf("Case #%d: %03d\n",h+1,s-1);
	}
	return 0;
}
