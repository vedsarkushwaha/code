#include <cstdio>
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
	pf("1\n");
	pf("2 1 2\n");
	pf("2 3 4\n");
	fflush(stdout);
	sc("%d",&tmp);
	if(tmp==0) {
		pf("2\n");
		pf("5");
		fflush(stdout);
	}
	else if(tmp==-1) {
		pf("1\n");
		pf("1 3\n");
		pf("1 4\n");
		fflush(stdout);
		sc("%d",&tmp);
		if(tmp==-1) {
			pf("2\n");
			pf("4\n");
			fflush(stdout);
		}
		else if(tmp==1) {
			pf("2\n");
			pf("3\n");
			fflush(stdout);
		}
		else assert(1==0);
	}
	else if(tmp==1) {
		pf("1\n");
		pf("1 1\n");
		pf("1 2\n");
		fflush(stdout);
		sc("%d",&tmp);
		if(tmp==-1) {
			pf("2\n");
			pf("2\n");
			fflush(stdout);
		}
		else if(tmp==1) {
			pf("2\n");
			pf("1\n");
			fflush(stdout);
		}
		else assert(1==0);
	}
	else assert(1==0);
	return 0;
}
