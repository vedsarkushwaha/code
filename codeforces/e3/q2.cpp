#include <cstdio>

#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
using namespace std;

int main() {
	var(ll);
	ll n,m;
	sc("%lld %lld",&n,&m);
	int g[10]={0};
	fr(i,0,n) {
		sc("%lld",&tmp);
		g[tmp-1]+=1;
	}

	fr(i,0,m-1) {
		fr(j,i+1,m) {
			tmp5+=(g[i]*g[j]);
		}
	}
	pf("%lld",tmp5);
	return 0;
}