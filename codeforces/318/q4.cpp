#include <bits/stdc++.h>
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
	var(int);
	int n;
	vi vec;
	sc("%d",&n);
	fr(i,0,n) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	vi lft,rgt;
	lft.pb(1);
	fr(i,1,n) {
		lft.pb(min(vec[i],lft.back()+1));
	}

	reverse(vec.begin(),vec.end());
	rgt.pb(1);
	fr(i,1,n) {
		rgt.pb(min(vec[i],rgt.back()+1));
	}
	
	reverse(rgt.begin(),rgt.end());
	// fr(i,0,n) pf("%d ",rgt[i]);
	// pf("\n");
	// fr(i,0,n) pf("%d ",lft[i]);
	tmp=0;
	// pf("%d %d %d\n",lft.size(),rgt.size(),vec.size());
	fr(i,0,n) {
		// fflush(stdout);
		tmp=max(tmp,min(lft[i],rgt[i]));
		// pf("%d %d %d\n",tmp,lft[i],rgt[i]);
	}
	pf("%d",tmp);
	return 0;
}
