#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
unsigned ll power(unsigned ll x,unsigned ll y) {
	unsigned ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
ll gcd(ll a,ll b) {
  while (b != 0)  {
    ll t = b;
    b = a % b;
    a = t;
  }
  return a;
}
int main() {
	var(ll);
	ll l,r;
	cin>>l>>r;
	fr(i,l,r+1) {
		fr(j,i+1,r+1) {
			fr(k,j+1,r+1) {
				//cout<<gcd(i,j)<<' '<<gcd(j,k)<<' '<<gcd(k,l)<<endl;
				if((gcd(i,j)==gcd(j,k)) && (gcd(j,k)==1)&& (gcd(i,k)!=1)) {
					cout<<i<<' '<<j<<' '<<k<<endl;
					return 0;
				}
			}
		}
	}
	pf("-1");
	return 0;
}
