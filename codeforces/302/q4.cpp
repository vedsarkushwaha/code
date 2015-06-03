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
ll md=1000000007;
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
int main() {
	var(ll);
	char s[1000010];
	fr(i,0,1000010) {
		s[i]='E';
	}
	ll n,m;
	string p;
	sc("%lld %lld",&n,&m);
	cin>>p;
	fr(i,0,m) {
		sc("%lld",&k);
		fr(j,k,k+p.length()) {
			if(s[j]=='E' || s[j]==p[j-k])
				s[j]=p[j-k];
			else {
				pf("0");
				return 0;
			}
		}
	}
	tmp=0;
	fr(i,0,n) {
		if(s[i]=='E')
			tmp++;
	}
	tmp1=26;
	pf("%lld",power(tmp1,tmp));
	return 0;
}