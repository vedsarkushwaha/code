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
	ll n,m,a;
	sc("%lld %lld %lld",&n,&m,&a);
	tmp1=0,tmp2=0;
	if(n%a)
		tmp1=(n/a)+1;
	else
		tmp1=n/a;
	if(m%a)
		tmp2=(m/a)+1;
	else
		tmp2=m/a;
	printf("%lld",tmp1*tmp2);
	return 0;
}
