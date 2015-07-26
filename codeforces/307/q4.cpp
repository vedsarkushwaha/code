#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

ll power(ll x,ll y,ll md) {
	ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2,md);
	if (y%2 == 0)
		return (temp*temp)%md;
	else
		return (x*temp*temp)%md;
}

int main() {
	var(ll);
	ll n,k,l,m;
	sc("%lld %lld %lld %lld",&n,&k,&l,&m);
	if(k>=(1<<l)) {
		pf("0\n");
		return 0;
	}
	ll sm=1;
	fr(i,0,l) {
		if(k&(1<<i)) {
			tmp=(power(2,n-1,m) + m -1)%m;
		}
		else {
			tmp=(power(2,n,m)+m - power(2,n-1,m) + 1)%m;
		}
		sm=(sm*tmp)%m;
	}
	pf("%lld\n",sm);
	return 0;
}