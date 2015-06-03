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
int prm[100000009];

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
vector<int> vec;
void seive_fun(ull sz) {
	int i,j,k,limit;
	//init();
	prm[0]=1;
	prm[1]=1;
	limit=sqrt(sz);
	for(i=2;i<=limit;i++) {
		if(prm[i]==0) {
			vec.push_back(i);
			k=sz/i;
			for(j=2;j<=k;j++)
				prm[i*j]=1;
		}
	}
}
int main() {
	ull limit,i,j,temp,num,sz=100000000,T;
	sc("%llu",&T);
	seive_fun(sz);
	while(T--) {
		sc("%lld",&num);
		pf("%d\n",vec.at(num-1));
	}
	return 0;
}
