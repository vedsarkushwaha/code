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
ll md=1000003;
ll power(ll x,ll y) {
	ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%md;
	else
		return (x*temp*temp)%md;
}
ll nCk(ll n,ll k ) {
	if (k > n) return 0;
	if (k * 2 > n) k = n-k;
	if (k == 0) return 1;

	ll result = n;
	ll result1 = 1;
	for(ll i = 2; i <= k; ++i ) {
		result = (result*(n-i+1))%md;
		result1 = (result1*i)%md;
	}
	result1=power(result1,md-2);
	return (result*result1)%md;
}

main() {
	var(ll);
	ll L,R;
	sc("%lld",&T);
	while(T--) {
		sc("%lld %lld %lld",&N,&L,&R);
		tmp5=0;
		fr(i,1,N+1)
			tmp5=(tmp5+nCk(R-L+i,i))%md;
		assert(tmp5>=0);
		pf("%lld\n",tmp5);
	}
	return 0;
}