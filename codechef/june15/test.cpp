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

pair<ll,pair<ll,ll> > egcd(ll a, ll b) {
	if(a==0) return make_pair(b,make_pair(0LL,1LL));
	else {
		pair<ll,pair<ll,ll> > temp;
		temp=egcd(b%a,a);
		ll g=temp.first;
		ll y=temp.second.first;
		ll x=temp.second.second;
		return make_pair(g,make_pair(x-(b/a)*y,y));
	}
}
ll modinv(ll a,ll m) {
	pair<ll,pair<ll,ll> > temp;
	temp=egcd(a,m);
	ll g=temp.first;
	ll x=temp.second.first;
	ll y=temp.second.second;
	pf("%lld %lld %lld\n",g,x,y);
	if(g!=1) return INT_MIN;
	else return (x+m)%m;
}

int main() {
	var(ll);
	sc("%lld",&T);
	while(T--) {
		sc("%lld %lld",&tmp,&tmp1);
		pf("%lld\n",modinv(tmp,tmp1));
	}
	return 0;
}