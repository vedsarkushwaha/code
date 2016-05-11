#include <cstdio>
#include <vector>
#include <cassert>
 
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll unsigned long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,flag=0,T=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
 
vll trees;
 
long long getWood(ll month,ll L, ll W) {
	var(ll);
	tmp=0;
	fr(i,0,trees.size()) {
		if((trees[i].first + trees[i].second*month) >= L) {
			tmp+=(trees[i].first + trees[i].second*month);
			if(tmp>W) return 1;
			// pf("%lld:%lld:%lld\n",i,month,trees[i].first + trees[i].second*month);
		}
	}
	assert(tmp<=W && tmp>=0);
	if(tmp==W) return 0;
	else return -1;
}
 
int main() {
	var(ll);
	ll N,W,L;
	long long tmp5;
	sc("%llu %llu %llu",&N,&W,&L);
	fr(i,0,N) {
		sc("%llu %llu",&tmp1,&tmp2);
		trees.pb(make_pair(tmp1,tmp2));
	}
	ll low=0;
	ll high=max(W/N+1,1000000000);
 
	ll mid;
	ll prevAns=high;

	assert(getWood(high,L,W)>=0);
	//binary search
	while(high>=low) {
		mid=(high+low)/2;
		tmp5 = getWood(mid,L,W);
		// pf("%lld %lld %lld %lld %lld\n",low,mid,high,W,tmp5);
		if(0==tmp5) {
			pf("%lld",mid);
			return 0;
		}
		else if(low==mid) break;
		else if(tmp5>0) {
			prevAns=mid;
			assert(getWood(prevAns,L,W)>0);
			high=mid;
		}
		else if(tmp5<0) {
			low=mid;
		}
	}
	if(getWood(mid,L,W)>=0) pf("%lld",mid);
	else {
		// assert(mid+1==prevAns);
		mid++;
		while(getWood(mid,L,W)<0) {
			mid++;
			// assert(mid<=prevAns);
		}
		pf("%lld",mid);
	}
	// iterative search
	// low=0;
	// high=1000000000;
	// pf("-");
	// fr(mid,low,high+1) {
	// 	tmp5 = getWood(mid,L,W);
	// 	if(tmp5>=0) break;
	// }
	// pf("%lld",mid);
	return 0;
}