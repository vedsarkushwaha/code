#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int md=1000000007;

ll npr(ll n, ll r) {
	var(ll);
	tmp = 1;
	fr(i,1,n+1) {
		tmp=(tmp*i);
	}
	fr(i,1,n-r+1) {
		tmp=tmp/i;
	}
	return tmp%md;
}

ll ncr(ll n, ll r) {
	var(ll);
	tmp = 1;
	fr(i,1,n+1) {
		tmp=(tmp*i);
	}
	fr(i,1,r+1) {
		tmp=tmp/i;
	}

	fr(i,1,n-r+1) {
		tmp=tmp/i;
	}
	return tmp%md;
}

ll getPrimeCount(ll limit) {
	var(ll);
	int cnt=0;
	fr(tmp,2,limit+1) {
		int flag=0;
		fr(i,2,tmp/2+1) {
			if(tmp%i==0) {
				flag=1;
				break;
			}
		}
		if(!flag) cnt++;
	}
	return cnt;
}

int main() {
	var(ll);
	ll T,N,M;
	sc("%lld",&T);
	while(T--) {
		sc("%lld %lld",&N,&M);
		tmp = min(100LL,M);
		ll primeCount=getPrimeCount(tmp);
		// pf("Total Prime Numbers: %lld\n",primeCount);
		ll ans=1;
		tmp=min(primeCount, N);
		fr(i,1,tmp+1) {
			ans+=((ncr(primeCount,i) * npr(N,i))%md);
			ans=ans%md;
		}
		pf("%lld\n",ans);
	}
	return 0;
}