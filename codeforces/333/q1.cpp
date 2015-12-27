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
	ll n,m,nb,mb;
	vl a,b;
	cin>>n>>nb;
	fr(i,0,n) {
		cin>>tmp;
		// a.pb(tmp);
		tmp1+=(pow(nb,n-i-1)*tmp);
	}
	cin>>m>>mb;
	fr(i,0,m) {
		cin>>tmp;
		// b.pb(tmp);
		tmp2+=(pow(mb,m-i-1)*tmp);
	}
	// cout<<tmp1<<" "<<tmp2<<endl;
	if(tmp1==tmp2) pf("=");
	else if(tmp1<tmp2) pf("<");
	else pf(">");
	return 0;
}
