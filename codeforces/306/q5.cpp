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
vector<char> opt;
bool chk(vi &vec,int r,int val) {
	var(int);
	if(!r) {
		if(vec[r]==val)
			return 1;
		else
			return 0;
	}
	if(!val) {
		if(vec[r]!=0)
			return 0;
		else {
			opt.pb('0'+vec[r]);
			opt.pb('>');
			opt.pb('-');
			opt.pb(')');
			return chk(vec,r-1,1);
		}
	}
	else {
		if(vec[r]==1)
			return 1;
		else {
			opt.pb('0'+vec[r]);
			opt.pb('>');
			opt.pb('-');
			opt.pb(')');
			return chk(vec,r-1,0);
		}
	}
}
int main() {
	var(int);
	sc("%d",&N);
	vi vec;
	fr(i,0,N) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	if(!chk(vec,N-1,0))
		pf("NO");
	else {

	}
	return 0;
}
