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
ll fun(ll x,ll y,ll h,ll m) {return (x*h+y)%m;}
int main() {
	var(ll);
	ll m,h1,a1,h2,a2,x2,y2,x1,y1;
	sc("%lld",&m);
	sc("%lld %lld",&h1,&a1);
	sc("%lld %lld",&x1,&y1);
	sc("%lld %lld",&h2,&a2);
	sc("%lld %lld",&x2,&y2);
	// Xanier
	int flag=0;
	fr(i,0,p) {
		h1=fun(x1,y1,h1,m);
		h2=fun(x2,y2,h2,m);
		if(h1==a1) {
			if(h2==a2) {
				pf("%lld",i);
				return 0;
			}
			else {
				flag=1;
				break;
			}
		}
	}
	tmp5=i;
	if(!flag) {
		pf("-1");
		return 0;
	}
	flag=0;
	fr(i,0,p) {
		h1=fun(x1,y1,h1,m);
		if(h1==a1) {
			flag=1;
			break;
		}
	}
	if(!flag) {
		pf("-1");
		return 0;
	}
	tmp4=i;
	fr(i,0,p) {

	}
	return 0;
}