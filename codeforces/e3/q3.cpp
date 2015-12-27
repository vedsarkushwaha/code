#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
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
	var(int);
	int n;
	sc("%d",&n);
	vi vec;
	fr(i,0,n) {
		sc("%d",&tmp);
		vec.pb(tmp);
		tmp5+=tmp;
	}
	sort(vec.begin(),vec.end());
	tmp4=tmp5/n;
	fr(i,0,n) {
		if(vec[i]>=tmp4) break;
		tmp3+=(tmp4-vec[i]);
		vec[i]=tmp4;
	}
	if(n-i < (tmp5%n)) tmp3++;
	pf("%d",tmp3);
	return 0;
}
