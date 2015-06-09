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

int main() {
	var(ll);
	ll m,n;
	sc("%lld %lld %lld",&n,&m,&k);
	if(n<m) swap(n,m);
	assert(k<=n*m);
	ll low,mid,high;
	low=1,high=m;
	while(low<=high) {
		mid=(low+high)/2;
		if(k<=mid*n && k>(mid-1)*n) {
			break;
		}
		else if(k>mid*n) low=mid+1;
		else high=mid-1;
	}
	fr(i,1,n+1) {
		
	}
	return 0;
}
