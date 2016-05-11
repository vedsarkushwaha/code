#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0

using namespace std;

double getDist(int x, int y, int px, int py) {
	return sqrt((x-px)*(x-px) + (y-py)*(y-py));
}

int main() {
	var(ll);
	ll n,px,py,x,y;
	double minDist=INT_MAX,maxDist=INT_MIN;
	sc("%lld %lld %lld",&n,&px,&py);
	fr(i,0,n) {
		sc("%lld %lld",&x,&y);
		minDist=min(getDist(x,y,px,py),minDist);
		maxDist=max(getDist(x,y,px,py),maxDist);
	}
	pf("%.9lf",M_PI*(maxDist-minDist)*(maxDist+minDist));
	return 0;
}