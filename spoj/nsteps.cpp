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
unsigned ll gcd(unsigned ll a, unsigned ll b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}
int main() {
	var(int);
	int T,x,y;
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&x,&y);
		if(x==y) {
			if(x%2==0)
				pf("%d\n",2*x);
			else
				pf("%d\n",2*x-1);
		}
		else if(x==y+2) {
			if(x%2==0)
				pf("%d\n",2*x-2);
			else
				pf("%d\n",2*x-3);
		}
		else
			pf("No Number\n");
	}
	return 0;
}