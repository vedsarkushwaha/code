#include<bits/stdc++.h>
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

int main() {
	var(ll);
	int T,N;
	sc("%d",&T);
	while(T--) {
		sc("%d",&N);
		ll sm=0;
		tmp5=1;
		flag=0;
		sc("%lld",&tmp);
		fr(i,1,N) {
			sc("%lld",&tmp1);
			if(tmp<=tmp1) {
				tmp5++;
			}
			else {
				sm+=(tmp5*(tmp5+1))/2;
				tmp5=1;
			}
			tmp=tmp1;
		}
		sm+=(tmp5*(tmp5+1))/2;
		pf("%lld\n",sm);
	}
	return 0;
}