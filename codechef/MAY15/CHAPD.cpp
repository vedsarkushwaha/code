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

ll gcd(ll a, ll b) {
  while (b != 0)  {
    ll t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main() {
	var(ll);
	ll A,B;
	sc("%lld",&T);
	while(T--) {
		tmp5=0;
		sc("%lld %lld",&A,&B);
		tmp=A;
		if(B==1 || A%B==0) pf("Yes\n");
		else if(A==1) pf("No\n");
		else {
			while(1) {
				tmp=gcd(A,B);	
				if(tmp==1) {
					pf("No\n");
					tmp5=1;
					break;
				}
				B=B/tmp;
				if(A%B==0 || B==1) {
					pf("Yes\n");
					break;
				}
			}
		}
	}
	return 0;
}