#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	var(ll);
	sc("%lld",&T);
	while(T--) {
		sc("%lld %lld",&tmp1,&tmp2);
		vi time,value;
		fr(i,0,tmp1) {
			sc("%lld",&tmp3);
			time.pb(tmp3);
		}
		fr(i,0,tmp1) {
			sc("%lld",&tmp3);
			value.pb(tmp3);
		}
		tmp5=0;
		fr(i,0,tmp1) {
			tmp5=max(tmp5,(tmp2/time[i])*value[i]);
		}
		pf("%lld\n",tmp5);
	}
	return 0;
}