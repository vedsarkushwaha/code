#include <cstdio>
#include <vector>
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
	var(int);
	int N;
	sc("%d",&N);
	vi vec;
	fr(i,0,N) {
		sc("%d",&tmp);
		while(tmp%2==0) {tmp=tmp/2;}
		while(tmp%3==0) {tmp=tmp/3;}
		vec.pb(tmp);
	}
	fr(i,0,N-1) {
		if(vec[i]!=vec[i+1]) {
			pf("No");
			return 0;
		}
	}
	pf("Yes");
	return 0;
}
