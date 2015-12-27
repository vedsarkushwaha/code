#include <cstdio>
#include <vector>
#include <algorithm>

#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
using namespace std;

bool comp(int a, int b) {
	return a>b;
}
int main() {
	var(int);
	int n,m;
	sc("%d %d",&n,&m);
	vector<int> vec;
	fr(i,0,n) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	sort(vec.begin(),vec.end(),comp);
	fr(i,0,n) {
		tmp5+=vec[i];
		if(tmp5>=m) break;
	}
	pf("%d",i+1);
	return 0;
}
