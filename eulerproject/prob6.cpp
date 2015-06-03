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

int main() {
	ull N,sum1,sum2;
	int T;
	sc("%d",&T);
	while(T--) {
		sc("%llu",&N);
		sum1=pow((N*(N+1))/2,2);
		sum2=(N*(N+1)*(2*N+1))/6;
		pf("%llu\n",sum1-sum2);
	}
	return 0;
}
