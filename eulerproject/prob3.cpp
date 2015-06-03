#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#define f(i,m,n) for(i=0;i<n;i++)
#define ull unsigned long long
#define sc scanf
#define pf printf
using namespace std;
int prm[1000000000];

void init(ull *a,int len) {
	int i;
	f(i,0,len)
		a[i]=0;
}
void print(ull *a,ull len) {
	ull i;
	f(i,0,len)
		printf("%llu",a[i]);
}
void seive_fun(ull sz) {
	int i,j,k,limit;
	//init();
	prm[0]=1;
	prm[1]=1;
	limit=sqrt(sz);
	for(i=2;i<=limit;i++) {
		if(prm[i]==0) {
			k=sz/i;
			for(j=2;j<=k;j++)
				prm[i*j]=1;
		}
	}
}
int main() {
	ull limit,i,j,temp,num,sz,T;
	sc("%llu",&T);
	while(T--) {
		sc("%lld",&num);
		sz=sqrt(num);
		//pf("%llu ",limit);
		seive_fun(sz);
	
		f(i,2,sz+1) {
			if((prm[i]==0)&&(num%i==0)) {
				//pf("W %llu W",i);
				temp=i;
				num/=i;
				while(num%i==0) {num/=i;}
				//pf("%lld ",temp);
			}
		}
		if(num==1)
			pf("%llu",temp);
		else
			pf("%llu",num);
	}
	return 0;
}
