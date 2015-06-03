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
#include<utility>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
map<ll,ll> mp;
ll solve(ll N) {
	var(ll);
	map<ll,ll>::iterator it;
	if(N<5)
		return N;
	else if((it=mp.find(N))!=mp.end())
		return it->second;
	else {
		tmp=max(N,solve(N/2)+solve(N/3)+solve(N/4));
		//pf("%lld %lld\n",N,tmp);
		mp.insert(make_pair(N,tmp));
		return tmp;
	}
}
int main() {
	var(ll);
	ll N;
	mp.insert(make_pair(1,1));
	mp.insert(make_pair(2,2));
	mp.insert(make_pair(3,3));
	mp.insert(make_pair(4,4));
	while(sc("%lld",&N)!=EOF) {
		pf("%lld\n",solve(N));
	}
	return 0;
}
