#include <cstdio>

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
	ll M;
	var(ll);
	sc("%lld",&T);
	while(T--) {
		sc("%lld %lld",&N,&M);
		if((N==1 && M==2) || (M==1 && N==2)) {
			pf("Yes\n");
		}
		else if(N==1 || M==1) {
			pf("No\n");
		}
		else if(M==3 && N==3) {
			pf("No\n");
		}
		else if(N%2 && M%2) {
			pf("No\n");
		}
		else {
			pf("Yes\n");
		}
	}
	return 0;
}