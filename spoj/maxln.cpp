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
#define var(x) x tmp1=0,tmp2=0,tmp3=0,tmp=0
#define con int T,N,i=0,j=0,k=0
using namespace std;
int main() {
	var(double);
	con;
	sc("%d",&T);
	fr(i,1,T+1) {
		sc("%lf",&tmp);
		pf("Case %d: %.2lf\n",i,4*tmp*tmp+0.25);
	}
	return 0;
}
