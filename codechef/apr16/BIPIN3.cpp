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

ll md=1000000007;

ll pow(ll a, ll b) {
	var(ll);
	if(b==0) return 1;
	tmp=pow(a,b/2);
	if(b%2) return (((tmp*tmp)%md)*a)%md;
	else return (tmp*tmp)%md;
}

int main() {
	var(ll);
	ll K;
	sc("%lld",&T);
	while(T--) {
		sc("%lld %lld",&N,&K);
		tmp=0;
		tmp=K;
		tmp=(tmp*(pow(K-1,N-1)))%md;
		pf("%lld\n",tmp);
	}
	return 0;
}