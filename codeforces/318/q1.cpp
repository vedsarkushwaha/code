#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
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

int main() {
	int N;
	var(int);
	sc("%d",&N);
	vi vec;
	vi::iterator it;
	fr(i,0,N) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	while(max_element(vec.begin(),vec.end())-vec.begin()!=0) {
		it=max_element(vec.begin(),vec.end());
		// tmp=vec[0]+(*it)+1;
		// tmp=tmp/2;
		// tmp5+=(tmp-vec[0]);
		// *it = (*it)-tmp5;
		// vec[0]+=tmp5;
		tmp5++;
		vec[0]++;
		(*it)--;
	}
	fr(i,1,N) {
		assert(vec[0]>=vec[i]);
		if(vec[0]==vec[i]) {
			tmp5++;
			break;
		}
	}
	pf("%d",tmp5);
	return 0;
}
