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
#define f(i,m,n) for(i=m;i<n;i++)
#define ull unsigned long long
#define sc scanf
#define pf printf
using namespace std;

void init(ull *a,int len) {
	int i;
	f(i,0,len)
		a[i]=0;
}
void print(ull *a,int len) {
	int i;
	f(i,0,len)
		printf("%llu",a[i]);
}
ull opr(ull n) {
	int cnt=0;
	ull tn;
	tn=n;
	while(tn!=0) {
		tn=tn>>1;
		cnt++;
	}
	if((n&(n-1))==0) {
		if((cnt&1)==0)
			return 1;
		else
			return 2;
	}
	else {
		return (n&(((ull)1<<(cnt-1))-1));
	}
}	
int main() {
	ull T,N;
	int cnt,temp;
	sc("%llu",&T);
	//pf("%lu",sizeof(ull));
	while(T--) {
		cnt=0;
		sc("%llu",&N);
		while(N!=1) {
			N=opr(N);
			cnt++;
		}
		if((cnt&1)==1)
			pf("Louise\n");
		else
			pf("Richard\n");
	}
	return 0;
}
