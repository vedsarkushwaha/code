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
ll md=1000000007;
using namespace std;
unsigned ll power(unsigned ll x,unsigned ll y) {
	unsigned ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%md;
	else
		return (x*temp*temp)%md;
}
void print(vl vec) {
	var(ll);
	pf("\n");
	fr(i,0,vec.size()) pf("%lld ",vec[i]);
	pf("\n");
}
main() {
	var(ll);
	sc("%lld",&T);
	while(T--) {
		sc("%lld",&N);
		vl vec;
		vl sm;
		fr(i,0,N) {
			sc("%lld",&tmp);
			vec.pb(tmp);
		}
		sort(vec.begin(),vec.end());
		// print(vec);
		vl smBack,smFront;
		fr(i,0,N-1) {
			// printf("i=%lld\n",i);
			if(i==0) {
				smFront.pb(vec[0]);
				smBack.pb(vec[N-1-i]);	
			}
			else {
				smFront.pb(smFront[i-1]+vec[i]);
				// pf("%lld %lld\n",vec[i-1],vec[i]);
				smBack.pb(smBack[i-1]+vec[N-1-i]);
			}
		}
		reverse(smFront.begin(),smFront.end());
		reverse(smBack.begin(),smBack.end());
		// print(smBack);
		// print(smFront);
		ll ans=0;
		fr(i,0,N-1) {
			tmp=(smBack[i]-smFront[i])%md;
			tmp=(tmp*power(2,i))%md;
			ans+=tmp;
			ans=ans%md;
		}
		pf("%lld\n",ans);
	}
}