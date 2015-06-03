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
#define sz 10000
using namespace std;
int prm[sz+1];
ll gcd(ll a, ll b) {
  while (b != 0)  {
    ll t = b;
    b = a % b;
    a = t;
  }
  return a;
}
void seive_fun() {
	ll i,j,k,limit;
	prm[0]=1;
	prm[1]=1;
	limit=sqrt(sz);
	for(i=2;i<=limit;i++) {
		if(prm[i]==0) {
			k=sz/i;
			for(j=2;j<=k;j++)
				prm[i*j]=1;
		}
	}
}
int main() {
	var(ll);
	seive_fun();
	sc("%lld",&T);
	while(T--) {
		sc("%lld %lld",&tmp1,&tmp2);
		tmp=gcd(tmp1,tmp2);
		tmp1=sqrt(tmp);
		tmp5=1;
		fr(i,2,tmp1+1) {
			tmp3=0;
			if(!prm[i]) {
				while(tmp%i==0) {
					tmp/=i;
					tmp3++;
				}
			}
			tmp5*=(tmp3+1);
		}
		if(tmp!=1)
			tmp5*=2;
		pf("%lld\n",tmp5);
	}
	return 0;
}