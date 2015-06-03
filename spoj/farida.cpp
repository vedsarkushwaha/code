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
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll unsigned long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0

using namespace std;
int main() {
	var(ll);
	ll T,N,ele;
	vector<ll> dp;
	sc("%llu",&T);
	fr(i,1,T+1) {
		dp.push_back(0);
		sc("%llu",&N);
		fr(j,1,N+1) {
			sc("%llu",&tmp);
			if(j==1)
				dp.push_back(tmp);
			else {
				dp.push_back(max(dp.at(j-1),dp.at(j-2)+tmp));
			}
		}
		pf("Case %llu: %llu\n",i,dp.at(N));
		dp.clear();
	}
	return 0;
}
