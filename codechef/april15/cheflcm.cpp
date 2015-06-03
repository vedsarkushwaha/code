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
#define sz 100000
using namespace std;
ll power(ll x,ll y) {
	ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}

int prm[sz+1];

void seive_fun() {
	int i,j,k,limit;
	prm[0]=1;
	prm[1]=1;
	limit=sqrt(sz);
	for(i=2;i<=limit;i++) {
		if(prm[i]==0) {
			k=sz/i;
			for(j=2;j<=k;j++)
				prm[i*j]=1;
		}
	}
}
int main() {
	var(ll);
	vl prime;
	seive_fun();
	fr(i,0,sz+1) {
		if(prm[i]==0)
			prime.pb(i);
	}
	sc("%lld",&T);
	while(T--) {
		sc("%lld",&N);
		vll fact;
		i=0;
		while(prime[i]<=sqrt(N)) {
			tmp5=0;
			while(N%prime[i]==0) {
				tmp5++;
				N=N/prime[i];
			}
			fact.pb(make_pair(prime[i],tmp5));
			i++;
		}
		if(N!=1) {
			fact.pb(make_pair(N,1));
		}
		tmp1=1;
		fr(i,0,fact.size()) {
			tmp=0;
			fr(j,0,fact[i].second+1) {
				tmp+=power(fact[i].first,j);
			}
			tmp1*=tmp;
			//pf("%lld %lld\n",fact[i].first,fact[i].second);
			//tmp5+=fact[i];
		}
		pf("%lld\n",tmp1);
	}
	return 0;
}