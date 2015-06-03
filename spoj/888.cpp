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
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T
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
unsigned ll gcd(unsigned ll a, unsigned ll b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}
ll dig(int n) {
	var(ll);
	tmp=0;
	while(n!=0) {
		tmp++;
		n=n/10;
	}
	return tmp;
}
int chk(ll n) {
	var(ll);
	tmp=n*n*n;
	if(tmp%1000==888)
		return 1;
	else 
		return 0;
}
int main() {
	var(ll);
	//sc("%d",&T);
	tmp=192;
	fr(i,193,100000) {
		if(chk(i)==1) {
			if(i-tmp1!=250) {
				pf("%lld %lld\n",dig(i),i-tmp1);
			}
			//if(i-tmp1==2)
			//	pf("%lld %lld\n",i,tmp1);
			tmp1=i;
			//pf("%lld ",i);
		}
	}
	return 0;
}
