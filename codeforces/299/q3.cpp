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
	ll A,B,n;
	sc("%lld %lld %lld",&A,&B,&n);
	fr(i,0,n) {
		ll l,t,m;
		sc("%lld %lld %lld",&l,&t,&m);
		ll sm=0,ns=0,nx=0,ny=0;
		ns=A+(l-1)*B;
		nx=(t-A)/B + 1;
		ll D=sqrt((2*ns-B)*(2*ns-B)+8*B*m*t);
		ll tmp=B-2*ns;
		ny=(tmp+D)/(2*B);
		// pf("%lld\n",ny);
		sm=(ny*(2*ns+(ny-1)*B))/2;
		ny++;
		ll sm1=sm=(ny*(2*ns+(ny-1)*B))/2;
		if(sm1<=m*t)
			sm=sm1;
		else
			ny--;
		// while(sm<=m*t) {
		// 	ny++;
		// 	sm=(ny*(2*ns+(ny-1)*B))/2;
		// 	// pf("sum=%lld\n",sm);
		// }
		if(min(nx,(l+ny-1))<l)
			pf("-1\n");
		else
			pf("%lld\n",min(nx,(l+ny-1)));
	}
	return 0;
}
