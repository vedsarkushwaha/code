#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
vll vec[200010];
vl nd;
int maxi(int l) {
	var(ll);
	if(vec[l].size()==0)
		return 1;
	fr(i,0,vec[l].size()) {
		j=vec[l][i];
		//tmp5=0;
		fr(k,0,vec[j].size()) {
			tmp5+=maxi(vec[j][k]);
		}
	}
	fr(i,0,vec[l].size()) {
		tmp4+=maxi(vec[l][i]);
	}
	if(tmp5+1>tmp4) {
		nd[l]=1;
	return 0;	
}
int main() {
	var(ll);
	sc("%lld",&T);
	fr(i,1,T+1) {
		sc("%lld",&N);
		nd.clear();
		nd.resize(200010,0);
		fr(k,0,N+1)
			vec[k].clear();
		if(N==1) {
			pf("Case #%lld: %lld\n",i,N);
			continue;
		}
		sc("%lld",&tmp);
		fr(j,2,N+1) {
			sc("%lld",&tmp);
			vec[tmp].pb(make_pair(j,0));
		}
		//sort(inp.begin(),inp.end());
		/*fr(j,1,N+1) {
			fr(k,0,vec[j].size()) {
				pf("%lld ",vec[j][k]);
			}
			pf("\n");
		}*/
		k=1;
		tmp5=0;
		while(tmp=maxi(1)) {
			tmp5+=tmp;
		}
		pf("Case #%lld: %lld\n",i,tmp5);
	}
	return 0;
}
