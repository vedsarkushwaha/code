#include <cstdio>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

ll triangle(ll n) {
	return (n*(n+1))/2;
}

ll square(ll n) {
	return n*n;
}

ll pentagonal(ll n) {
	return (n*(3*n-1))/2;
}

ll hexagonal(ll n) {
	return (n*(2*n-1));
}

ll heptagonal(ll n) {
	return (n*(5*n-3))/2;
}

ll octagonal(ll n) {
	return n*(3*n-2);
}

int main() {
	var(ll);
	fr(i,33,1000) {
		pf("%lld ",triangle(i));
	}
	return 0;
}