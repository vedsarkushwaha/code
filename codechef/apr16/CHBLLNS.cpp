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
	var(ll);
	int R,G,B,K;
	sc("%lld",&T);
	while(T--) {
		sc("%d %d %d",&R,&G,&B);
		sc("%d",&K);
		K--;
		tmp=0;
		if(K<R) tmp+=K;
		else tmp+=R;
		if(K<G) tmp+=K;
		else tmp+=G;
		if(K<B) tmp+=K;
		else tmp+=B;
		pf("%lld\n",tmp+1);
	}
	return 0;
}