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
ll md=1000000007;
int main() {
	var(ll);
	sc("%lld",&T);
	while(T--) {
		sc("%lld",&N);
		vl vec;
		fr(i,0,N) {
			sc("%lld",&tmp);
			vec.pb(tmp);
		}
		sort(vec.begin(),vec.end());
		// fr(i,0,N)
		// 	pf("%lld ",vec[i]);
		// pf("\n");
		ll cnt=0,ans=1,cnt1=0;
		j=0;
		while(cnt1<N) {
			while(j<N && vec[j]<=cnt1) {
				j++;
			}
			ans=(ans*(j-cnt1))%md;
			cnt+=(j-cnt1);
			// pf("%lld\t%lld\t%lld\t%lld\n",ans,cnt,j,cnt1);
			cnt1++;
		}
		pf("%lld\n",ans);
	}
	return 0;
}