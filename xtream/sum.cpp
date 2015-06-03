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
#include<climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll unsigned long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
#define mod 1000000007
using namespace std;
int main() {
	var(ll);
	ll N,Q;
	sc("%llu",&N);
	tmp3=0;
	while(N--) {
		sc("%llu",&tmp);
		tmp3+=tmp;
	}
	tmp3=tmp3%mod;
	sc("%llu",&Q);
	while(Q--) {
		sc("%llu",&tmp);
		tmp3=tmp3*2;
		tmp3=tmp3%mod;
	}
	pf("%llu\n",tmp3);
	return 0;
}
